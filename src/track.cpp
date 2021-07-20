#include "track.h"

#include <math.h>

#include <QLineF>

Track::Track(QVector<QPointF> &points)
{
    if (points.size() < 3) {
        return;
    }
    double factor = 0.25;
    path.moveTo(points.at(0));
    QPointF cp1;
    for (int i = 1; i < points.size() -1; i++) {
        auto previous = points.at(i - 1);
        auto current = points.at(i);
        auto next = points.at(i + 1);
        auto source = QLineF(previous, current);
        auto target = QLineF(current, next);
        auto targetAngle = target.angleTo(source);
        qreal angle;
        if (targetAngle > 180) {
            angle = fmod((source.angle() + source.angleTo(target) / 2), 360);
        } else {
            angle = fmod((target.angle() + target.angleTo(source) / 2), 360);
        }
        auto revTarget = QLineF::fromPolar(source.length() * factor, angle + 180).translated(current);
        auto cp2 = revTarget.p2();
        if (i == 1) {
            path.quadTo(cp2, current);
        } else {
            path.cubicTo(cp1, cp2, current);
        }
        auto revSource = QLineF::fromPolar(target.length() * factor, angle).translated(current);
        cp1 = revSource.p2();
    }
    path.quadTo(cp1, points.at(points.size() -1));
}

void Track::paint(QPainter &painter)
{
    painter.drawPath(path);
}
