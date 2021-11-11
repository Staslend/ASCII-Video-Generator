#ifndef VIDEOASCII_H
#define VIDEOASCII_H

#include <QFile>
#include <QMediaPlayer>
#include <iostream>
#include <QVideoSink>
#include <QVideoFrame>
#include <QTimer>
#include <QMediaMetaData>

#include "acsii_converter.h"

class VideoASCII : public QObject
{
    QFile *file;
    QTextStream *textStream;
    QMediaPlayer mp;
    QVideoSink *vs;
    QMediaPlayer *med;
    int frameN = 0;

public:
    QTimer *t;

    VideoASCII();
    VideoASCII(std::string path);
    virtual ~VideoASCII();
public slots:
    void RenderFrame();
};
#endif // VIDEOASCII_H
