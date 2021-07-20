#include "renderer.h"

#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QMouseEvent>

#include "track.h"

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
    return QSize(800, 600);
}

void Renderer::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    for (auto& element : elements) {
        painter.save();
        element->paint(painter);
        painter.restore();
    }
    for (auto& point : points) {
        painter.drawPoint(point);
    }
}

void Renderer::mousePressEvent(QMouseEvent* e)
{
    QWidget::mousePressEvent(e);
}

void Renderer::mouseMoveEvent(QMouseEvent *e)
{
    points.append(e->pos());
    update();
    QWidget::mouseMoveEvent(e);
}

void Renderer::mouseReleaseEvent(QMouseEvent *e)
{
    QSharedPointer<Element> element(new Track(points));
    elements.append(element);
    points.clear();
    update();
    QWidget::mouseReleaseEvent(e);
}
