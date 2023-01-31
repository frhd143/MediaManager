#include "MediaManager.hpp"
#include "Media.hpp"
#include "Ps2Game.hpp"
#include "Book.hpp"
#include <iostream>


using namespace std;


MediaManager:: MediaManager(size_t size) {
    managerSize = size;
    media_array = new Media*[managerSize];
}


MediaManager::MediaManager(const MediaManager& other) {
    managerSize = other.managerSize;
    this->media_array = new Media*[managerSize];
    for (int i = 0; i < other.nrOfMedia; i++) {
        addMedia(other.media_array[i]);
    }
}


MediaManager::~MediaManager() {
    
    // A destructor to dealocate media_array and all the media pointers inside the array!
    for(int i = 0; i < nrOfMedia; i++) {
        //std::cout << i << std::endl;
        //std::cout << media_array[i]->prettyPrint() << std::endl;
        
        delete media_array[i];
        media_array[i] = nullptr;
    }
    delete[] media_array;
    media_array = nullptr;
}


void MediaManager::addMedia(Media* media_) {
    // Create a new Book pointer!
    Book* book_ptr = new Book;
    // Create a new temporary Book pointer that is a nullptr!
    Book* book_ptr_temp = nullptr;
    // Create a new Ps2Game pointer!
    Ps2Game* game_ptr = new Ps2Game;
    // Create a new temporary Ps2Game pointer that is a nullptr!
    Ps2Game* game_ptr_temp = nullptr;
    // Dynamic cast book_ptr_temp and game_ptr_temp
    book_ptr_temp = dynamic_cast<Book*>(media_);
    game_ptr_temp = dynamic_cast<Ps2Game*>(media_);
    // If book_ptr_temp is a Book object!
    if (book_ptr_temp != nullptr) {
        // Then add the book into the media_array!
        *book_ptr = *book_ptr_temp;
        this->media_array[nrOfMedia] = book_ptr;
        // and then add 1 to nrOfMedia!
        nrOfMedia++;
        delete game_ptr;
        //delete game_ptr_temp;
    }
    // If game_ptr_tenmp is a Ps2Game object!
    if (game_ptr_temp != nullptr) {
        // Then add the game into the media_array!
        *game_ptr = *game_ptr_temp;
        this->media_array[nrOfMedia] = game_ptr;
        // and then add 1 to nrOfMedia!
        nrOfMedia++;
        delete book_ptr;
    }
}


void MediaManager::addBook(const Book& book) {
    //std::cout <<"nrOfMedi: " << nrOfMedia << std::endl;
    //std::cout << book.prettyPrint() << std::endl;
    //Book newB = book;
    // We create a Media pointer to a new Book objects the has the same parameters 
    // as the book object that has been passed as a prameter!!
    //Media* book_Ptr = new Book(book);
    // Every time we a new book we use the variable nrOfMedia to store it book into the media_array!
    this->media_array[nrOfMedia] = new Book(book);
    // and then we add 1 to nrOfMedia!
    this->nrOfMedia++;
    //delete book_Ptr;
}



void MediaManager::addPs2Game(const Ps2Game& game) {
    // This function does exacly the same thing that addBook() does!
    //Ps2Game newG = game;
    //Media* gamePtr = new Ps2Game(game);
    this->media_array[nrOfMedia] = new Ps2Game(game);
    this->nrOfMedia++;

    //delete gamePtr;
}


string MediaManager::printMedia() const {
    // A string variable to store all information about an object! and then we return the string!
    // We use the function prettyPrint() to get all info about objects that are store in media_array!
    string info;
    for (int i=0; i<nrOfMedia; i++) {
        info = info + media_array[i]->prettyPrint() + " ";
    }
    return info;
}


void MediaManager::getBooks(Book*& out_array, int& out_bookCount) const {
    // A variable to count books
    int book_count = 0;
    // Vi can use this varaiable to store our books
    int book_index = 0;
    // This loop counts how many books we have in meia_array
    for(int i=0; i<this->nrOfMedia; i++) {
        Book* book_ptr = nullptr;
        book_ptr = dynamic_cast<Book*>(this->media_array[i]);
        if (book_ptr != nullptr) {
            book_count = book_count+1;
        }
    }
    // Creating a new array to strore all books in!
    Book* books_arr = new Book[book_count];
    // In this loop we add all books into books_arr that we just created!
    for (int i=0; i<this->nrOfMedia; i++) {
        Book* new_book_ptr = nullptr;
        new_book_ptr = dynamic_cast<Book*>(this->media_array[i]);
        if (new_book_ptr != nullptr) {
            books_arr[book_index] = *new_book_ptr;
            book_index = book_index+1;
        }
    }
    // Wen finished adding all books into the new array!
    out_array = books_arr;
    out_bookCount = book_count;
    
}


void MediaManager::getPs2Games(Ps2Game*& out_array, int& out_gameCount) const {
    // A variable to count games
    int game_count = 0;
    // Create a new variable! Then we use the variabe to store the games in right place!
    int game_index = 0;
    // Count number of games in media_array!
    for(int i=0; i<this->nrOfMedia; i++) {
        Ps2Game* game_ptr = nullptr;
        game_ptr = dynamic_cast<Ps2Game*>(this->media_array[i]);
        if(game_ptr != nullptr) {
            game_count = game_count+1;
        }
    }
    // Creating a new array to store all games in 
    Ps2Game* game_arr = new Ps2Game[game_count];
    // Add all games into game_arr that we created!
    for (int i=0; i<this->nrOfMedia; i++) {
        Ps2Game* new_game_ptr = nullptr;
        new_game_ptr = dynamic_cast<Ps2Game*>(this->media_array[i]);
        if (new_game_ptr != nullptr) {
            game_arr[game_index] = *new_game_ptr;
            game_index = game_index+1;
        }
    }
    // When finished adding all games into the new array!
    out_array = game_arr;
    out_gameCount = game_count;
}


Media** MediaManager::getMedias() const {
    // We create a pointer to the media_arry and then return it!
    //Media** return_ptr_toM = media_array;
    //return return_ptr_toM;
    return media_array;
}


bool MediaManager::operator==(const MediaManager& other) const {
    int value = 0;
    // Check if objects have the same length!
    if (this->nrOfMedia == other.nrOfMedia) {
        // Same length! 
        for(int i=0; i<nrOfMedia; i++) {
            // compare every index. If the same add 1 to value
            if (this->media_array[i]->prettyPrint() == other.media_array[i]->prettyPrint()) {
                value = value+1;
            }
            // If not the same! then value - 1.
            else {
                value = value-1;
            }
        }
        // if value==nrOfMedia it means that the objects are the same. But if value!=nrOfMedia then it means
        // that the objects are not the same!
        if (value == nrOfMedia) {
            return true;
        } else {return false;}
    } 
    // Not the same length! then thay are not equivalent!
    else {
        return false;
    } 
}


// It works exacly like the previous operator==, but insted of == we use !=
bool MediaManager::operator!=(const MediaManager& other) const {
    int value = 0;
    if (this->nrOfMedia != other.nrOfMedia) {
        return true;
    } else {
        for (int i=0; i<nrOfMedia; i++) {
            if(this->media_array[i]->prettyPrint() != other.media_array[i]->prettyPrint()) {
                value = value+1;
                return true;
            } else {
                value = value-1;
            }
        }
        if (value==nrOfMedia) {
            return true;
        } else {return false;}
    }
}