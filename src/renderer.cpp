#include "renderer.h"

#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QMouseEvent>

//! [0]
Renderer::Renderer(QWidget *parent)
    : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize Renderer::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize Renderer::sizeHint() const
{
    return QSize(400, 200);
}

void Renderer::paintEvent(QPaintEvent * /* event */)
{
    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    for (int x = 0; x < width(); x += 100) {
        for (int y = 0; y < height(); y += 100) {
            painter.save();
            painter.translate(x, y);
            painter.drawPath(path);
            painter.restore();
        }
    }

    for (auto point : points) {
        painter.drawPoint(point);
    }
}

void Renderer::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "Press";
    QWidget::mousePressEvent(e);
}

void Renderer::mouseMoveEvent(QMouseEvent *e)
{
    points.append(e->pos());
    qDebug() << "Move: " << e->pos();
    update();
    QWidget::mouseMoveEvent(e);
}

void Renderer::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug() << "Release";
    QWidget::mouseReleaseEvent(e);
}
