#include "Book.h"

#include <iostream>
#include <string>

// Constructor
Book::Book(){
    this->title = "";
    this->author = "";
    this->genre = "";
    this->type = "";
    this->length = 0;
}

Book::~Book(){

}

// Title Getters/Setters
void Book::setTitle(std::string title){
    this->title = title;
}
std::string Book::getTitle(){
    return this->title;
}

// Author Getters/Setters
void Book::setAuthor(std::string author){
    this->author = author;
}
std::string Book::getAuthor(){
    return this->author;
}

// Non-Fiction/Fiction Getters/Setters
void Book::setNF_F(std::string NF_F){
    this->NF_F = NF_F;
}
std::string Book::getNF_F(){
    return this->NF_F;
}

// Genre Getters/Setters
void Book::setGenre(std::string genre){
    this->genre = genre;
}
std::string Book::getGenre(){
    return this->genre;
}

// Type Getters/Setters
void Book::setType(std::string type){
    this->type = type;
}
std::string Book::getType(){
    return this->type;
}

// Length Getters/Setters
void Book::setLength(std::string length){
    this->length = length;
}
std::string Book::getLength() {}(){
    return this->length;
}