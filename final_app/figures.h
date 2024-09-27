#ifndef FIGURES_H
#define FIGURES_H

#include "figure.h"

class Triangle : public Figure
{
public:
    Triangle(const QPoint& p1, const QPoint& p2, const QPoint& p3);
    void draw(QPainter& painter) override;
    virtual bool isCursorInside(const QPoint& cursorPos) override;
    virtual void setColor(QColor color) override;
    virtual QColor getColor() override;
    virtual std::string getText() override;
    virtual QPoint getPosition() override;
    virtual void setPosition(QPoint target) override;
    QPoint offset1;
    QPoint offset2;

private:
    QPoint p1, p2, p3;
};

class Circle : public Figure
{
public:
    Circle(const QPoint& center, int radius);
    void draw(QPainter& painter) override;
    virtual bool isCursorInside(const QPoint& cursorPos) override;
    virtual void setColor(QColor color) override;
    virtual QColor getColor() override;
    virtual std::string getText() override;
    virtual QPoint getPosition() override;
    virtual void setPosition(QPoint target) override;

private:
    QPoint center;
    int radius;
};

class Rectangle : public Figure
{
public:
    Rectangle(const QPoint& topLeft, int width, int height);
    void draw(QPainter& painter) override;
    virtual bool isCursorInside(const QPoint& cursorPos) override;
    virtual void setColor(QColor color) override;
    virtual QColor getColor() override;
    virtual std::string getText() override;
    virtual QPoint getPosition() override;
    virtual void setPosition(QPoint target) override;

private:
    QPoint topLeft;
    int width, height;
};

#endif // FIGURES_H
