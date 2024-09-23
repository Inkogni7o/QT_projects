#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include <fstream>

#include "film.h"

class CsvReader
{
public:
    CsvReader(const std::string& filename);
    bool isOpen();
    std::vector<Film> readAll();

private:
    std::ifstream fin;
};

#endif // CSVREADER_H
