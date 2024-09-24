#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>
#include <string>
#include <fstream>

#include "film.h"

class AbstractReader
{
public:
    AbstractReader();
    virtual bool isOpen() = 0;
    virtual std::vector<Film> readAll() = 0;
};

#endif // ABSTRACTREADER_H
