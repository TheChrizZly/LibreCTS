//
// Created by christian on 24.10.24.
//

#include "mainwindow.h"
#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow), currentImage(512, 512, 1) {
    ui->setupUi(this);
    ui->windowingCenterValue->setValidator(new QIntValidator(-1024, 3095, this));
    ui->windowingWidthValue->setValidator(new QIntValidator(1, 2059, this));
    connect(ui->loadImageButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->windowCenterSlider, &QSlider::valueChanged, this, &MainWindow::updateWindowing);
    connect(ui->windowWidthSlider, &QSlider::valueChanged, this, &MainWindow::updateWindowing);
    connect(ui->windowingCenterValue, &QLineEdit::editingFinished, [this]() {
        ui->windowCenterSlider->setValue(ui->windowingCenterValue->text().toInt());
    });
    connect(ui->windowingWidthValue, &QLineEdit::editingFinished, [this]() {
        ui->windowWidthSlider->setValue(ui->windowingWidthValue->text().toInt());
    });
}

MainWindow::~MainWindow() {
    delete ui;
}
void MainWindow::loadImage() {
    const QString fileName = QFileDialog::getOpenFileName(this, "Open Image", QCoreApplication::applicationDirPath(), "Image Files (*.raw)");
    const CTImage ctImage(512, 512, 1);
    if(int res = ctImage.readImage(fileName)) {
        ErrorHandler errorHandler;
        errorHandler.handleError(static_cast<ErrorCode>(res));
        return;
    }
    currentImage = ctImage;
    ui->drawingArea->setImage(QPixmap::fromImage(ctImage.get2DImage(0, 800)));
}

void MainWindow::updateWindowing() const {
    if(ui->windowingCheckbox->isChecked()) {
        // 1. Get current windowing values
        const int windowCenter = ui->windowCenterSlider->value();
        const int windowWidth = ui->windowWidthSlider->value();
        ui->windowingCenterValue->setText(QString::number(windowCenter));
        ui->windowingWidthValue->setText(QString::number(windowWidth));
        // 2. Update the image in the viewer
        ui->drawingArea->setImage(QPixmap::fromImage(currentImage.get2DImage(windowCenter, windowWidth)));
    }
}

