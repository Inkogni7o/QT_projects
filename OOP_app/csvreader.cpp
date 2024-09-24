#include "csvreader.h"

std::vector<std::string> split_line(const std::string &str, char delim) {

    std::vector<std::string> tokens;

    if (!str.empty()) {
        size_t start = 0, end;
        do {
            tokens.push_back(str.substr(start, (str.find(delim, start) - start)));
            end = str.find(delim, start);
            start = end + 1;
        } while (end != std::string::npos);
    }

    return tokens;
}


CsvReader::CsvReader(const std::string& filename)
{
    fin = std::ifstream(filename);
}

bool CsvReader::isOpen()
{
    return fin.is_open();
}

std::vector<Film> CsvReader::readAll()
{
    std::vector<Film> films;
    int numLine = 0;
    while (!fin.eof()) {
        std::string line;
        std::getline(fin, line);

        auto tokens = split_line(line, ';');
        if (tokens.size() == 4) {
            Film f;
            f.id = std::strtol(tokens[0].data(), nullptr, 10);
            f.name = tokens[1];
            f.type = tokens[2];
            f.studio = tokens[3];

            films.push_back(f);
        } else {
            throw std::runtime_error("Error on line: " + std::to_string(numLine));
        } numLine += 1;
    }
    return films;
}
