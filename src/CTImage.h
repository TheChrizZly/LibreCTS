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
    struct CTImageDims {
        size_t width_;
        size_t height_;
        size_t depth_;
    };
    CTImage() : height_(0), width_(0), depth_(0), size_(0), currentWindowingCenter_(0), currentWindowingWidth_(800), currentLayer_(1), data_(nullptr) {}
    ~CTImage();

    void setWindowingParameters(const int windowCenter, const int windowWidth) {currentWindowingCenter_ = windowCenter; currentWindowingWidth_ = windowWidth;}
    void setLayer(const int layer){currentLayer_ = layer;}
    [[nodiscard]] CTImageDims getImageDims() const {return {height_, width_, depth_};}
    [[nodiscard]] int getLayer() const {return currentLayer_;}

    int readImage(const QString &filepath, size_t height=0, size_t width=0, size_t depth=0);
    [[nodiscard]] QImage toQImage() const;

    // Depreciated Functions: To be removed
    [[nodiscard]] QImage get2DImage(int center, int width) const;
    [[nodiscard]] QImage get2DImage_8bit() const;
    [[nodiscard]] QImage toQImage_unoptimized(int center, int width) const;

    static int applyWindow(int hu, int windowCenter, int windowWidth);

    static int applyWindow_minmax(int hu, int min, int max);
private:
    size_t height_;
    size_t width_;
    size_t depth_;
    size_t size_;
    int currentWindowingCenter_;
    int currentWindowingWidth_;
    int currentLayer_;

    short *data_;

};



#endif //CTIMAGE_H
