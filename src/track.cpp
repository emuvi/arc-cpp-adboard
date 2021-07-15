#include "track.h"

#include <array>
#include <QPainterPath>

Track::Track(QVector<QPoint> &fromPoints)
{
    int index = 0;
    for (auto point : fromPoints) {
        if (index % 10 == 0) {
            points.append(point);
        }
        index++;
    }

}

void Track::paint(QPainter &painter)
{
    QPainterPath path;
    bool first = true;
    QPoint* previous;
    for (auto& point : points) {
        previous = &point;
        if (first) {
            path.moveTo(point);
            first = false;
        } else {
            QPointF average(previous->x() + ((point.x() - previous->x()) / 2),
                         previous->y() + ((point.y() - previous->y()) / 2));
            path.quadTo(average, point);
        }
    }
    painter.save();
    painter.drawPath(path);
    painter.restore();
}
