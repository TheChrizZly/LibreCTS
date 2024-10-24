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
    explicit CTImageViewer(QWidget *parent = nullptr);
    void setImage(const QPixmap &pixmap) {
        originalPixmap = new QPixmap(pixmap); // Store a copy of the original
        setPixmap(pixmap);
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
    QPixmap *originalPixmap; // Store the original pixmap
};


#endif //CTIMAGEVIEWER_H
