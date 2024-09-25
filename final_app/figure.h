#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>

class Figure
{
public:
    Figure();
    ~Figure();
    virtual void draw(QPainter& painter) = 0;
};

#endif // FIGURE_H
