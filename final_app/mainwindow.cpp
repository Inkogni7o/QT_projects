#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    painted = new paintWidget(this);
    setCentralWidget(painted);
}

MainWindow::~MainWindow()
{
    delete ui;
}

