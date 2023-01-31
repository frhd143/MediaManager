#include <iostream>
#include "Media.hpp"
#include "Book.hpp"
#include "Ps2Game.hpp"


#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H


class MediaManager {
    private:
        Media** media_array;
        int managerSize;
        int nrOfMedia = 0;
    public:
        MediaManager(size_t size);
        MediaManager(const MediaManager& other);
        ~MediaManager();
        void addMedia(Media* media_);
        void addBook(const Book& book);
        void addPs2Game(const Ps2Game& game);
        string printMedia() const;
        void getBooks(Book*& out_array, int& out_bookCount) const;
        void getPs2Games(Ps2Game*& out_array, int& out_gameCount) const;
        Media** getMedias() const;
        bool operator==(const MediaManager& other) const;
        bool operator!=(const MediaManager& other) const;
};
#endif // MEDIAMANAGER_Hv