#include "csvwriter.h"

CsvWriter::CsvWriter(std::string &nameSaveFile)
{
    fout = std::ofstream(nameSaveFile);
}

bool CsvWriter::isOpen() const
{
    return fout.is_open();
}

void CsvWriter::writeAll(std::vector<Film> films)
{
    if (this->isOpen()) {
        for (const Film& f: films) {
            fout << f.id << ";" << f.name << ";"
                 << f.type << ";" << f.studio << std::endl;
        }
        fout.close();
    }
}
