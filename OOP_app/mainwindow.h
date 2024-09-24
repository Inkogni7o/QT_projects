#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

#include "film.h"
#include "csvreader.h"
#include "csvwriter.h"
#include "jsonreader.h"

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
    void search();
    void openFileDialog();
    void uploadTable(int mode);
    void updateTable();
    void saveToCsv();
    void addRow();
    void saveToCsvByCsvWriter();

private:
    Ui::MainWindow *ui;
    std::string fileName;
    std::vector<Film> films;
};
#endif // MAINWINDOW_H
