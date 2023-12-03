#ifndef CSC_212_PROJECT_BOOK_H
#define CSC_212_PROJECT_BOOK_H

#include <iostream>
#include <string>

// This is our book class which will hold
// all of our data for each book

class Book {
public:
    // Data
    std::string title;
    std::string author;
    std::string NF_F; // Non-Fiction or Fiction
    std::string genre;
    std::string type;
    int length;
    int serial;


    // Constructor
    Book(std::string title, std::string author, std::string NF_F, std::string genre, std::string type, int length);
    ~Book();

    // Getters and Setters
    void setTitle(std::string title);
    std::string getTitle();

    void setAuthor(std::string author);
    std::string getAuthor();

    void setNF_F(std::string NF_F);
    std::string getNF_F();

    void setGenre(std::string genre);
    std::string getGenre();

    void setType(std::string type);
    std::string getType();

    void setLength(std::string length);
    std::string getLength();

    std::string getSerial();

    int createSerial();
};


#endif //CSC_212_PROJECT_BOOK_H
