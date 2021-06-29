#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QMediaPlayer>
#include <QTime>
#include <QMouseEvent>
#include <QFont>
#include <QTextStream>
#include <QString>
#include <QListWidgetItem>
#include <QColor>

#define MUSICLIST_MAXLEN 200
#define MUSICLRC_MAXLEN 500

namespace Ui {
class MusicWidget;
}

class MusicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MusicWidget(QWidget *parent = 0);
    ~MusicWidget();

    void musicPositionChange(qint64 position);
    void setWindowBackgroundImage();

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private slots:


    void on_bt_add_clicked();

    void on_slider_volume_valueChanged(int value);

    void on_slider_musicTime_valueChanged(int value);

    void on_bt_StartPause_clicked();

    void on_lw_list_doubleClicked(const QModelIndex &index);

    void on_bt_last_clicked();

    void on_bt_next_clicked();

    void on_bt_voice_clicked();

    void on_bt_close_clicked();

    void on_bt_min_clicked();

    void on_bt_del_clicked();

private:
    Ui::MusicWidget *ui;
    QString musicList[MUSICLIST_MAXLEN];
    QString musicLrc[MUSICLRC_MAXLEN];
    QString currentMusicName;
    int musicListCounter;
    int musicLrcLineCounter;
    int lrcAddLineCounter;
    int musicVolume_last;
    int musicVolume_now;
    QPoint startRelativePos;

    QMediaPlayer player;
    int playFlag;
    bool musicPositionChangeFlag;
    bool musicStartFlag;
    bool voiceOpenFlag;
};

#endif // MUSICWIDGET_H
