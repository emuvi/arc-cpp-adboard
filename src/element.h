#ifndef ELEMENT_H
#define ELEMENT_H

#include <QPainter>

class Element
{
public:
    virtual ~Element(){};
    virtual void paint(QPainter &) = 0;

};

#endif // ELEMENT_H
