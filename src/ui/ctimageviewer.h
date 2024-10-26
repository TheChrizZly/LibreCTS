//
// Created by christian on 24.10.24.
//

#ifndef CTIMAGEVIEWER_H
#define CTIMAGEVIEWER_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPixmap>
#include "../CTImage.h"

class CTImageViewer final : public QLabel {
    Q_OBJECT

public:
    explicit CTImageViewer(QWidget *parent = nullptr): originalPixmap(new QPixmap) {}
    void setImage(const QPixmap &pixmap) {
        //Slightly faster than swapping the content
        originalPixmap = std::make_unique<QPixmap>(pixmap);
        setPixmap(pixmap);

       // QPixmap newPixmap(pixmap); // Create a temporary pixmap
       // originalPixmap->swap(newPixmap); // Swap contents efficiently
       // setPixmap(pixmap);
    }
protected:
    void resizeEvent(QResizeEvent *event) override {
        {
            const int size = qMin(width(), height());
            resize(size, size);

            if (!pixmap().isNull()) {
                const QPixmap scaledPixmap = originalPixmap->scaled(QSize(size, size), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                setPixmap(scaledPixmap);
            }
        }
    }

private:
    std::unique_ptr<QPixmap> originalPixmap;};


#endif //CTIMAGEVIEWER_H
