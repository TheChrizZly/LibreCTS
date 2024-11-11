//
// Created by christian on 16.10.24.
//

#ifndef CTIMAGE_H
#define CTIMAGE_H

#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QImage>
#include <omp.h>


class CTImage {
public:
    struct CTImageDims {
        size_t width_;
        size_t height_;
        size_t depth_;
    };

    /**
     * Initializes all required variables
     * Size is initialized with dimensions (0,0,0)
     * Windowing is initialized with center 0 and width 800
     * Current Layer is initialized with 1, so it diesn't need to be updated when Image is loaded
     * Imagedata is initialized with a nullptr
     */
    CTImage() : height_(0), width_(0), depth_(0), size_(0), currentWindowingCenter_(0), currentWindowingWidth_(800), currentLayer_(0), segmentationActive_(0), segmentationThreshold_(0), data_(nullptr), depthMap_(nullptr) {}
    ~CTImage();

    /**
     *
     * @param windowCenter sets the Center of the Windowing
     * @param windowWidth sets the Width of the Windowing
     */
    void setWindowingParameters(const int windowCenter, const int windowWidth) {currentWindowingCenter_ = windowCenter; currentWindowingWidth_ = windowWidth;}

    /**
     *
     * @param layer sets the depth value for visualization
     */
    void setLayer(const int layer){currentLayer_ = layer;}

    void setSegmentationThreshold(const int threshold) {
     segmentationThreshold_ = threshold;
    }

    void setSegmentationActive(const int active) {
     segmentationActive_ = active;
    }
    /**
     *
     * @return Returns the Height, Width and Depth of the CT Image
     */
    [[nodiscard]] CTImageDims getImageDims() const {return {height_, width_, depth_};}

    /**
     *
     * @return Returns the currently visualized layer/depth value
     */
    [[nodiscard]] int getLayer() const {return currentLayer_;}

    /**
     * Function to read CT Data from a file and store it in the data_ variable
     * Dimensions of the data is needed as it is not given by the file
     * @param filepath The Filepath of the Image File as QString
     * @param height The height of the image
     * @param width The width of the image
     * @param depth The depth of the image. For 2D Images choose depth=1
     * @return Returns an Error Code for Error handling
     */
    int readImage(const QString &filepath, size_t height=0, size_t width=0, size_t depth=0);

    int calculateDepthBuffer();

    /**
     * Function to create a 2D QImage from the 3D CT Data.
     * Size parameters and currentLayer are used from the class variables and might need to be set before calling toQImage
     * @return 2D QImage from 3D Image Data
     */
    [[nodiscard]] QImage toQImage() const;

    //  Functions: To be removed
    [[deprecated]] [[nodiscard]] QImage get2DImage(int center, int width) const;
    [[deprecated]] [[nodiscard]] QImage get2DImage_8bit() const;
    [[deprecated]] [[nodiscard]] QImage toQImage_unoptimized(int center, int width) const;

private:
    size_t height_;
    size_t width_;
    size_t depth_;
    size_t size_;
    int currentWindowingCenter_;
    int currentWindowingWidth_;
    int currentLayer_;
    int segmentationThreshold_;
    int segmentationActive_;

    short *data_;
    short *depthMap_;

    /**
     * Internal function to apply the windowing on the Image
     * @param hu the HU value of the original image
     * @param windowCenter the Window Center of the Windowing
     * @param windowWidth the Window Width for the Windowing
     * @param greyValue reference to the Grayscale Value to visualize the data (0-255)
     * @return the Grayscale Value to visualize the data (0-255)
     */
    static int applyWindow(int hu, int windowCenter, int windowWidth, int& greyValue);

    /**
     * Internal function to apply the windowing on the Image
     * @param hu the HU value of the original image
     * @param min the minimum Value HU value to be in the Windowing
     * @param max the minimum Value HU value to be in the Windowing
     * @return the Grayscale Value to visualize the data (0-255)
     */
    static int applyWindow_minmax(int hu, int min, int max);
};



#endif //CTIMAGE_H
