#include "musicwidget.h"
#include "ui_musicwidget.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include<QTextCodec>


MusicWidget::MusicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicWidget)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());

    musicListCounter = 0;  //播放器各参数初始化
    musicLrcLineCounter = 0;

    musicVolume_now = musicVolume_last = 50;    //音量设为50
    player.setVolume(50);
    ui->slider_volume->setValue(50);

    playFlag = 0;   //playflag用于缓冲
    musicPositionChangeFlag = false;    //各标志位初始化
    musicStartFlag = false;
    voiceOpenFlag = true;

    ui->bt_StartPause->setIcon(QIcon("images/bfzn_004.png" ));  //设置各按钮图标
    ui->bt_StartPause->setFixedSize(40, 40);
    ui->bt_voice->setIcon(QIcon("images/voice_open.png" ));
    ui->bt_voice->setFixedSize(16, 16);

    connect(&player, &QMediaPlayer::positionChanged, this, &MusicWidget::musicPositionChange);  //连接起进度条

    setWindowFlags(Qt::FramelessWindowHint);

    QPixmap pixmap = QPixmap("images/start.jpg").scaled(this->size());  //初始化背景、各窗口
    QPalette  palette (this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
    this->ui->lw_list->setStyleSheet(QString("color:rgba(255,255,255,255);background-color:rgba(10,10,10,150)"));
    this->ui->lw_lrc->setStyleSheet(QString("color:rgba(255,255,255,255);background-color:rgba(10,10,10,200)"));

    QTextCodec *codec =QTextCodec::codecForName("GBK");     //从文件中取出播放列表，列表中歌曲数
    QFile File2("List/2.txt");
     if (!File2.open(QIODevice::ReadOnly | QIODevice::Text))
         return;
    QTextStream in(&File2);
     QString line = in.readLine();
     File2.close();
     musicListCounter = line.toInt();
     QFile File("List/1.txt");
      if (File.open(QFile::ReadOnly|QIODevice::Text))
      {  while(!File.atEnd()) {
              static int L=0;
              QByteArray line = File.readLine();
              QString str= codec->toUnicode(line);
              str=str.replace("\n","");
              ui->lw_list->addItem( str);
              QString str1 = "C:/Qtprogram/MusicPlayer/music/";
              QString str2 = str;
              str1.append(str2);
              QString str3 = ".mp3";
              str1.append(str3);
              musicList[L]=str1;
              L++;
          }
      }
      File.close();
 }


MusicWidget::~MusicWidget()
{
    delete ui;
}

void MusicWidget::on_bt_close_clicked()     //关闭键
{
    this->close();
}

void MusicWidget::on_bt_min_clicked()       //最小化键
{
    this->showMinimized();
}

//鼠标三类事件
void MusicWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->buttons() == Qt::LeftButton)
        startRelativePos = e->pos();
}


void MusicWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(startRelativePos.y() < 40 && startRelativePos.x() < 1200)
    if (e->buttons() & Qt::LeftButton)
        move(e->globalPos() - startRelativePos);
}


void MusicWidget::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();
}

