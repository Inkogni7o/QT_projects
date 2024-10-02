#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMenu>
#include <memory>

#include "figure.h"
#include "figures.h"

class paintWidget : public QWidget
{
public:
    paintWidget(QWidget *parent);
    virtual ~paintWidget();
    QPainter *painter_p;
    std::list<std::unique_ptr<Figure>> figures;
    Figure* draggedFigure = nullptr;
    QPoint dragOffset;
    Figure* selectedFigure;

public slots:
    void deleteFigure();
    void addTriangle();
    void addCircle();
    void addRectangle();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    QMenu *contextMenu;
    QMenu *contextMenu1;
};

#endif // PAINTWIDGET_H
