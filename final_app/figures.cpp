#include "figures.h"

Triangle::Triangle(const QPoint& p1, const QPoint& p2, const QPoint& p3)
    : p1(p1), p2(p2), p3(p3) {}

void Triangle::draw(QPainter& painter)
{
    painter.drawPolygon(QPolygon() << p1 << p2 << p3);
}


Circle::Circle(const QPoint& center, int radius)
    : center(center), radius(radius) {}

void Circle::draw(QPainter& painter)
{
    painter.drawEllipse(center, radius, radius);
}

Rectangle::Rectangle(const QPoint& topLeft, int width, int height)
    : topLeft(topLeft), width(width), height(height) {}

void Rectangle::draw(QPainter& painter)
{
    painter.drawRect(topLeft.x(), topLeft.y(), width, height);
}
