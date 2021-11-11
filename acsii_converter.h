#ifndef ACSII_CONVERTER_H
#define ACSII_CONVERTER_H
#include <QApplication>
#include <string>
#include <iostream>

class ACSII_Converter
{
    static int WINDOW_SIZE_X;
    static int WINDOW_SIZE_Y;
    static int RESOLUTION_X;
    static int RESOLUTION_Y;
    static int SYMPHOL_HEIGHT;
    static int SYMPHOL_WIDTH;

    static QString grayness;

public:
    ACSII_Converter();
    static void ConvertAndOutput(std::string path);

    static void ConvertAndPutToStream(QImage im,
                                      QTextStream *stream);

    static int GetGrayness(QColor color);

    static void SetParams(int imgWidth,
                   int imgHeight,
                   int WINDOW_SIZE_X,
                   int WINDOW_SIZE_Y);

    static int GetGraynessOfArea(QImage *im,
                                 int px,
                                 int py);


};


#endif // ACSII_CONVERTER_H
