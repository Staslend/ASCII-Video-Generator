#include "acsii_converter.h"
#include <QCoreApplication>
#include <QTimer>
#include <QFile>
#include <QDir>

#include <QMediaPlayer>
#include <QVideoSink>
#include <QVideoFrame>

QTimer *t;

class VideoASCII : public QObject
{


    QFile *file;
    QTextStream *textStream;
    QMediaPlayer mp;
    QVideoSink *vs;
    QMediaPlayer *med;
    int frameN = 0;

public:
    VideoASCII()
    {

    }
    VideoASCII(std::string path)
    {
        med = new QMediaPlayer();
        file = new QFile(path.c_str());
        if (!file->open(QIODevice::ReadWrite | QIODevice::Text))
        {
            std::cout << "No file" << std::endl;
            return;
        }
        else file->resize(0);
        textStream = new QTextStream(file);
        if(textStream->device() == nullptr)
        {
            std::cout << "No device" << std::endl;
            return;
        }

        ACSII_Converter::SetParams(1920,1080,200,60);

        mp.setSource(QUrl::fromLocalFile("/home/tanaka/Videos/n.mp4"));
        mp.setVideoOutput(med);
        mp.play();

        vs = new QVideoSink;
        mp.setVideoSink(vs);
    }
    virtual ~VideoASCII()
    {

    }
public slots:
    void RenderFrame()
    {
        std::cout << frameN << std::endl;

        ACSII_Converter::ConvertAndPutToStream(vs->videoFrame().toImage(),
                                               textStream);
        *textStream << "Line Break" << Qt::endl;
        t->start(30);
        frameN++;
    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VideoASCII va("/home/tanaka/Documents/animeVid2");

    t = new QTimer();
    QObject::connect(t, &QTimer::timeout, &va, &VideoASCII::RenderFrame);
    t->start(150);

  return a.exec();

}
