#include "acsii_converter.h"
#include "videoascii.h"

#include <QCoreApplication>
#include <QTimer>
#include <QFile>
#include <QDir>

#include <QMediaPlayer>
#include <QVideoSink>
#include <QVideoFrame>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VideoASCII va("/home/tanaka/Documents/animeVid2");

    va.t = new QTimer();
    QObject::connect(va.t, &QTimer::timeout, &va, &VideoASCII::RenderFrame);
    va.t->start(150);

  return a.exec();

}
