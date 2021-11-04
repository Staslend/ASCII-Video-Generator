#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QMediaPlayer>

#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QVideoWidget
{
    Q_OBJECT

    QMediaPlayer *mp;
    QThread th;
    QVideoSink *vs;
public:
    MainWindow(QWidget *parent = nullptr);
    void SetVideoSink(QVideoSink *);
    ~MainWindow();
};
#endif // MAINWINDOW_H
