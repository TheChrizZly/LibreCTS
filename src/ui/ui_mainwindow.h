/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ctimageviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    CTImageViewer *drawingArea;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *leftLoadImageButtonSpacer;
    QPushButton *loadImageButton;
    QSpacerItem *rightLoadImageButtonSpacer;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *layerSpacerUp;
    QLabel *layerLabel;
    QLineEdit *layerValue;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QSlider *layerSlider;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *layerSpaceDown;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *windowingCheckbox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *windowCenterLabel;
    QLineEdit *windowingCenterValue;
    QSlider *windowCenterSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *windowWidthLabel;
    QLineEdit *windowingWidthValue;
    QSlider *windowWidthSlider;
    QSpacerItem *windowingSliderSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        drawingArea = new CTImageViewer(centralwidget);
        drawingArea->setObjectName("drawingArea");
        drawingArea->setMinimumSize(QSize(512, 512));
        drawingArea->setScaledContents(true);

        horizontalLayout_2->addWidget(drawingArea);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        leftLoadImageButtonSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(leftLoadImageButtonSpacer);

        loadImageButton = new QPushButton(centralwidget);
        loadImageButton->setObjectName("loadImageButton");

        horizontalLayout_3->addWidget(loadImageButton);

        rightLoadImageButtonSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(rightLoadImageButtonSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 12);
        verticalLayout->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        layerSpacerUp = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(layerSpacerUp);

        layerLabel = new QLabel(centralwidget);
        layerLabel->setObjectName("layerLabel");

        verticalLayout_4->addWidget(layerLabel);

        layerValue = new QLineEdit(centralwidget);
        layerValue->setObjectName("layerValue");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(layerValue->sizePolicy().hasHeightForWidth());
        layerValue->setSizePolicy(sizePolicy);
        layerValue->setMaximumSize(QSize(40, 16777215));
        layerValue->setCursor(QCursor(Qt::CursorShape::IBeamCursor));
        layerValue->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        layerValue->setMaxLength(3);
        layerValue->setFrame(false);
        layerValue->setEchoMode(QLineEdit::EchoMode::Normal);
        layerValue->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(layerValue);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        layerSlider = new QSlider(centralwidget);
        layerSlider->setObjectName("layerSlider");
        layerSlider->setMinimum(1);
        layerSlider->setMaximum(1);
        layerSlider->setOrientation(Qt::Orientation::Vertical);
        layerSlider->setInvertedAppearance(true);

        horizontalLayout_7->addWidget(layerSlider);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_7);

        layerSpaceDown = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(layerSpaceDown);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        windowingCheckbox = new QCheckBox(centralwidget);
        windowingCheckbox->setObjectName("windowingCheckbox");

        verticalLayout_3->addWidget(windowingCheckbox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        windowCenterLabel = new QLabel(centralwidget);
        windowCenterLabel->setObjectName("windowCenterLabel");

        horizontalLayout_5->addWidget(windowCenterLabel);

        windowingCenterValue = new QLineEdit(centralwidget);
        windowingCenterValue->setObjectName("windowingCenterValue");
        windowingCenterValue->setMaxLength(4);

        horizontalLayout_5->addWidget(windowingCenterValue);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_5);

        windowCenterSlider = new QSlider(centralwidget);
        windowCenterSlider->setObjectName("windowCenterSlider");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(windowCenterSlider->sizePolicy().hasHeightForWidth());
        windowCenterSlider->setSizePolicy(sizePolicy1);
        windowCenterSlider->setMinimum(-1024);
        windowCenterSlider->setMaximum(3095);
        windowCenterSlider->setValue(0);
        windowCenterSlider->setSliderPosition(0);
        windowCenterSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_3->addWidget(windowCenterSlider);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        windowWidthLabel = new QLabel(centralwidget);
        windowWidthLabel->setObjectName("windowWidthLabel");

        horizontalLayout_6->addWidget(windowWidthLabel);

        windowingWidthValue = new QLineEdit(centralwidget);
        windowingWidthValue->setObjectName("windowingWidthValue");
        windowingWidthValue->setMaxLength(4);

        horizontalLayout_6->addWidget(windowingWidthValue);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_6);

        windowWidthSlider = new QSlider(centralwidget);
        windowWidthSlider->setObjectName("windowWidthSlider");
        windowWidthSlider->setMaximum(2059);
        windowWidthSlider->setValue(800);
        windowWidthSlider->setSliderPosition(800);
        windowWidthSlider->setOrientation(Qt::Orientation::Horizontal);
        windowWidthSlider->setTickPosition(QSlider::TickPosition::NoTicks);

        verticalLayout_3->addWidget(windowWidthSlider);

        windowingSliderSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(windowingSliderSpacer);


        verticalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        drawingArea->setText(QString());
        loadImageButton->setText(QCoreApplication::translate("MainWindow", "load Image", nullptr));
        layerLabel->setText(QCoreApplication::translate("MainWindow", "Layer", nullptr));
        layerValue->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        windowingCheckbox->setText(QCoreApplication::translate("MainWindow", "Windowing", nullptr));
        windowCenterLabel->setText(QCoreApplication::translate("MainWindow", "Windowing Center", nullptr));
        windowingCenterValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        windowWidthLabel->setText(QCoreApplication::translate("MainWindow", "Windowing Width", nullptr));
        windowingWidthValue->setText(QCoreApplication::translate("MainWindow", "800", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
