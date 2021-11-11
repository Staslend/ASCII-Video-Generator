#include "videoascii.h"



    VideoASCII::VideoASCII()
    {

    }

    VideoASCII::VideoASCII(std::string path)
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


        med->setSource(QUrl::fromLocalFile("/home/tanaka/Videos/n.mp4"));
        med->setVideoOutput(med);
        med->play();

        vs = new QVideoSink;
        med->setVideoSink(vs);

        QMediaMetaData data = med->metaData();
        std::cout << data.stringValue(QMediaMetaData::Resolution).data()-> << std::cout;
        ACSII_Converter::SetParams(1920, 1080,200,60);
    }

    VideoASCII::~VideoASCII()
    {

    }

    void  VideoASCII::RenderFrame()
    {
        std::cout << frameN << std::endl;

        ACSII_Converter::ConvertAndPutToStream(vs->videoFrame().toImage(),
                                               textStream);
        *textStream << "Line Break" << Qt::endl;
        t->start(30);
        frameN++;
    }
