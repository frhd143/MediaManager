/*
    Written by Farhad Asadi
*/

#include <iostream>

#include "include/MediaManager.hpp"

int main()
{
    //std::cout << "Let's begin!" << std::endl;

    {
        // This is lab2
        MediaManager manager(3);


        Book hitchickersGuide("Liftarens guide till galaxen",
                                    "Douglas Adams", "9789132212697", 42, 3);
        manager.addBook(hitchickersGuide);
        Book yachtDesign("Principles of Yacht Design",
                               "Lars Larsson, Rolf Eliasson, Michal Orych",
                               "9781408187906", 352, 4);
        manager.addBook(yachtDesign);
        Book revelationSpace("Revelation Space", "Alastair Reynolds",
                                   "9780575083097", 576, 1);
        manager.addBook(revelationSpace);


        //std::cout << manager.printMedia() << std::endl;
        //std::cout << cppPrimer.getTitle() << std::endl;
    }

    return 0;
}
