//
// Created by christian on 24.10.24.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QIntValidator>
#include <QDebug>
#include <QElapsedTimer>
#include "../CTImage.h"
#include "../ErrorHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CTImage currentImage;// Store the currently loaded image
    int counterWindowing = 0;
    int counterLayering = 0;
    int timerWindowing = 0;
    int timerLayering = 0;

private slots:
    void loadImage();
    void updateWindowing();
    void calculateDepthBuffer();
};
#endif // MAINWINDOW_H
