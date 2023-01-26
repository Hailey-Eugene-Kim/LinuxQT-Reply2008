#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "musicdialog.h"
#include "cameradialog.h"
#include "songdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_musicButton_clicked()
{
    MusicDialog dlg;
    dlg.exec();
}

void MainWindow::on_cameraButton_clicked()
{
    CameraDialog dlg;
    dlg.exec();
}

void MainWindow::on_songButton_clicked()
{
    SongDialog dlg;
    dlg.exec();
}
