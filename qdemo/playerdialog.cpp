#include "playerdialog.h"
#include "ui_playerdialog.h"
#include "songdialog.h"
#include <stdio.h>
#include <signal.h>
#include <QFileDialog>

volatile int play_flag;


void sigChldHandler(int signal){
    printf("got signal %d\n", signal);
    play_flag = 0;
}

PlayerDialog::PlayerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerDialog)
{
    ui->setupUi(this);
}

PlayerDialog::~PlayerDialog()
{
    delete ui;
}

void PlayerDialog::on_startButton_clicked()
{
    SongDialog dlg;
    dlg.exec();
}
