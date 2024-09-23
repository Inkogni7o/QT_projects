#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnEntry, &QPushButton::clicked,
            this, &MainWindow::onBtnEntryClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnEntryClicked() {
    QString text = ui->entryText->text();
    ui->entryText->clear();
    ui->outputText->printText(text);
}
