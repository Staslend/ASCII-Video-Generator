#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <string>

int WINDOW_SIZE_X = 500;
int WINDOW_SIZE_Y = 500;

int RESOLUTION_X = 200;
int RESOLUTION_Y = 60;

int  SYMPHOL_WIDTH;
int  SYMPHOL_HEIGHT;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QImage im("/home/tanaka/Pictures/aaaa.jpg");

    //RESOLUTION OF FINAL ASCII ART
    RESOLUTION_X = (WINDOW_SIZE_Y * im.width() / im.height()) * 2;
    RESOLUTION_Y = WINDOW_SIZE_Y * WINDOW_SIZE_X / RESOLUTION_X;
    RESOLUTION_X = WINDOW_SIZE_X;

    //SIZE OF AREA FOR EVERY SYMPHOL
    SYMPHOL_HEIGHT = im.height() / RESOLUTION_Y;
    SYMPHOL_WIDTH = im.width() / RESOLUTION_X;

    QString grayness = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'. ";

    for(int py = 0; py < RESOLUTION_Y; py+=1)
    {
        for(int px = 0; px < RESOLUTION_X; px+=1)
        {
            int gs = 0;

            for(int y = py * SYMPHOL_HEIGHT; y < py * SYMPHOL_HEIGHT+SYMPHOL_HEIGHT; y++)
            {
                for(int x = px * SYMPHOL_WIDTH; x < px * SYMPHOL_WIDTH + SYMPHOL_WIDTH; x++)
                {
                    gs += (int)(im.pixelColor(x,y).red() + im.pixelColor(x,y).green() + im.pixelColor(x,y).blue())/3;
                }
            }
            std::cout << grayness.toStdString()[gs / (SYMPHOL_WIDTH * SYMPHOL_HEIGHT) * grayness.size() / 256];
        }
        std::cout << std::endl;
    }
    return a.exec();
}
