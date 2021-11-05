#include "acsii_converter.h"

ACSII_Converter::ACSII_Converter()
{

}

void ACSII_Converter::ConvertAndOutput(std::string path, int WINDOW_SIZE_X, int WINDOW_SIZE_Y, int RESOLUTION_X, int RESOLUTION_Y, int SYMPHOL_WIDTH, int SYMPHOL_HEIGHT)
{
    QImage im(path.c_str());

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

}
