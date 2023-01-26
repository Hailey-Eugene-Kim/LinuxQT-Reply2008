#ifndef SONGDIALOG_H
#define SONGDIALOG_H
#include <musicthread.h>

#include <QDialog>

namespace Ui {
class SongDialog;
}

class SongDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SongDialog(QWidget *parent = 0);
    ~SongDialog();
    
private slots:
    
    void handleCommand(int);
    
    void on_pauseButton_clicked();
    
    void on_playButton_clicked();

    void on_dotoriButton_clicked();
    
    void on_skipButton_clicked();
    
    void on_exitButton_clicked();

    void on_volumeupButton_clicked();

    void on_volumedownButton_clicked();

    void on_stopButton_clicked();

    void on_openButton_clicked();

    void on_albumWidget_destroyed();

private:
    Ui::SongDialog *ui;
    int song_fd_pipe[2];
    MusicThread *musicThread;
};

#endif // SONGDIALOG_H
