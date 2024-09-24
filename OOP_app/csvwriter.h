#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <vector>
#include <fstream>

#include "film.h"

class CsvWriter
{
public:
    CsvWriter(std::string& nameSaveFile);
    bool isOpen() const;
    void writeAll(std::vector<Film> vec);

private:
  std::ofstream fout;

};

#endif // CSVWRITER_H
