#ifndef COLOREDTEXTBROWSER_H
#define COLOREDTEXTBROWSER_H

#include <QTextBrowser>
#include <QVector>
#include <QColor>

class ColoredTextBrowser : public QTextBrowser {
    Q_OBJECT

public:
    ColoredTextBrowser(QWidget *parent = nullptr);
    void printText(QString name);

};
#endif // COLOREDTEXTBROWSER_H
