#include "figures.h"

Triangle::Triangle(const QPoint& p1, const QPoint& p2, const QPoint& p3)
    : p1(p1), p2(p2), p3(p3) {}

void Triangle::draw(QPainter& painter)
{
    painter.drawPolygon(QPolygon() << p1 << p2 << p3);
}

void Triangle::setColor(QColor color){
    this->color = color;
}

QColor Triangle::getColor() {
    return this->color;
}

bool Triangle::isCursorInside(const QPoint& cursorPos) {
    double s = (p2.y() - p1.y()) * (p3.x() - p1.x()) - (p2.x() - p1.x()) * (p3.y() - p1.y());
    double s1 = (p2.y() - cursorPos.y()) * (p3.x() - cursorPos.x()) - (p2.x() - cursorPos.x()) * (p3.y() - cursorPos.y());
    double s2 = (cursorPos.y() - p1.y()) * (p3.x() - p1.x()) - (cursorPos.x() - p1.x()) * (p3.y() - p1.y());
    double s3 = (p2.y() - p1.y()) * (cursorPos.x() - p1.x()) - (p2.x() - p1.x()) * (cursorPos.y() - p1.y());

    if (s1 * s >= 0 && s2 * s >= 0 && s3 * s >= 0) {
        return true;
    } return false;
}

std::string Triangle::getText()
{
    std::string text1 = "Информация о треугольнике \n\n";
    std::string text2 = "Первая точка => " + std::to_string(p1.x())
            + "; " + std::to_string(p1.y()) + "\n";
    std::string text3 = "Вторая точка => " + std::to_string(p2.x())
            + "; " + std::to_string(p2.y()) + "\n";
    std::string text4 = "Третья точка => " + std::to_string(p3.x())
            + "; " + std::to_string(p3.y()) + "\n";

    std::string text = text1 + text2 + text3 + text4;
    return text;
}



Circle::Circle(const QPoint& center, int radius)
    : center(center), radius(radius) {}

void Circle::draw(QPainter& painter)
{
    painter.drawEllipse(center, radius, radius);
}

void Circle::setColor(QColor color){
    this->color = color;
}

QColor Circle::getColor() {
    return this->color;
}

bool Circle::isCursorInside(const QPoint& cursorPos) {
    return ( sqrt(pow(cursorPos.x() - center.x(), 2) +
                  pow(cursorPos.y() - center.y(), 2)) <= radius );
}

std::string Circle::getText()
{
    std::string text1 = "Информация об окружности \n\n";
    std::string text2 = "Центр => " + std::to_string(center.x())
            + "; " + std::to_string(center.y()) + "\n";
    std::string text3 = "Радиус => " + std::to_string(radius);

    std::string text = text1 + text2 + text3;
    return text;
}



Rectangle::Rectangle(const QPoint& topLeft, int width, int height)
    : topLeft(topLeft), width(width), height(height) {}

void Rectangle::draw(QPainter& painter)
{
    painter.drawRect(topLeft.x(), topLeft.y(), width, height);
}

void Rectangle::setColor(QColor color){
    this->color = color;
}

QColor Rectangle::getColor() {
    return this->color;
}

bool Rectangle::isCursorInside(const QPoint& cursorPos) {
    return (cursorPos.x() >= topLeft.x() && cursorPos.x() <= topLeft.x() + width &&
      cursorPos.y() >= topLeft.y()  && cursorPos.y() <= topLeft.y() + height);
}

std::string Rectangle::getText()
{
    std::string text1 = "Информация о прямоугольнике \n\n";
    std::string text2 = "Левая верхняя точка => " + std::to_string(topLeft.x())
            + "; " + std::to_string(topLeft.y()) + "\n";
    std::string text3 = "Ширина => " + std::to_string(width) + "\n";
    std::string text4 = "Высота => " + std::to_string(height);

    std::string text = text1 + text2 + text3 + text4;
    return text;
}
