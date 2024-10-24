//
// Created by christian on 16.10.24.
//

#include "CTImage.h"

CTImage::CTImage(int width, int height, int depth) {
    this->width_ = width;
    this->height_ = height;
    this->depth_ = depth;
    this->size_ = width * height * depth;
    this->data_ = new short[this->size_];
}
CTImage::~CTImage() {
   // delete[] this->data_;
}


int CTImage::readImage(const QString &filepath) const {
    QFile dataFile(filepath);
    const size_t numBytes = this->size_ * 12/8;
    if (!dataFile.open(QIODevice::ReadOnly))
    {
        // Could not open Image
        return 1;
    }
    std::vector<unsigned char> buffer(numBytes);

    if (dataFile.size() != dataFile.read(reinterpret_cast<char *>(data_), 512*512*sizeof(short)))
    {
        // Could not read the whole file
        return 2;
    }
    dataFile.close();
    return 0;
}
QImage CTImage::toQImage(const int center, const int width) const {
    constexpr QImage::Format format = QImage::Format_Grayscale8;
    QImage image(this->width_, this->height_, format);
    image.fill(Qt::black);
    for (int i = 0; i < this->height_; i++) {
        for (int j = 0; j < this->width_; j++) {
            const int index = i*this->width_ + j;
            const int value = CTImage::applyWindow(data_[index], center, width);
            // Set the pixel value
            image.setPixel(j, i, qRgb(value, value, value));
        }
    }
    return image;
}

QImage CTImage::get2DImage_8bit() const {
    // Annahme. Bilddaten sind nur 2D: z=1

    constexpr QImage::Format format = QImage::Format_Grayscale8;
    QImage image(this->width_, this->height_, format);
    image.fill(Qt::black);
    for (int i = 0; i < this->height_; i++) {
        for (int j = 0; j < this->width_; j++) {
            const int index = i*this->width_ + j;
            const char value = this->data_[index];
            // Set the pixel value
            image.setPixel(j, i, qRgb(value, value, value));
        }
    }
    return image;
}
QImage CTImage::get2DImage(int center, int width) const {
    // Annahme: Bilddaten sind nur 2D: z=1
    constexpr QImage::Format format = QImage::Format_Grayscale8;
    QImage image(this->width_, this->height_, format);
    image.fill(Qt::black);
    for (int i = 0; i < this->height_; i++) {
        for (int j = 0; j < this->width_; j++) {
            const int index = i*this->width_ + j;
            const int value = CTImage::applyWindow(data_[index], center, width);
            // Set the pixel value
            image.setPixel(j, i, qRgb(value, value, value));
        }
    }
    return image;
}
int CTImage::applyWindow(const int hu, const int windowCenter, const int windowWidth) {
    int new_hu;
    if (hu <= windowCenter - windowWidth/2) {
        new_hu = 0;
    } else if (hu >= windowCenter + windowWidth/2) {
        new_hu = 255;
    } else {
        new_hu = 255 * (hu - windowCenter + windowWidth/2) / windowWidth;
    }
    return new_hu;

}
int CTImage::applyWindow_minmax(const int hu, const int min, const int max) {
    return applyWindow(hu, max+min/2, max-min);
}
