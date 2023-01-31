#include "Media.hpp"
#ifndef PS2GAME_H
#define PS2GAME_H
class Ps2Game:public Media {
    private:
        //string g_title;
        string studio;
        int year;
    public:
        Ps2Game() {};
        Ps2Game(const string& title, const string& studio,int year);
        Ps2Game(const Ps2Game& other);
        virtual ~Ps2Game() {};
        Ps2Game& operator=(const Ps2Game& other);
        const string& getStudio() const;
        int getYear() const;
        bool operator==(const Ps2Game& other) const;
        bool operator!=(const Ps2Game& other) const;
        string prettyPrint() const;
        bool operator==(const Media& other) const;
        bool operator!=(const Media& other) const;
};
#endif // PS2GAME_H
/*
    TODO:
    1. Add include guard
    2. Define the class 'Book'
    3. Declare necessary members
    4. Define member functions in Book.cpp
*/