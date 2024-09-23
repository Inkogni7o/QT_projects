#include "ColoredTextBrowser.h"
#include <QTextDocument>
#include <QTextCursor>
#include <QTextCharFormat>
#include <QRandomGenerator>


ColoredTextBrowser::ColoredTextBrowser(QWidget *parent) : QTextBrowser(parent) {}

void ColoredTextBrowser::printText(QString text) {
    QTextCharFormat format;
        format.setForeground(QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                                            QRandomGenerator::global()->bounded(256),
                                            QRandomGenerator::global()->bounded(256)));

        QTextCursor cursor = this->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.insertText(text, format);
        cursor.insertBlock();

        this->setTextCursor(cursor);
}
