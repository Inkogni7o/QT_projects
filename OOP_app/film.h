#ifndef FILM_H
#define FILM_H

#include <string>

struct Film
{
    int id;
    std::string name;
    std::string type;
    std::string studio;

    bool operator> (const Film other) const
    {
        if (studio > other.studio) {
            return true;
        } else {
            return false;
        }
    }

    bool operator< (const Film other) const
    {
        if (studio < other.studio) {
            return true;
        } else {
            return false;
        }
    }

    bool operator== (const Film other) const
    {
        if (studio == other.studio) {
            return true;
        } else {
            return false;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Film f)
    {
        os << f.name << ";" << f.type << ";" << f.studio;
        return os;
    }
};

#endif // FILM_H
