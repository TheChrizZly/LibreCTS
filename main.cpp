#include <QApplication>
#include "src/ui/mainwindow.h"
#undef slots
#include <torch/torch.h>
#define slots Q_SLOTS
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}