/********************************************************************************
** Form generated from reading UI file 'musicwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWIDGET_H
#define UI_MUSICWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicWidget
{
public:
    QListWidget *lw_list;
    QListWidget *lw_lrc;
    QPushButton *bt_add;
    QPushButton *bt_close;
    QPushButton *bt_min;
    QGroupBox *gb_container;
    QSlider *slider_musicTime;
    QPushButton *bt_next;
    QPushButton *bt_StartPause;
    QPushButton *bt_last;
    QLabel *lb_musicTime;
    QSlider *slider_volume;
    QPushButton *bt_voice;
    QLabel *lb_musicTime_2;
    QPushButton *bt_del;

    void setupUi(QWidget *MusicWidget)
    {
        if (MusicWidget->objectName().isEmpty())
            MusicWidget->setObjectName(QString::fromUtf8("MusicWidget"));
        MusicWidget->resize(1243, 611);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/14.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MusicWidget->setWindowIcon(icon);
        MusicWidget->setAutoFillBackground(false);
        MusicWidget->setStyleSheet(QString::fromUtf8(""));
        lw_list = new QListWidget(MusicWidget);
        lw_list->setObjectName(QString::fromUtf8("lw_list"));
        lw_list->setGeometry(QRect(50, 400, 1141, 71));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(true);
        font.setUnderline(false);
        font.setWeight(50);
        lw_list->setFont(font);
        lw_list->setStyleSheet(QString::fromUtf8(""));
        lw_lrc = new QListWidget(MusicWidget);
        lw_lrc->setObjectName(QString::fromUtf8("lw_lrc"));
        lw_lrc->setEnabled(false);
        lw_lrc->setGeometry(QRect(0, 30, 1251, 371));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lw_lrc->sizePolicy().hasHeightForWidth());
        lw_lrc->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("PMingLiU-ExtB"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        lw_lrc->setFont(font1);
        lw_lrc->setStyleSheet(QString::fromUtf8(""));
        lw_lrc->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lw_lrc->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        bt_add = new QPushButton(MusicWidget);
        bt_add->setObjectName(QString::fromUtf8("bt_add"));
        bt_add->setGeometry(QRect(10, 430, 41, 41));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        bt_add->setFont(font2);
        bt_add->setCursor(QCursor(Qt::PointingHandCursor));
        bt_close = new QPushButton(MusicWidget);
        bt_close->setObjectName(QString::fromUtf8("bt_close"));
        bt_close->setGeometry(QRect(1210, 0, 31, 31));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        bt_close->setFont(font3);
        bt_close->setCursor(QCursor(Qt::PointingHandCursor));
        bt_close->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);"));
        bt_close->setFlat(true);
        bt_min = new QPushButton(MusicWidget);
        bt_min->setObjectName(QString::fromUtf8("bt_min"));
        bt_min->setGeometry(QRect(1150, 0, 31, 31));
        bt_min->setFont(font3);
        bt_min->setCursor(QCursor(Qt::PointingHandCursor));
        bt_min->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 0);\n"
""));
        bt_min->setFlat(true);
        gb_container = new QGroupBox(MusicWidget);
        gb_container->setObjectName(QString::fromUtf8("gb_container"));
        gb_container->setGeometry(QRect(0, 470, 1251, 141));
        gb_container->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0.36, y1:0.443, x2:1, y2:0, stop:0.202247 rgba(89, 255, 249, 128), stop:1 rgba(255, 255, 255, 255));\n"
"border-color: rgba(255, 255, 255, 0);"));
        gb_container->setFlat(false);
        slider_musicTime = new QSlider(gb_container);
        slider_musicTime->setObjectName(QString::fromUtf8("slider_musicTime"));
        slider_musicTime->setGeometry(QRect(340, 120, 611, 20));
        slider_musicTime->setCursor(QCursor(Qt::PointingHandCursor));
        slider_musicTime->setMaximum(100);
        slider_musicTime->setOrientation(Qt::Horizontal);
        bt_next = new QPushButton(gb_container);
        bt_next->setObjectName(QString::fromUtf8("bt_next"));
        bt_next->setGeometry(QRect(730, 30, 61, 61));
        bt_next->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/bfzn_002.png"), QSize(), QIcon::Normal, QIcon::Off);
        bt_next->setIcon(icon1);
        bt_next->setIconSize(QSize(40, 40));
        bt_next->setAutoDefault(false);
        bt_next->setFlat(true);
        bt_StartPause = new QPushButton(gb_container);
        bt_StartPause->setObjectName(QString::fromUtf8("bt_StartPause"));
        bt_StartPause->setGeometry(QRect(590, 40, 51, 51));
        bt_StartPause->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/bfzn_004.png"), QSize(), QIcon::Normal, QIcon::Off);
        bt_StartPause->setIcon(icon2);
        bt_StartPause->setIconSize(QSize(40, 40));
        bt_StartPause->setAutoDefault(false);
        bt_StartPause->setFlat(true);
        bt_last = new QPushButton(gb_container);
        bt_last->setObjectName(QString::fromUtf8("bt_last"));
        bt_last->setGeometry(QRect(440, 30, 61, 61));
        bt_last->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/bfzn_001.png"), QSize(), QIcon::Normal, QIcon::Off);
        bt_last->setIcon(icon3);
        bt_last->setIconSize(QSize(40, 40));
        bt_last->setAutoDefault(false);
        bt_last->setFlat(true);
        lb_musicTime = new QLabel(gb_container);
        lb_musicTime->setObjectName(QString::fromUtf8("lb_musicTime"));
        lb_musicTime->setGeometry(QRect(240, 120, 51, 21));
        lb_musicTime->setFont(font2);
        slider_volume = new QSlider(gb_container);
        slider_volume->setObjectName(QString::fromUtf8("slider_volume"));
        slider_volume->setGeometry(QRect(1050, 50, 151, 16));
        slider_volume->setCursor(QCursor(Qt::PointingHandCursor));
        slider_volume->setMaximum(100);
        slider_volume->setOrientation(Qt::Horizontal);
        bt_voice = new QPushButton(gb_container);
        bt_voice->setObjectName(QString::fromUtf8("bt_voice"));
        bt_voice->setGeometry(QRect(1000, 50, 31, 21));
        bt_voice->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../build-MusicBox-Desktop_Qt_5_6_0_MinGW_32bit-Debug/images/voice_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        bt_voice->setIcon(icon4);
        bt_voice->setIconSize(QSize(16, 16));
        bt_voice->setAutoDefault(false);
        bt_voice->setFlat(true);
        lb_musicTime_2 = new QLabel(gb_container);
        lb_musicTime_2->setObjectName(QString::fromUtf8("lb_musicTime_2"));
        lb_musicTime_2->setGeometry(QRect(980, 120, 51, 21));
        lb_musicTime_2->setFont(font2);
        bt_del = new QPushButton(MusicWidget);
        bt_del->setObjectName(QString::fromUtf8("bt_del"));
        bt_del->setGeometry(QRect(1190, 430, 41, 41));
        bt_del->setFont(font2);
        bt_del->setCursor(QCursor(Qt::PointingHandCursor));
        gb_container->raise();
        lw_list->raise();
        lw_lrc->raise();
        bt_add->raise();
        bt_close->raise();
        bt_min->raise();
        bt_del->raise();

        retranslateUi(MusicWidget);

        QMetaObject::connectSlotsByName(MusicWidget);
    } // setupUi

    void retranslateUi(QWidget *MusicWidget)
    {
        MusicWidget->setWindowTitle(QApplication::translate("MusicWidget", "MusicPlayer", nullptr));
        bt_add->setText(QApplication::translate("MusicWidget", "+", nullptr));
        bt_close->setText(QApplication::translate("MusicWidget", "\303\227", nullptr));
        bt_min->setText(QApplication::translate("MusicWidget", "\342\200\224", nullptr));
        gb_container->setTitle(QString());
        bt_next->setText(QString());
        bt_StartPause->setText(QString());
        bt_last->setText(QString());
        lb_musicTime->setText(QApplication::translate("MusicWidget", "00:00", nullptr));
        bt_voice->setText(QString());
        lb_musicTime_2->setText(QApplication::translate("MusicWidget", "00:00", nullptr));
        bt_del->setText(QApplication::translate("MusicWidget", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicWidget: public Ui_MusicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWIDGET_H
