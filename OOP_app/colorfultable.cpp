#include "colorfultable.h"

ColorfulTable::ColorfulTable(QWidget *parent) : QTableWidget(parent) {}

void ColorfulTable::paintEvent(QPaintEvent *event) {
    QPainter painter(viewport());

    for (int row = 0; row < rowCount(); ++row) {
        for (int col = 0; col < columnCount(); ++col) {
            QTableWidgetItem *item = this->item(row, col);
            if (item) {
                painter.save();
//                painter.translate(this->cellRect(row, col).topLeft());
//                painter.setPen(Qt::black);

                painter.setPen(QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                                               QRandomGenerator::global()->bounded(256),
                                               QRandomGenerator::global()->bounded(256)));

                painter.drawText(QRect(0, 0, columnWidth(col), rowHeight(row)), Qt::AlignCenter, item->text());
                painter.restore();
            }
        }
    }
}
