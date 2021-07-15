#include "window.h"

#include <QtWidgets>

Window::Window()
{
    renderer = new Renderer;
    
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(renderer, 0, 0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);
    setWindowTitle("AdBoard");
}
