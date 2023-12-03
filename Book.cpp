#include "Book.h"

#include <iostream>
#include <string>

// Constructor
Book::Book(std::string title, std::string author, std::string NF_F, std::string genre, std::string type, int length){
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

    // Serial addition with genre Fiction or Non-Fiction type
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

    // Serial addition based on type
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

    // Serial addition with length
    if(this->length < 100){
        serial = serial;
    } else if (this->length >= 100 && this->length < 200){
        serial += 1;
    } else if (this->length >= 200 && this->length < 300){
        serial += 2;
    } else if (this->length >= 300 && this->length < 400){
        serial += 3;
    } else if (this->length >= 400 && this->length < 500){
        serial += 4;
    } else if (this->length >= 500 && this->length < 600){
        serial += 5;
    } else if (this->length >= 600 && this->length < 700){
        serial += 6;
    } else if (this->length >= 700 && this->length < 800){
        serial += 7;
    } else if (this->length >= 800 && this->length < 900){
        serial += 8;
    } else if (this->length >= 900){
        serial += 9;
    }

    return serial;
}

void Book::printBook(){
    std::cout << title << ',' << author << ", " << NF_F << ", " << genre << ", "<< type << ", " << length << ", " << serial << std::endl;
}

