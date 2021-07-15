#ifndef TRACK_H
#define TRACK_H

#include "element.h"

class Track : public Element
{
public:
    Track(QVector<QPoint> &fromPoints);
    void paint(QPainter &painter) override;
private:
    QVector<QPoint> points;
};

#endif // TRACK_H
