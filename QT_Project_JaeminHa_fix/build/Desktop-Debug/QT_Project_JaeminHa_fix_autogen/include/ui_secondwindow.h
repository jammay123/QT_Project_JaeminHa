/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_secondwindow
{
public:
    QLabel *text_label;
    QPushButton *shoot_btn;
    QPushButton *inventory_btn;
    QLabel *main_label;
    QLabel *hp_label;
    QLCDNumber *my_hp_lcd;
    QLabel *hp_label_2;
    QLCDNumber *enemy_hp_lcd;
    QPushButton *cookie_btn;
    QPushButton *critical_btn;
    QPushButton *insight_btn;
    QPushButton *flash_btn;
    QPushButton *reload_btn;
    QPushButton *turn_btn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *secondwindow)
    {
        if (secondwindow->objectName().isEmpty())
            secondwindow->setObjectName(QString::fromUtf8("secondwindow"));
        secondwindow->resize(800, 600);
        secondwindow->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 2, 2);"));
        text_label = new QLabel(secondwindow);
        text_label->setObjectName(QString::fromUtf8("text_label"));
        text_label->setGeometry(QRect(10, 420, 591, 170));
        text_label->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"color: rgb(255, 255, 255);"));
        shoot_btn = new QPushButton(secondwindow);
        shoot_btn->setObjectName(QString::fromUtf8("shoot_btn"));
        shoot_btn->setGeometry(QRect(610, 270, 180, 60));
        shoot_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"font: 25pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        inventory_btn = new QPushButton(secondwindow);
        inventory_btn->setObjectName(QString::fromUtf8("inventory_btn"));
        inventory_btn->setGeometry(QRect(610, 340, 180, 60));
        inventory_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"font: 25pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        main_label = new QLabel(secondwindow);
        main_label->setObjectName(QString::fromUtf8("main_label"));
        main_label->setGeometry(QRect(10, 10, 590, 400));
        main_label->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"color: rgb(255, 255, 255);"));
        hp_label = new QLabel(secondwindow);
        hp_label->setObjectName(QString::fromUtf8("hp_label"));
        hp_label->setGeometry(QRect(610, 10, 180, 50));
        hp_label->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"color: rgb(255, 255, 255);\n"
""));
        my_hp_lcd = new QLCDNumber(secondwindow);
        my_hp_lcd->setObjectName(QString::fromUtf8("my_hp_lcd"));
        my_hp_lcd->setGeometry(QRect(610, 70, 180, 60));
        my_hp_lcd->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"color: rgb(255, 255, 255);"));
        hp_label_2 = new QLabel(secondwindow);
        hp_label_2->setObjectName(QString::fromUtf8("hp_label_2"));
        hp_label_2->setGeometry(QRect(610, 140, 180, 50));
        hp_label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"color: rgb(255, 255, 255);\n"
""));
        enemy_hp_lcd = new QLCDNumber(secondwindow);
        enemy_hp_lcd->setObjectName(QString::fromUtf8("enemy_hp_lcd"));
        enemy_hp_lcd->setGeometry(QRect(610, 200, 180, 60));
        enemy_hp_lcd->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"color: rgb(255, 255, 255);"));
        cookie_btn = new QPushButton(secondwindow);
        cookie_btn->setObjectName(QString::fromUtf8("cookie_btn"));
        cookie_btn->setGeometry(QRect(610, 440, 180, 27));
        cookie_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        critical_btn = new QPushButton(secondwindow);
        critical_btn->setObjectName(QString::fromUtf8("critical_btn"));
        critical_btn->setGeometry(QRect(610, 500, 180, 27));
        critical_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        insight_btn = new QPushButton(secondwindow);
        insight_btn->setObjectName(QString::fromUtf8("insight_btn"));
        insight_btn->setGeometry(QRect(610, 530, 180, 27));
        insight_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        flash_btn = new QPushButton(secondwindow);
        flash_btn->setObjectName(QString::fromUtf8("flash_btn"));
        flash_btn->setGeometry(QRect(610, 560, 180, 27));
        flash_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        reload_btn = new QPushButton(secondwindow);
        reload_btn->setObjectName(QString::fromUtf8("reload_btn"));
        reload_btn->setGeometry(QRect(610, 470, 180, 27));
        reload_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(71, 6, 6);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        turn_btn = new QPushButton(secondwindow);
        turn_btn->setObjectName(QString::fromUtf8("turn_btn"));
        turn_btn->setGeometry(QRect(610, 410, 180, 27));
        turn_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(129, 61, 156);\n"
"font: 15pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(secondwindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 250, 231, 161));
        label->setStyleSheet(QString::fromUtf8("image: url(:/image_comfil/russian_rullet_image.jpg);"));
        label_2 = new QLabel(secondwindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(370, 10, 231, 161));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/image_comfil/russian_rullet_image.jpg);"));
        label_3 = new QLabel(secondwindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 160, 181, 101));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/image_comfil/revolver.jpg);"));

        retranslateUi(secondwindow);

        QMetaObject::connectSlotsByName(secondwindow);
    } // setupUi

    void retranslateUi(QDialog *secondwindow)
    {
        secondwindow->setWindowTitle(QCoreApplication::translate("secondwindow", "Dialog", nullptr));
        text_label->setText(QString());
        shoot_btn->setText(QCoreApplication::translate("secondwindow", "shoot", nullptr));
        inventory_btn->setText(QCoreApplication::translate("secondwindow", "inventory", nullptr));
        main_label->setText(QString());
        hp_label->setText(QCoreApplication::translate("secondwindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">PLAYER HP</span></p></body></html>", nullptr));
        hp_label_2->setText(QCoreApplication::translate("secondwindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">ENEMY HP</span></p></body></html>", nullptr));
        cookie_btn->setText(QCoreApplication::translate("secondwindow", "cookie", nullptr));
        critical_btn->setText(QCoreApplication::translate("secondwindow", "critical", nullptr));
        insight_btn->setText(QCoreApplication::translate("secondwindow", "insight", nullptr));
        flash_btn->setText(QCoreApplication::translate("secondwindow", "flash", nullptr));
        reload_btn->setText(QCoreApplication::translate("secondwindow", "reload", nullptr));
        turn_btn->setText(QCoreApplication::translate("secondwindow", "turn", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class secondwindow: public Ui_secondwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
