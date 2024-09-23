#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include "ColoredTextBrowser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onBtnEntryClicked();

private:
    QLineEdit *entryText;
    QPushButton *btnEntry;
    ColoredTextBrowser *coloredTextBrowser;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
