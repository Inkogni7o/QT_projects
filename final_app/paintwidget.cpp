#include "paintwidget.h"

#include <QDebug>

paintWidget::paintWidget (QWidget *parent) : QWidget(parent) {
    setMouseTracking(true);
    figures.push_back(std::make_unique<Triangle>(QPoint(50, 50), QPoint(150, 150), QPoint(250, 50)));
    figures.push_back(std::make_unique<Circle>(QPoint(100, 250), 75));
    figures.push_back(std::make_unique<Rectangle>(QPoint(50, 350), 100, 200));
};

paintWidget::~paintWidget() {
}

void paintWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    for (const auto& figure : figures) {
        painter.setPen(QPen(figure->getColor(), 5));
        figure->draw(painter);
    }
}

void paintWidget::mouseMoveEvent(QMouseEvent* event)
{

    for (const auto& figure : figures) {
        if (figure->isCursorInside( event->pos() )) {
            figure->setColor(Qt::red);
        } else {
            figure->setColor(Qt::green);
        }
    }
    this->update();
}

void paintWidget::mousePressEvent(QMouseEvent * event)
{
    for (const auto& figure : figures) {
        if (figure->isCursorInside( event->pos() )) {
            QMessageBox::information(NULL, QObject::tr("Информация о фигуре"),
                                     QObject::tr((figure->getText()).c_str()));
        }
    }
     this->update();
}
