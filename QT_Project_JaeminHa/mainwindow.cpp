#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "secondwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_btn_clicked()
{
    this->hide();
    secondwindow game_secondwindow;
    game_secondwindow.move(this->geometry().topLeft());
    game_secondwindow.setModal(true);
    game_secondwindow.exec();
}

