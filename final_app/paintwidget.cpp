#include "paintwidget.h"

paintWidget::paintWidget (QWidget *parent) : QWidget(parent) {
    figures.push_back(new Triangle(QPoint(50, 50), QPoint(150, 150), QPoint(250, 50)));
    figures.push_back(new Circle(QPoint(100, 250), 75));
    figures.push_back(new Rectangle(QPoint(50, 350), 100, 200));
};

paintWidget::~paintWidget() {
}

void paintWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 5));
    for (Figure* figure : figures) {
        figure->draw(painter);
    }
}
