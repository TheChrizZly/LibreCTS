//
// Created by christian on 16.10.24.
//

#ifndef CTIMAGE_H
#define CTIMAGE_H

#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QImage>

class CTImage {
public:
    CTImage(int width, int height, int depth);
    ~CTImage();
    int readImage(const QString &filepath) const;
    [[nodiscard]] QImage toQImage(int center,int  width) const;
    [[nodiscard]] QImage get2DImage(int center, int width) const;
    [[nodiscard]] QImage get2DImage_8bit() const;

    static int applyWindow(int hu, int windowCenter, int windowWidth);

    static int applyWindow_minmax(int hu, int min, int max);
private:
    int width_;
    int height_;
    int depth_;
    int size_;

    short *data_;

};



#endif //CTIMAGE_H
