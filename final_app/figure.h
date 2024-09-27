#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <memory>

class Figure
{
public:
    Figure();
    ~Figure();
    virtual void draw(QPainter& painter) = 0;
    virtual bool isCursorInside(const QPoint& cursorPos) = 0;
    virtual void setColor(QColor color) = 0;
    virtual QColor getColor() = 0;
    virtual std::string getText() = 0;
    virtual QPoint getPosition() = 0;
    virtual void setPosition(QPoint target) = 0;
protected:
    QColor color = Qt::green;
};

#endif // FIGURE_H
