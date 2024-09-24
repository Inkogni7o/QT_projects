#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->outputTable->setColumnCount(4);
    QStringList headers;
    headers << "ID" << "Название" << "Тип" << "Студия";
    ui->outputTable->setHorizontalHeaderLabels(headers);
    ui->outputTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStringList options;
    options << "Movie" << "Serial";
    ui->typeInputCombo->addItems(options);


    connect(ui->btnImportFile, &QPushButton::clicked,
            this, &MainWindow::openFileDialog);  // connect btn for search
    connect(ui->btnSaveToCsv, &QPushButton::clicked,
            this, &MainWindow::saveToCsv);
    connect(ui->btnSaveToJson, &QPushButton::clicked,
            this, &MainWindow::saveToJson);
    connect(ui->btnAddFilm, &QPushButton::clicked,
            this, &MainWindow::addRow);
    connect(ui->btnCsvWriterSave, &QPushButton::clicked,
            this, &MainWindow::saveToCsvByCsvWriter);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search()
{
    auto request = ui->editSearch->text().toStdString();
    if (request == "") {
        this->updateTable();
    } else {
    int count = 0;

        for (size_t i = 0; i < films.size(); i++) {
            const Film& f = films[i];
            if (f.name.find(request) != std::string::npos ||
                    f.type.find(request) != std::string::npos ||
                    f.studio.find(request) != std::string::npos) {
                QTableWidgetItem *id = new QTableWidgetItem(QString::number(f.id));
                QTableWidgetItem *name = new QTableWidgetItem(QString::fromStdString(f.name));
                QTableWidgetItem *type = new QTableWidgetItem(QString::fromStdString(f.type));
                QTableWidgetItem *studio = new QTableWidgetItem(QString::fromStdString(f.studio));

                ui->outputTable->setItem(count, 0, id);
                ui->outputTable->setItem(count, 1, name);
                ui->outputTable->setItem(count, 2, type);
                ui->outputTable->setItem(count, 3, studio);
                count += 1;
            };
        }
        ui->outputTable->setRowCount(count);
    }
}

void MainWindow::openFileDialog()
{
    QString name = QFileDialog::getOpenFileName(this,
                              tr("Выбрать файл"), "",
                              tr("CSV Files (*.csv);;JSON Files (*.json)"));
    if (!name.isEmpty()) {
       QFileInfo fileInfo(name);
       if (fileInfo.suffix() == "csv") {
           fileName = name.toStdString();
           this->uploadTable(1);
        } else if (fileInfo.suffix() == "json"){
           fileName = name.toStdString();
           this->uploadTable(2);
       }
    }
}

bool compareByStudio(const Film& a, const Film& b) {
    return a < b;
}

void MainWindow::uploadTable(int mode)
{
    if (mode == 1) {
        CsvReader reader(fileName);
        if (reader.isOpen()) {
            films = reader.readAll();
        }
    } else if (mode == 2) {
        jsonReader reader(fileName);
        if (reader.isOpen()) {
            films = reader.readAll();
        }
    }

    std::sort(films.begin(), films.end(), compareByStudio);

    ui->outputTable->setRowCount(films.size());
    for (size_t i = 0; i < films.size(); i++) {
        const Film& f = films[i];
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(f.id));
        QTableWidgetItem *name = new QTableWidgetItem(QString::fromStdString(f.name));
        QTableWidgetItem *type = new QTableWidgetItem(QString::fromStdString(f.type));
        QTableWidgetItem *studio = new QTableWidgetItem(QString::fromStdString(f.studio));

        ui->outputTable->setItem(i, 0, id);
        ui->outputTable->setItem(i, 1, name);
        ui->outputTable->setItem(i, 2, type);
        ui->outputTable->setItem(i, 3, studio);
    }
}

void MainWindow::updateTable()
{
        ui->outputTable->setRowCount(films.size());
        for (size_t i = 0; i < films.size(); i++) {
            const Film& f = films[i];
            QTableWidgetItem *id = new QTableWidgetItem(QString::number(f.id));
            QTableWidgetItem *name = new QTableWidgetItem(QString::fromStdString(f.name));
            QTableWidgetItem *type = new QTableWidgetItem(QString::fromStdString(f.type));
            QTableWidgetItem *studio = new QTableWidgetItem(QString::fromStdString(f.studio));

            ui->outputTable->setItem(i, 0, id);
            ui->outputTable->setItem(i, 1, name);
            ui->outputTable->setItem(i, 2, type);
            ui->outputTable->setItem(i, 3, studio);
        }
}

void MainWindow::saveToCsv()
{
    QString saveName = QFileDialog::getSaveFileName(this, "Сохранить в CSV", "", "CSV Files (*.csv)");
    if (!saveName.isEmpty()) {
        QFile file(saveName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            for (const Film& f: films) {
                out << QString::number(f.id) << "," << QString::fromStdString(f.name)
                << "," << QString::fromStdString(f.type) << "," << QString::fromStdString(f.studio) << "\n";
            }
            file.close();
        }
    }
}

void MainWindow::saveToJson()
{
    nlohmann::json json;
    QString saveName = QFileDialog::getSaveFileName(this, "Сохранить в JSON", "", "JSON Files (*.json)");
    if (!saveName.isEmpty()) {
        for (const auto& film : films) {
            nlohmann::json film_json;
            film_json["ID"] = film.id;
            film_json["Title"] = film.name;
            film_json["Type"] = film.type;
            film_json["Studio"] = film.studio;
            json["films"].push_back(film_json);
        }
        std::string name = saveName.toStdString();
        std::ofstream file(name);
        file << std::setw(4) << json << std::endl;
    }
}

void MainWindow::addRow()
{
    Film new_film;
    if (!(ui->idInput->text().isEmpty() || ui->nameInput->text().isEmpty()
            || ui->typeInputCombo->currentText().isEmpty()
            || ui->studioInput->text().isEmpty()))
    {
        new_film.id = ui->idInput->text().toInt();
        new_film.name = ui->nameInput->text().toStdString();
        new_film.type = ui->typeInputCombo->currentText().toStdString();
        new_film.studio = ui -> studioInput->text().toStdString();
        films.push_back(new_film);
    }
    this->updateTable();
}


void MainWindow::saveToCsvByCsvWriter()
{
    QString saveName = QFileDialog::getSaveFileName(this, "Сохранить в CSV", "", "CSV Files (*.csv)");
    if (!saveName.isEmpty()) {
        std::string name = saveName.toLatin1().data();
        CsvWriter writer(name);
        writer.writeAll(films);
    }
}
