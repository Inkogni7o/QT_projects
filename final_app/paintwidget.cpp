#include "paintwidget.h"

#include <QDebug>

paintWidget::paintWidget (QWidget *parent) : QWidget(parent) {
    setMouseTracking(true);
    figures.push_back(std::make_unique<Triangle>(QPoint(50, 50), QPoint(150, 150), QPoint(250, 50)));
    figures.push_back(std::make_unique<Circle>(QPoint(100, 250), 75));
    figures.push_back(std::make_unique<Rectangle>(QPoint(50, 350), 100, 200));

    contextMenu = new QMenu(this);
    QAction *action1 = new QAction(tr("Удалить"), this);
    contextMenu->addAction(action1);
    connect(action1, &QAction::triggered, this, &paintWidget::deleteFigure);
}

paintWidget::~paintWidget() {}

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
    if (draggedFigure != nullptr) {
        draggedFigure->setPosition(event->pos() - dragOffset);
        draggedFigure->setColor(Qt::blue);
    } else {
        for (const auto& figure : figures) {
            if (figure->isCursorInside( event->pos() )) {
                figure->setColor(Qt::red);
            } else {
                figure->setColor(Qt::green);
            }
        }
    }
    this->update();
}

void paintWidget::deleteFigure() {
    for (auto figure = figures.begin(); figure != figures.end(); ++figure) {
        if (figure->get() == selectedFigure) {
            figures.erase(figure);
        }
    }
    update();
}


void paintWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        for (const auto& figure : figures) {
            if (figure->isCursorInside(event->pos())) {
                draggedFigure = figure.get();
                dragOffset = event->pos() - figure->getPosition();
                break;
            }
        }
    } else if (event->button() == Qt::MiddleButton) {
        for (const auto& figure : figures) {
            if (figure->isCursorInside( event->pos() )) {
                QMessageBox::information(NULL, QObject::tr("Информация о фигуре"),
                                         QObject::tr((figure->getText()).c_str()));
            }
        }
    }
    if (event->button() == Qt::RightButton) {
        for (const auto& figure : figures) {
            if (figure->isCursorInside( event->pos() )) {
                contextMenu->popup(mapToGlobal(event->pos()));
                selectedFigure = figure.get();
            }
        }
    }
    this->update();
}

void paintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && draggedFigure != nullptr) {
        draggedFigure = nullptr;
        this->update();
    }
}

