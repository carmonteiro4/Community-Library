#include "Book.h"

#include <iostream>
#include <string>

// Constructor
Book::Book(std::string title, std::string author, std::string NF_F, std::string genre, std::string type, int length, int serial){
    this->title = title;
    this->author = author;
    this->NF_F = NF_F;
    this->genre = genre;
    this->type = type;
    this->length = length;
    this->serial = createSerial();
}

Book::~Book(){

}

// Serial Number Getters/Setters
int Book::createSerial() {
    int serial = 0;
    this->NF_F == "Fiction" ? serial+=1000 : serial+=2000;
    // Serial addition with genre type
    if (this->genre == "Mystery") {
        serial += 0;
    } else if (this->genre == "Science") {
        serial += 100;
    } else if (this->genre == "Fantasy") {
        serial += 200;
    } else if (this->genre == "Romance") {
        serial += 300;
    } else if (this->genre == "History") {
        serial += 400;
    } else if (this->genre == "Dystopian") {
        serial += 500;
    } else if (this->genre == "Comedy") {
        serial += 600;
    } else if (this->genre == "Horror") {
        serial += 700;
    } else if (this->genre == "Biography") {
        serial += 800;
    } else if (this->genre == "Adventure") {
        serial += 900;
    }

    //Serial addition based on type
    if (this->type == "Novel"){
        serial+=0;
    } else if (this->type == "Textbook"){
        serial+=10;
    } else if (this->type == "Poetry"){
        serial+=20;
    } else if (this->type == "Essay"){
        serial+=30;
    } else if (this->type == "Short Story"){
        serial+=40;
    }
}

std::string Book::getSerial() {}(){
return this->serial;
}


