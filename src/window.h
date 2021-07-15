#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "renderer.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

private:
    Renderer *renderer;
};

#endif // WINDOW_H
