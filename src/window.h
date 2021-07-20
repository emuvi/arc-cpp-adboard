#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>

#include "renderer.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
    void resizeEvent(QResizeEvent *) override;

private:
    Renderer *renderer;
    QPushButton *menu;
};

#endif // WINDOW_H
