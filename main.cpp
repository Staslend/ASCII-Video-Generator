#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <string>
//QLabel *l;
//QVideoSink *v;
//QTimer *t;


int WINDOW_SIZE_X = 500;
int WINDOW_SIZE_Y = 500;

int RESOLUTION_X = 200;
int RESOLUTION_Y = 60;



int  SYMPHOL_WIDTH;
int  SYMPHOL_HEIGHT;

#define FRAME_PER_SEC 30;
const int frameRate = 1000 / FRAME_PER_SEC;

int Grayscale(QColor rgb)
{
   // std::cout << "Grayscale pixel" << std::endl;

 //   std::cout << (int)(rgb.red() + rgb.green() + rgb.blue())/3 << std::endl;
    return (int)(rgb.red() + rgb.green() + rgb.blue())/3 ;
}

int Grayscale(QImage im)
{
   // std::cout << "Grayscale Image" << std::endl;
    int gs = 0;
    for(int x = 0; x < im.width();x++)
    {
        for(int y = 0; y < im.height(); y++)
        {
            gs += Grayscale(im.pixelColor(y,x));
        }
    }
    gs /= im.width() * im.height();

    return gs;
}

int Grayscale(QImage im, int sx, int sy, int w, int h)
{
   // std::cout << "Grayscale fragment" << std::endl;

    int gs = 0;

    for(int y = sy; y < sy+h; y++)
    {
        for(int x = sx; x < sx+w;x++)
        {
            gs += Grayscale(im.pixelColor(x,y));
        }
    }
    gs /= w * h;
  //  std::cout << gs << std::endl;

    return gs;
}

void f()
{
 //   l->setPixmap(QPixmap::fromImage(v->videoFrame().toImage().scaled(640,360)));
 //   t->start(frameRate);
  //  qDebug() << "Frame";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QImage im("/home/tanaka/Pictures/aaaa.jpg");

    //RESOLUTION OF FINAL ASCII ART
    RESOLUTION_X = (WINDOW_SIZE_Y * im.width() / im.height()) * 2;
    RESOLUTION_Y = WINDOW_SIZE_Y * WINDOW_SIZE_X / RESOLUTION_X;
    RESOLUTION_X = WINDOW_SIZE_X;

    //SIZE OF AREA FOR EVERY SYMPHOL
    SYMPHOL_HEIGHT = im.height() / RESOLUTION_Y;
    SYMPHOL_WIDTH = im.width() / RESOLUTION_X;


    /*
    l = new QLabel;
    l->resize(640,360);
    l->show();
    v = new QVideoSink;
    w.SetVideoSink(v);

    t = new QTimer();
    QObject::connect(t, &QTimer::timeout, f);
    t->start(1000);
    */

    QString grayness = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'. ";

    for(int y = 0; y < RESOLUTION_Y; y+=1)
    {
        for(int x = 0; x < RESOLUTION_X; x+=1)
        {
                std::cout << grayness.toStdString()[Grayscale(im,x * SYMPHOL_WIDTH,y * SYMPHOL_HEIGHT,SYMPHOL_WIDTH,SYMPHOL_HEIGHT) * grayness.size() / 256];
        }
        std::cout << std::endl;
    }
    return a.exec();
}
