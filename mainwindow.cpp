#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QVideoWidget(parent)
{
    mp = new QMediaPlayer();
    mp->setSource(QUrl::fromLocalFile("/home/tanaka/Videos/n.mp4"));

    vs = new QVideoSink();
    mp->setVideoOutput(this);    
  //  mp->play();

}

void MainWindow::SetVideoSink(QVideoSink *v)
{
    vs = v;
    mp->setVideoSink(vs);
}

MainWindow::~MainWindow()
{
    free(mp);
    free(vs);
}

