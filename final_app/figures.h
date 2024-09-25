#ifndef FIGURES_H
#define FIGURES_H

#include "figure.h"

class Triangle : public Figure
{
public:
    Triangle(const QPoint& p1, const QPoint& p2, const QPoint& p3);
    void draw(QPainter& painter) override;

private:
    QPoint p1, p2, p3;
};

class Circle : public Figure
{
public:
    Circle(const QPoint& center, int radius);
    void draw(QPainter& painter) override;

private:
    QPoint center;
    int radius;
};

class Rectangle : public Figure
{
public:
    Rectangle(const QPoint& topLeft, int width, int height);
    void draw(QPainter& painter) override;

private:
    QPoint topLeft;
    int width, height;
};

#endif // FIGURES_H
