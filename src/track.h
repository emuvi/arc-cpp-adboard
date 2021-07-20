#ifndef TRACK_H
#define TRACK_H

#include "element.h"

#include <QPainterPath>

class Track : public Element
{
public:
    Track(QVector<QPointF> &points);
    void paint(QPainter &painter) override;
private:
    QPainterPath path;
};

#endif // TRACK_H
