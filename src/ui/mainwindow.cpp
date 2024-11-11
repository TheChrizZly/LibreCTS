//
// Created by christian on 24.10.24.
//

#include "mainwindow.h"
#include "mainwindow.h"

#include <qguiapplication.h>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow), currentImage() {
    ui->setupUi(this);
    ui->windowingCenterValue->setValidator(new QIntValidator(-1024, 3095, this));
    ui->windowingWidthValue->setValidator(new QIntValidator(1, 2059, this));
    ui->layerValue->setValidator(new QIntValidator(1, 1, this));
    connect(ui->loadImageButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->windowCenterSlider, &QSlider::valueChanged, this, &MainWindow::updateWindowing);
    connect(ui->windowWidthSlider, &QSlider::valueChanged, this, &MainWindow::updateWindowing);
    connect(ui->windowingCenterValue, &QLineEdit::editingFinished, [this]() {
        ui->windowCenterSlider->setValue(ui->windowingCenterValue->text().toInt());
    });
    connect(ui->windowingWidthValue, &QLineEdit::editingFinished, [this]() {
        ui->windowWidthSlider->setValue(ui->windowingWidthValue->text().toInt());
    });
    connect(ui->layerSlider, &QSlider::valueChanged, [this](const int value) {
        QElapsedTimer timer;
        timer.start();
        currentImage.setLayer(value-1);
        ui->drawingArea->setImage(QPixmap::fromImage(currentImage.toQImage()));
        ui->layerValue->setText(QString::number(value));
        timerLayering += timer.nsecsElapsed();
        counterLayering += 1;
        qDebug() << " Avg Time Elapsed: " << timerLayering/counterLayering << "ns" << "Counter: " << counterLayering;
    });
    connect(ui->layerValue, &QLineEdit::editingFinished, [this]() {
        currentImage.setLayer(ui->layerValue->text().toInt()-1);
        ui->drawingArea->setImage(QPixmap::fromImage(currentImage.toQImage()));
        ui->layerSlider->setValue(ui->layerValue->text().toInt());
    });
    connect(ui->segmentationCheckbox, &QCheckBox::checkStateChanged, [this](const int state) {
    currentImage.setSegmentationActive(state == Qt::Checked);
    ui->drawingArea->setImage(QPixmap::fromImage(currentImage.toQImage()));
    });
    connect(ui->segmentationThresholdSlider, &QSlider::valueChanged, [this](const int value) {
        ui->segmentationThresholdValue->setText(QString::number(value));
        currentImage.setSegmentationThreshold(value);
        ui->drawingArea->setImage(QPixmap::fromImage(currentImage.toQImage()));
    });
    connect(ui->segmentationThresholdValue, &QLineEdit::editingFinished, [this]() {
        ui->segmentationThresholdSlider->setValue(ui->segmentationThresholdValue->text().toInt());
        currentImage.setSegmentationThreshold(ui->segmentationThresholdValue->text().toInt());
        ui->drawingArea->setImage(QPixmap::fromImage(currentImage.toQImage()));
    });

    connect(ui->calculateDepthMapButton, &QPushButton::clicked, this, &MainWindow::calculateDepthBuffer);
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::loadImage() {
    const QString fileName = QFileDialog::getOpenFileName(this, "Open Image", QCoreApplication::applicationDirPath(), "Image Files (*.raw)");
    CTImage ctImage;
    if(int res = ctImage.readImage(fileName, 512, 512, 130); res != 0) {
        ErrorHandler errorHandler;
        errorHandler.handleError(static_cast<ErrorCode>(res));
        return;
    }
    currentImage = ctImage;
    ui->layerSlider->setMaximum(currentImage.getImageDims().depth_);
    ui->layerValue->setValidator(new QIntValidator(1, currentImage.getImageDims().depth_, this));

    ui->drawingArea->setImage(QPixmap::fromImage(ctImage.toQImage()));
}

void MainWindow::updateWindowing() {
    QElapsedTimer timer;
    timer.start();
    // 1. Get current windowing values
    const int windowCenter = ui->windowCenterSlider->value();
    const int windowWidth = ui->windowWidthSlider->value();
    ui->windowingCenterValue->setText(QString::number(windowCenter));
    ui->windowingWidthValue->setText(QString::number(windowWidth));
    currentImage.setWindowingParameters(windowCenter, windowWidth);
    // 2. Update the image in the viewer
    ui->drawingArea->setImage(QPixmap::fromImage(currentImage.toQImage()));
    timerWindowing += timer.nsecsElapsed();
    counterWindowing += 1;
    //qDebug() << "Time elapsed: " << timer.nsecsElapsed() << "ns";
    qDebug() << " Avg Time Elapsed: " << timerWindowing/counterWindowing << "ns" << "Counter: " << counterWindowing;
}

void MainWindow::calculateDepthBuffer() {
    
}


