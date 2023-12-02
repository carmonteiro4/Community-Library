//
// Created by Xlilw on 12/2/2023.
//

#ifndef CSC_212_PROJECT_BOOK_H
#define CSC_212_PROJECT_BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string genre;
    std::string type;
    int length;

public:
    Book();
    Book(std::string title, std::string author, std::string genre, std::string type, int length);
    ~Book();

    void setTitle(std::string title);
    std::string getTitle();

    void setAuthor(std::string author);
    std::string getAuthor();

    void setGenre(std::string genre);
    std::string getGenre();

    void setType(std::string type);
    std::string getType();

    void setLength(std::string length);
    std::string getLength();
};


#endif //CSC_212_PROJECT_BOOK_H
