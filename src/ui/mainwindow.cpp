//
// Created by christian on 24.10.24.
//

#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow), currentImage(512, 512, 1) {
    ui->setupUi(this);
    connect(ui->loadImageButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->windowCenterSlider, &QSlider::valueChanged, this, &MainWindow::updateWindowing);
    connect(ui->windowWidthSlider, &QSlider::valueChanged, this, &MainWindow::updateWindowing);
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::loadImage() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", QCoreApplication::applicationDirPath(), "Image Files (*.raw)");
    CTImage ctImage(512, 512, 1);
    if(int res = ctImage.readImage(fileName)) {
        ErrorHandler errorHandler;
        errorHandler.handleError(static_cast<ErrorCode>(res));
        return;
    }
    currentImage = ctImage;
    ui->drawingArea->setImage(QPixmap::fromImage(ctImage.get2DImage(0, 800)));
}

void MainWindow::updateWindowing() {
    if(ui->windowingCheckbox->isChecked()) {
        // 1. Get current windowing values
        int windowCenter = ui->windowCenterSlider->value();
        int windowWidth = ui->windowWidthSlider->value();
        // 2. Update the image in the viewer
        ui->drawingArea->setImage(QPixmap::fromImage(currentImage.get2DImage(windowCenter, windowWidth)));
    }
}

