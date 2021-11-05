#ifndef ACSII_CONVERTER_H
#define ACSII_CONVERTER_H
#include <QApplication>
#include <string>
#include <iostream>

class ACSII_Converter
{

public:
    ACSII_Converter();
    static void ConvertAndOutput(std::string path,
                          int WINDOW_SIZE_X,
                          int WINDOW_SIZE_Y,
                          int RESOLUTION_X,
                          int RESOLUTION_Y,
                          int SYMPHOL_WIDTH,
                          int SYMPHOL_HEIGHT);

    static void ConvertAndPutToStream(QImage im,
                          int WINDOW_SIZE_X,
                          int WINDOW_SIZE_Y,
                          int RESOLUTION_X,
                          int RESOLUTION_Y,
                          int SYMPHOL_WIDTH,
                          int SYMPHOL_HEIGHT,
                          QTextStream *stream);


};

#endif // ACSII_CONVERTER_H
