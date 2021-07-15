#ifndef RENDERER_H
#define RENDERER_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include "element.h"

class Renderer : public QWidget
{
    Q_OBJECT

public:
    explicit Renderer(QWidget *parent = nullptr);
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

private:
    QVector<QSharedPointer<Element>> elements;
    QVector<QPoint> points;
};

#endif // RENDERER_H