void MusicWidget::musicPositionChange(qint64 position)      //进度变化
{
        if(player.state() == QMediaPlayer::PlayingState)
        {
            playFlag++;
            if(playFlag >= 2)       //开始播放
            {
                ui->slider_musicTime->setValue(player.position()*100/player.duration());        //百分比计算进度条值
                musicPositionChangeFlag = true;
                QTime duration(0, player.position() / 60000, qRound((player.position() % 60000) / 1000.0), 0);      //显示总时长和已播时长
                ui->lb_musicTime->setText(duration.toString(tr("mm:ss")));
                QTime duration2(0, player.duration() / 60000, qRound((player.duration() % 60000) / 1000.0), 0);
                ui->lb_musicTime->setText(ui->lb_musicTime->text() );
                ui->lb_musicTime_2->setText( duration2.toString(tr("mm:ss")));

                if(duration == duration2)       //播放结束，换列表中下一首
                {
                    player.setMedia(QUrl::fromLocalFile(musicList[(ui->lw_list->currentIndex().row() + 1) % musicListCounter]));
                    ui->lw_list->setCurrentRow((ui->lw_list->currentIndex().row() + 1) % musicListCounter);
                    player.play();
                    currentMusicName = ui->lw_list->currentItem()->text();
                    setWindowBackgroundImage();

                }

                if(musicLrc[0].compare(currentMusicName) != 0)  //未载入过歌词
                {
                    QFile lrcFile("lrc/" + ui->lw_list->currentItem()->text() + ".txt");
                    ui->lw_lrc->clear();

                    if(lrcFile.open(QIODevice::ReadOnly))       //有相应歌词
                    {qDebug() << "lrc File Open Success";
                        QTextStream lrcFileStream(&lrcFile);

                        lrcFileStream.setCodec("UTF-8");
                        musicLrcLineCounter = 0;
                        musicLrc[musicLrcLineCounter++] = currentMusicName;
                        while (!lrcFileStream.atEnd())
                        {

                            QString line = lrcFile.readLine();
                            musicLrc[musicLrcLineCounter++] = line;
                        }
                        lrcFile.close();
                    }
                    else        //无歌词
                    {qDebug() << "lrc File Open Fail";
                        int currentMusicRow=0;
                        ui->lw_lrc->clear();
                        lrcAddLineCounter = 0;

                        for(int i=currentMusicRow-4; i<currentMusicRow+5; i++)
                        {
                            if(i == currentMusicRow)
                            {
                                ui->lw_lrc->addItem("当前歌曲无歌词");
                            }
                            else
                            {
                                ui->lw_lrc->addItem("");
                            }

                            lrcAddLineCounter++;

                            ui->lw_lrc->setCurrentRow(lrcAddLineCounter-1);
                            ui->lw_lrc->currentItem()->setTextAlignment(Qt::AlignCenter);

                            if(i == currentMusicRow)
                            {
                                QFont font;
                                font.setPointSize(18);

                                ui->lw_lrc->setCurrentRow(4);
                                ui->lw_lrc->currentItem()->setFont(font);
                                ui->lw_lrc->currentItem()->setTextAlignment(Qt::AlignCenter);
                                ui->lw_lrc->currentItem()->setTextColor(Qt::cyan);


                            }
                        }

                    }
                }
                else        //已经载入过本歌歌词
                {
                    int currentMusicRow=0;
                    for(currentMusicRow=0; currentMusicRow < musicLrcLineCounter; currentMusicRow++)
                    {
                        QString mm,ss;
                        mm = musicLrc[currentMusicRow].mid(1, 2);
                        ss = musicLrc[currentMusicRow].mid(4, 2);
                        QTime duration3(0, mm.toInt(), ss.toInt(), 0);
                        if(duration3 == duration)
                        {
                            break;
                        }
                    }
                    if(currentMusicRow < musicLrcLineCounter)
                    {
                        ui->lw_lrc->clear();
                        lrcAddLineCounter = 0;

                        for(int i=currentMusicRow-4; i<currentMusicRow+5; i++)
                        {

                            if(i >= 0 && i < musicLrcLineCounter)
                            {
                                QStringList lrc = musicLrc[i].split("]");
                                if(lrc.count() == 2)
                                    ui->lw_lrc->addItem(lrc.at(1));
                                else
                                    ui->lw_lrc->addItem(musicLrc[i]);

                                lrcAddLineCounter++;

                                ui->lw_lrc->setCurrentRow(lrcAddLineCounter-1);
                                ui->lw_lrc->currentItem()->setTextAlignment(Qt::AlignCenter);

                            }
                            else
                            {
                                ui->lw_lrc->addItem("");
                                lrcAddLineCounter++;

                                ui->lw_lrc->setCurrentRow(lrcAddLineCounter-1);
                                ui->lw_lrc->currentItem()->setTextAlignment(Qt::AlignCenter);

                            }
                            if(i == currentMusicRow)
                            {
                                QFont font;
                                font.setPointSize(18);

                                ui->lw_lrc->setCurrentRow(4);
                                ui->lw_lrc->currentItem()->setFont(font);
                                ui->lw_lrc->currentItem()->setTextAlignment(Qt::AlignCenter);
                                ui->lw_lrc->currentItem()->setTextColor(Qt::cyan);

                            }
                        }
                    }

                }
                ui->lw_lrc->setCurrentRow(-1);
            }

        }
        else
        {
            playFlag = 0;
        }
}


