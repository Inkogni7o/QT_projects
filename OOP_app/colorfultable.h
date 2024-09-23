#ifndef COLORFULTABLE_H
#define COLORFULTABLE_H

#include <QTableWidget>
#include <QPainter>
#include <QColor>
#include <QRandomGenerator>

class ColorfulTable : public QTableWidget
{
public:
    ColorfulTable(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // COLORFULTABLE_H
