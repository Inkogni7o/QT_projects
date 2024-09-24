#include "jsonreader.h"

jsonReader::jsonReader(std::string filename)
{
    fin = std::ifstream(filename);
}

bool jsonReader::isOpen()
{
    return fin.is_open();
}

std::vector<Film> jsonReader::readAll()
{   std::vector<Film> films;
    nlohmann::json json;
    fin >> json;

    for(const auto& j: json["films"]) {
        Film film;
        film.id = j["ID"];
        film.name = j["Title"];
        film.type = j["Type"];
        film.studio = j["Studio"];
        films.push_back(film);
        }
    return films;
}
