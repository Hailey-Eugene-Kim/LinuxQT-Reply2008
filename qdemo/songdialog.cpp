#include "songdialog.h"
#include "ui_songdialog.h"
#include <stdio.h>
#include <signal.h>
#include <QFileDialog>
#include <QDirIterator>
#include <QDebug>

volatile int song_play_flag;
int row = 0; //DList

void song_sigChldHandler(int signal) {
    printf("got signal %d\n", signal);
    song_play_flag = 0;
}

SongDialog::SongDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SongDialog)
{
    ui->setupUi(this);

    song_play_flag = 0;
    if (pipe(song_fd_pipe) == -1) close();

    musicThread = new MusicThread();
    connect(musicThread, SIGNAL(sendCommand(int)), this, SLOT(handleCommand(int)));
    musicThread->start();
}

void SongDialog::handleCommand(int song_cmd)
{
    if ((song_cmd == 1)&&(song_play_flag)) {
        static int toggle = 0;
        toggle ^= 1;
        if (toggle)
            ui->nameLabel->setStyleSheet("color:rgb(0,0,0)");
        else
            ui->nameLabel->setStyleSheet("color:rgb(0,0,255)");
    }
}

SongDialog::~SongDialog()
{
    delete ui;
}

void SongDialog::on_playButton_clicked()
{
    pid_t song_pid_temp;
    char song_cmd[256];

    if(song_play_flag) return;
    song_play_flag = 1;
    song_pid_temp = fork();
    if(song_pid_temp == -1) exit(-1);
    else if (song_pid_temp == 0) {
        ::close(0);
        dup(song_fd_pipe[0]);
        ::close(song_fd_pipe[0]);
        ::close(song_fd_pipe[1]);

        QString fullname = ui->nameLabel->text();
        fullname.prepend("/mnt/nfs/mp3/");
        strcpy(song_cmd, fullname.toStdString().c_str());
        execlp("/mnt/nfs/mplayer", "mplayer", "-volume", "30", "-srate", "44100", song_cmd, NULL);
    }
    else {

        sighandler_t song_sig_ret;
        song_sig_ret = signal(SIGCHLD, song_sigChldHandler);
        if(song_sig_ret == SIG_ERR) exit(-1);
    }


}

void SongDialog::on_pauseButton_clicked()
{
    if(song_play_flag == 0) return;
    write(song_fd_pipe[1], "p", 1);
}

void SongDialog::on_stopButton_clicked()
{
    if(song_play_flag == 0) return;
    write(song_fd_pipe[1], "q", 1);
}

void SongDialog::on_dotoriButton_clicked()
{
    //add current song to DListWidget
    QString dotoriName = (QString)ui->nameLabel->text();

    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText(dotoriName);
    ui->DListWidget->insertItem(row++, newItem);

}

void SongDialog::on_skipButton_clicked()
{

}

void SongDialog::on_volumeupButton_clicked()
{
    write(song_fd_pipe[1], "0", 1);
}

void SongDialog::on_volumedownButton_clicked()
{
    write(song_fd_pipe[1], "9", 1);
}

void SongDialog::on_exitButton_clicked()
{
    SongDialog::on_stopButton_clicked();
    close();
}


void SongDialog::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Music"), "/mnt/nfs/mp3", tr("Music Files (*.mp3 *.wav)"));

    if (!fileName.isEmpty())
        fileName.remove(0, 13);
        ui->nameLabel->setText(fileName);
}
