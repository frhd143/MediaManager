#include "Ps2Game.hpp"

#include <iostream>
Ps2Game::Ps2Game(const string& title_, const string& studio_, int year_) {
    m_title = title_;
    studio = studio_;
    year = year_;
}
Ps2Game::Ps2Game(const Ps2Game& other)  {
    this->m_title = other.m_title;
    this->studio = other.studio;
    this->year = other.year;
}
Ps2Game& Ps2Game::operator=(const Ps2Game& other) {
    this->m_title = other.m_title;
    this->studio = other.studio;
    this->year = other.year;
    return *this;
}
const string& Ps2Game::getStudio() const {
    return studio;
}
int Ps2Game::getYear() const {
    return year;
}
string Ps2Game::prettyPrint() const {
    string info;
    string year_to_str = to_string(year);
    info = m_title + ", " + studio + ", " + year_to_str;
    return info;
}
bool Ps2Game::operator==(const Ps2Game& other) const {
    if (this->prettyPrint() == other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}
        
bool Ps2Game::operator!=(const Ps2Game& other) const {
    if (this->prettyPrint()!= other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}
bool Ps2Game::operator==(const Media& other) const {
    if (this->prettyPrint() == other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}
        
bool Ps2Game::operator!=(const Media& other) const {
    if (this->prettyPrint()!= other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}