void MusicWidget::on_bt_add_clicked()       //添加音乐
{
    bool same = false;
    QStringList path = QFileDialog::getOpenFileNames(this, "添加音乐", "./music");
    for(int i=0; i<path.count(); i++)       //判断是否添加过
    {
        same = false;
        for(int j=0; j<musicListCounter; j++)
        {
            if(musicList[j].compare(path.at(i)) == 0)
            {
                same = true;
                break;
            }
        }
        if(same == false)       //无重复的加入播放列表，存入本地文件
        {
            musicList[musicListCounter++] = path.at(i);
            QFileInfo info(path.at(i));
            ui->lw_list->addItem(info.baseName());
               QString fileName = "List/1.txt";
               QFile file(fileName);
               if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))
               {
                    qDebug() << "open fail!" << endl;
               }
               QTextStream stream(&file);
                           stream << info.baseName() << "\n";
                       file.close();
        }
    }
    QString fileName = "List/2.txt";        //保存列表中音乐数
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly |QFile::Truncate))
    {
         qDebug() << "open fail!" << endl;
    }
    QTextStream stream(&file);
                stream << musicListCounter;
            file.close();

}

void MusicWidget::on_bt_del_clicked()       //删除键
{
    QString fileName = "List/1.txt";        //清空本地文档以重置
    QFile file(fileName);
    file.open(QFile::WriteOnly|QFile::Truncate);
    file.close();
    for(int i = ui->lw_list->currentIndex().row(); i < musicListCounter-1; i++)     //更新播放列表
    {
        musicList[i] = musicList[i+1];

    }

    musicListCounter--;
    for(int j = 0; j < musicListCounter; j++)       //存入本地文档
    {
              if(!file.open(QIODevice::WriteOnly  | QIODevice::Text|QIODevice::Append))
              {
                   qDebug() << "open fail!" << endl;
              }
              QTextStream stream(&file);
              QFileInfo info(musicList[j]);
              stream << info.baseName() << "\n";
          file.close();
    }

    QString fileName2 = "List/2.txt";       //保存列表中音乐数
    QFile file2(fileName2);
    if(!file2.open(QIODevice::WriteOnly |QFile::Truncate))
    {
         qDebug() << "open fail!" << endl;
    }
    QTextStream stream(&file2);
                stream << musicListCounter;
            file2.close();
    ui->lw_list->takeItem(ui->lw_list->currentIndex().row());
}


void MusicWidget::setWindowBackgroundImage()        //设置背景
{

    QPixmap pixmap = QPixmap("images/" + ui->lw_list->currentItem()->text() + ".jpg");
    if(pixmap.isNull() == false)
    {
        pixmap = pixmap.scaled(this->width(), this->height());
        QPalette  palette (this->palette());
        palette.setBrush(QPalette::Background, QBrush(pixmap));
        this-> setPalette( palette );
    }
    else
    {
        QPixmap pixmap = QPixmap("images/start.jpg");
        pixmap = pixmap.scaled(this->width(), this->height());
        QPalette  palette (this->palette());
        palette.setBrush(QPalette::Background, QBrush(pixmap));
        this-> setPalette( palette );
    }
}

