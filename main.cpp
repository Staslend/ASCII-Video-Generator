#include "acsii_converter.h"
#include <QCoreApplication>
#include <QTimer>
#include <QFile>
#include <QDir>

#include <QMediaPlayer>
#include <QVideoSink>
#include <QVideoFrame>

QTimer *timer;


void func(QImage im, QTextStream *textStream)
{

    ACSII_Converter::ConvertAndPutToStream(im,
                                           200, 60,
                                           200, 60,
                                           3, 6,
                                           textStream);
    timer->start(200);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("/home/tanaka/Documents/animeVid");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream textStream(&file);

    QMediaPlayer mp;
    mp.setSource(QUrl::fromLocalFile("/home/tanaka/Videos/n.mp4"));
    mp.play();

    QVideoSink *vs = new QVideoSink;
    mp.setVideoSink(vs);



  return a.exec();

}
