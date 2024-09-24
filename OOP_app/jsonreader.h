#ifndef JSONREADER_H
#define JSONREADER_H

#include "abstractreader.h"
#include <json.hpp>

class jsonReader : public AbstractReader
{
public:
    jsonReader(std::string filename);
    bool isOpen() override;
    std::vector<Film> readAll() override;

private:
    std::ifstream fin;
};

#endif // JSONREADER_H