void MusicWidget::on_slider_volume_valueChanged(int value)      //滑动改变音量
{
    player.setVolume(value);
    if(musicVolume_now != value)
    {
        musicVolume_last = musicVolume_now;
        musicVolume_now = value;
    }

    if(value == 0)
    {
        if(voiceOpenFlag == true)
        {
            ui->bt_voice->setIcon(QIcon("images/voice_close.png" ));
        }
        voiceOpenFlag = false;
    }
    else
    {
        if(voiceOpenFlag == false)
        {
            ui->bt_voice->setIcon(QIcon("images/voice_open.png" ));
        }
        voiceOpenFlag = true;
    }
}

void MusicWidget::on_slider_musicTime_valueChanged(int value)
{

    if(musicPositionChangeFlag == false)
    {
        if(musicStartFlag == true)
        {
            player.pause();
            player.setPosition(value*player.duration()/100);
            player.play();
            currentMusicName = ui->lw_list->currentItem()->text();
        }
        else
        {
            player.setPosition(value*player.duration()/100);
        }
    }
    else
    {
        musicPositionChangeFlag = false;
    }
}

void MusicWidget::on_bt_StartPause_clicked()        //播放、暂停按键
{
    if(!musicStartFlag)
    {
        ui->bt_StartPause->setIcon(QIcon("images/bfzn_003.png" ));
        musicStartFlag = true;
        if(player.state() == QMediaPlayer::StoppedState)
        {
            player.setMedia(QUrl::fromLocalFile(musicList[ui->lw_list->currentIndex().row()]));
            setWindowBackgroundImage();
        }
            player.play();
            currentMusicName = ui->lw_list->currentItem()->text();
    }
    else
    {
        ui->bt_StartPause->setIcon(QIcon("images/bfzn_004.png" ));
        musicStartFlag = false;
        player.pause();
    }

}

void MusicWidget::on_lw_list_doubleClicked(const QModelIndex &index)        //双击列表项播放
{
    player.setMedia(QUrl::fromLocalFile(musicList[ui->lw_list->currentIndex().row()]));
    player.play();
    currentMusicName = ui->lw_list->currentItem()->text();
    musicStartFlag = true;
    ui->bt_StartPause->setIcon(QIcon("images/bfzn_003.png" ));
    setWindowBackgroundImage();
}

void MusicWidget::on_bt_last_clicked()      //上一首
{
    if(ui->lw_list->currentIndex().row() - 1 >= 0)
    {
        player.setMedia(QUrl::fromLocalFile(musicList[(ui->lw_list->currentIndex().row() - 1)]));
        ui->lw_list->setCurrentRow((ui->lw_list->currentIndex().row() - 1) );
    }
    else
    {
        player.setMedia(QUrl::fromLocalFile(musicList[musicListCounter - 1]));
        ui->lw_list->setCurrentRow(musicListCounter - 1);
    }

    player.play();
    currentMusicName = ui->lw_list->currentItem()->text();
    if(musicStartFlag == false)
    {
        musicStartFlag = true;
        ui->bt_StartPause->setIcon(QIcon("images/bfzn_003.png" ));
    }
    setWindowBackgroundImage();

}

void MusicWidget::on_bt_next_clicked()      //下一首
{

    player.setMedia(QUrl::fromLocalFile(musicList[(ui->lw_list->currentIndex().row() + 1) % musicListCounter]));
    ui->lw_list->setCurrentRow((ui->lw_list->currentIndex().row() + 1) % musicListCounter);

    player.play();
    currentMusicName = ui->lw_list->currentItem()->text();
    if(musicStartFlag == false)
    {
        musicStartFlag = true;
        ui->bt_StartPause->setIcon(QIcon("images/bfzn_003.png" ));
    }
    setWindowBackgroundImage();
}

void MusicWidget::on_bt_voice_clicked()     //静音按钮
{

    if(voiceOpenFlag == false)
    {
        ui->bt_voice->setIcon(QIcon("images/voice_open.png" ));
        ui->slider_volume->setValue(musicVolume_last);
        voiceOpenFlag = true;
    }
    else
    {
        ui->slider_volume->setValue(0);
        ui->bt_voice->setIcon(QIcon("images/voice_close.png" ));
        voiceOpenFlag = false;
    }
}

