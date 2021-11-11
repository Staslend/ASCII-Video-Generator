#include "acsii_converter.h"

int ACSII_Converter::WINDOW_SIZE_X = 0;
int ACSII_Converter::WINDOW_SIZE_Y = 0;
int ACSII_Converter::RESOLUTION_X = 0;
int ACSII_Converter::RESOLUTION_Y = 0;
int ACSII_Converter::SYMPHOL_HEIGHT = 0;
int ACSII_Converter::SYMPHOL_WIDTH = 0;

QString ACSII_Converter::grayness = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'. ";


ACSII_Converter::ACSII_Converter()
{
}

void ACSII_Converter::SetParams(int imgWidth, int imgHeight, int WINDOW_SIZE_X2, int WINDOW_SIZE_Y2)
{
    WINDOW_SIZE_X = WINDOW_SIZE_X2;
    WINDOW_SIZE_Y = WINDOW_SIZE_Y2;


    //RESOLUTION OF FINAL ASCII ART
    RESOLUTION_X = (WINDOW_SIZE_Y * imgWidth / imgHeight) * 2;
    RESOLUTION_Y = WINDOW_SIZE_Y * WINDOW_SIZE_X / RESOLUTION_X;
    RESOLUTION_X = WINDOW_SIZE_X;

    //SIZE OF AREA FOR EVERY SYMPHOL
    SYMPHOL_HEIGHT = imgHeight / RESOLUTION_Y;
    SYMPHOL_WIDTH = imgWidth / RESOLUTION_X;

}

void ACSII_Converter::ConvertAndOutput(std::string path)
{
    QImage im(path.c_str());

    for(int py = 0; py < RESOLUTION_Y; py++)
    {
        for(int px = 0; px < RESOLUTION_X; px++)
        {
            std::cout << ACSII_Converter::grayness.toStdString()[ACSII_Converter::GetGraynessOfArea(&im,px,py)];
        }
        std::cout << std::endl;
    }

}

int ACSII_Converter::GetGraynessOfArea(QImage *im, int px, int py)
{
    int gs = 0;
    for(int y = py; y < py + SYMPHOL_HEIGHT; y++)
    {
        for(int x = px; x < px + SYMPHOL_WIDTH; x++)
        {
            gs += ACSII_Converter::GetGrayness(im->pixelColor(x,y));
        }
    }
    return gs / (SYMPHOL_WIDTH * SYMPHOL_HEIGHT) * grayness.size() / 256;
}


int ACSII_Converter::GetGrayness(QColor color)
{
    return (int)(color.red() + color.green() + color.blue())/3;
}

void ACSII_Converter::ConvertAndPutToStream(QImage im, QTextStream *stream)
{

    if(stream->device() == nullptr)
    {
        std::cout << "Ta tu cock" << std::endl;
        return;
    }

    for(int py = 0; py < RESOLUTION_Y; py++)
    {
        for(int px = 0; px < RESOLUTION_X; px++)
        {
            *stream << ACSII_Converter::grayness.toStdString()[ACSII_Converter::GetGraynessOfArea(&im,px,py)];
        }
        *stream << Qt::endl;
    }
    stream->flush();

}

