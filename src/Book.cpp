#include "Book.hpp"
#include <iostream>
//#include "../include/Book.hpp"


using namespace std;



Book::Book(const string& title_, const string& author_, const string& isbn_, int pages_, int edition_) {
    m_title = title_;
    author = author_;
    isbn = isbn_;
    pages = pages_;
    edition = edition_;
}


Book::Book(const Book& other) {
    this->m_title = other.m_title;
    this->author = other.author;
    this->isbn = other.isbn;
    this->pages = other.pages;
    this->edition = other.edition;

}


Book& Book::operator=(const Book& other) {
    if(this != &other) {
        this->m_title = other.m_title;
        this->author = other.author;
        this->isbn = other.isbn;
        this->pages = other.pages;
        this->edition = other.edition;
    }
    return *this;
}



const string& Book::getAuthor() const {
    return author;
};
const string& Book::getIsbn() const {
    return isbn;
}
int Book::getPages() const {
    return pages;
}
int Book::getEdition() const {
    return edition;
}
string Book::prettyPrint() const {
    string pages_to_str = to_string(pages);
    string edition_to_str = to_string(edition);
    string info;
    info = m_title + ", " + author + ", " + isbn + ", " + pages_to_str + ", " + edition_to_str + " |";
    return info;
}
bool Book::operator==(const Book& other) const {
    if (this->prettyPrint() == other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}
        
bool Book::operator!=(const Book& other) const {
    if (this->prettyPrint()!= other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}
bool Book::operator==(const Media& other) const {
    if (this->prettyPrint() == other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}
        
bool Book::operator!=(const Media& other) const {
    if (this->prettyPrint()!= other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}