#include "window.h"

#include <QtWidgets>
#include <QDebug>

Window::Window()
{
    renderer = new Renderer;
    menu = new QPushButton("Menu");

    renderer->setParent(this);
    renderer->move(0, 0);
    renderer->resize(this->size());
    renderer->show();

    menu->setParent(this);
    menu->move(30, 30);
    menu->resize(90, 30);
    menu->show();

    setWindowTitle("AdBoard");
}

void Window::resizeEvent(QResizeEvent *e)
{
    renderer->resize(e->size());
}
