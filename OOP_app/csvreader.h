#ifndef CSVREADER_H
#define CSVREADER_H

#include "abstractreader.h"

class CsvReader : public AbstractReader
{
public:
    CsvReader(const std::string& filename);
    bool isOpen() override;
    std::vector<Film> readAll() override;

private:
    std::ifstream fin;
};

#endif // CSVREADER_H
