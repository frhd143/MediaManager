#include "Media.hpp"
#ifndef BOOK_H
#define BOOK_H
class Book:public Media {
    private:
        //string b_title;
        string author;
        string isbn;
        int pages;
        int edition;
    public:
        Book() {};
        Book(const string& title, const string& author, const string& isbn, int pages, int edition);
        Book(const Book& other);
        virtual ~Book() {};
        Book& operator=(const Book& other);
        const string& getAuthor() const;
        const string& getIsbn() const;
        int getPages() const;
        int getEdition() const;
        bool operator==(const Book& other) const;
        bool operator!=(const Book& other) const;
        string prettyPrint() const;
        bool operator==(const Media& other) const;
        bool operator!=(const Media& other) const;
};
#endif // BOOK_H