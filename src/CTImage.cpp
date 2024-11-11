//
// Created by christian on 16.10.24.
//

#include "CTImage.h"

CTImage::~CTImage() {
   // delete[] this->data_;
}


int CTImage::readImage(const QString &filepath, const size_t height, const size_t width, const size_t depth) {
    // Update Image variables
    height_=height;
    width_=width;
    depth_=depth;
    size_=height*width*depth;
    data_ = new short[size_];
    depthMap_ = new short[height_*width_];

    QFile dataFile(filepath); // Open the datastream

    // Open File and check if file can be accessed
    if (!dataFile.open(QIODevice::ReadOnly))
    {
        // Could not open Image
        return 1;
    }
    // Read the file and check if the filesize matches the expected filesize
    if (dataFile.size() != dataFile.read(reinterpret_cast<char *>(data_), size_*sizeof(short)))
    {
        // Could not read the whole file
        return 2;
    }
    dataFile.close(); // Close the datastream

    return 0; // Image was read successfully

}
QImage CTImage::toQImage() const {
    // Directly set the pixel values in the image data instead of using setPixel (Run time ~ 1/4 of naive approach)
    // For naive approach: Check toQImage_unoptimized
    // Annahme: Bilddaten sind nur 2D: z=1
    constexpr QImage::Format format = QImage::Format_RGB32;
    // Create a 2D QImage and fill it black
    QImage image(this->width_, this->height_, format);
    image.fill(Qt::black);

    uchar* bits = image.bits(); // Get a pointer to the raw image data
    // Iterate over each pixel in the image
    int greyvalue;
    constexpr uchar mask[] = {255, 0, 255, 255}; // Magenta with full alpha
    // parallelization only slighty faster :(
    // Changing the order of the loops does not improve performance
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < this->height_; i++) {
        for (int j = 0; j < this->width_; j++) {
            const int index = i * this->height_ + j + height_*width_*currentLayer_; // Define voxel location in the dataArray
            if (segmentationActive_ && data_[index] > segmentationThreshold_) {
                // Set the RGB Mask values
                *bits++ = mask[0]; // Red
                *bits++ = mask[1]; // Green
                *bits++ = mask[2]; // Blue
                *bits++ = mask[3]; // Alpha (transparency)
            } else {
                applyWindow(data_[index], currentWindowingCenter_, currentWindowingWidth_, greyvalue); // Apply windowing function
                // Set the pixel value to greyscale
                *bits++ = static_cast<uchar>(greyvalue); // Red
                *bits++ = static_cast<uchar>(greyvalue); // Green
                *bits++ = static_cast<uchar>(greyvalue); // Blue
                *bits++ = static_cast<uchar>(255); // Alpha (transparency)
            }
        }
    }
    return image;
}

QImage CTImage::toQImage_unoptimized(const int center, const int width) const {
    // unoptimized, naive approach. uses Qt functions to get the value one by one
    constexpr QImage::Format format = QImage::Format_Grayscale8;
    QImage image(this->width_, this->height_, format);
    image.fill(Qt::black);
    int greyvalue;
    for (int i = 0; i < this->height_; i++) {
        for (int j = 0; j < this->width_; j++) {
            const int index = i*this->width_ + j;
            applyWindow(data_[index], center, width, greyvalue);
            // Set the pixel value
            image.setPixel(j, i, qRgb(greyvalue, greyvalue, greyvalue));
        }
    }
    return image;
}

QImage CTImage::get2DImage_8bit() const {
    // Used for 8bit images. Not used anymore. May be used if 8-bit images are needed again
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
QImage CTImage::get2DImage(const int center, const int width) const {
    // Naming was unconvenient. Replaced by toQImage
    // Annahme: Bilddaten sind nur 2D: z=1
    constexpr QImage::Format format = QImage::Format_Grayscale8;
    QImage image(this->width_, this->height_, format);
    image.fill(Qt::black);
    int greyvalue;
    for (int i = 0; i < this->height_; i++) {
        for (int j = 0; j < this->width_; j++) {
            const int index = i*this->width_ + j;
            const int value = applyWindow(data_[index], center, width, greyvalue);
            // Set the pixel value
            image.setPixel(j, i, qRgb(greyvalue, greyvalue, greyvalue));
        }
    }
    return image;
}

int CTImage::applyWindow(const int hu, const int windowCenter, const int windowWidth, int& greyValue) {
    if (hu <= windowCenter - windowWidth/2) {
        greyValue = 0;
    } else if (hu >= windowCenter + windowWidth/2) {
        greyValue = 255;
    } else {
        greyValue = 255 * (hu - windowCenter + windowWidth/2) / windowWidth;
    }
    //success
    return 0;
}

int CTImage::calculateDepthBuffer() {

}
//int CTImage::applyWindow_minmax(const int hu, const int min, const int max) {
    //return applyWindow(hu, max+min/2, max-min);
//}
