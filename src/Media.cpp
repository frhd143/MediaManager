
#include <iostream>
#include "Media.hpp"
using namespace std;
Media::Media(const string& title ) {
    m_title = title;
} 
const string& Media::getTitle() const {
    return m_title;
}
bool Media::operator==(const Media& other) const {
    if (this->prettyPrint() == other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}
bool Media::operator!=(const Media& other) const {
    if (this->prettyPrint() != other.prettyPrint()) {
        return true;
    }
    else {
        return false;
    }
}