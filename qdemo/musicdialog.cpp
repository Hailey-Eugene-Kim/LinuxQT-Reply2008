#include "musicdialog.h"
#include "ui_musicdialog.h"
#include <stdio.h>
#include <signal.h>
#include <QFileDialog>

volatile int play_flag;

void sigChldHandler(int signal){
    printf("got signal %d\n", signal);
    play_flag = 0;
}

MusicDialog::MusicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MusicDialog)
{
    ui->setupUi(this);
    play_flag = 0;
    if(pipe(fd_pipe) == -1) close();
}

MusicDialog::~MusicDialog()
{
    delete ui;
}

void MusicDialog::on_exitButton_clicked()
{
    if (play_flag) {
        write(fd_pipe[1], "q", 1);
        while(play_flag);
    }
    ::close(fd_pipe[0]);
    ::close(fd_pipe[1]);
    close();
}

void MusicDialog::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Music"), "/mnt/nfs", tr("Music Files (*.mp3 *.wav)"));

    if(!fileName.isEmpty())
        ui->openFileLabel->setText(fileName);
}

void MusicDialog::on_playButton_clicked()
{
    pid_t pid_temp;
    char cmd[256];

    if(play_flag) return;
    play_flag = 1;
    pid_temp = fork();
    if(pid_temp == -1) exit(-1);
    else if (pid_temp == 0) {
        ::close(0);
        dup(fd_pipe[0]);
        ::close(fd_pipe[0]);
        ::close(fd_pipe[1]);
        strcpy(cmd, ui->openFileLabel->text().toStdString().c_str());
        execlp("/mnt/nfs/mplayer", "mplayer", "-volume", "30", "-srate", "44100", cmd, NULL);
    }
    else {
        sighandler_t sig_ret;
        sig_ret = signal(SIGCHLD, sigChldHandler);
        if(sig_ret == SIG_ERR) exit(-1);
    }
}

void MusicDialog::on_pauseButton_clicked()
{
    if(play_flag == 0) return;
    write(fd_pipe[1], "p", 1);
}

void MusicDialog::on_stopButton_clicked()
{
    if(play_flag == 0) return;
    write(fd_pipe[1], "q", 1);
}
