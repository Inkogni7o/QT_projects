#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
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

protected:
    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // PAINTWIDGET_H
