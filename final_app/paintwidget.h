#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>

#include "figure.h"
#include "figures.h"

class paintWidget : public QWidget
{
public:
    paintWidget(QWidget *parent);
    virtual ~paintWidget();
    QPainter *painter_p;
    std::list<Figure*> figures;

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // PAINTWIDGET_H
