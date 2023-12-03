#include <iostream>
#include <fstream>
#include <sstream>
#include "BookTree.h"

// hello

int SerialNumberGenerator(std::string NF_F, std::string genre, std::string type, int length){
    int serial;
    if(NF_F == "Fiction"){
        serial = 1000;
    }else if(NF_F == "Non-Fiction"){
        serial = 2000;
    }

    if(genre == "Mystery"){
        serial = serial;
    }if(genre == "Science"){
        serial += 100;
    }if(genre == "Fantasy"){
        serial += 200;
    }if(genre == "Romance"){
        serial += 300;
    }if(genre == "History"){
        serial += 400;
    }if(genre == "Dystopian"){
        serial += 500;
    }if(genre == "Comedy"){
        serial += 600;
    }if(genre == "Horror"){
        serial += 700;
    }if(genre == "Biography"){
        serial += 800;
    }if(genre == "Adventure"){
        serial += 900;
    }

    if(type == "Novel"){
        serial = serial;
    }if(type == "Textbook"){
        serial += 10;
    }if(type == "Poetry"){
        serial += 20;
    }if(type == "Essay"){
        serial += 30;
    }if(type == "Short Essay"){
        serial += 40;
    }

    if(length < 100){
        serial = serial;
    }if(length >= 100 && length < 200){
        serial += 1;
    }if(length >= 200 && length < 300){
        serial += 2;
    }if(length >= 300 && length < 400){
        serial += 3;
    }if(length >= 400 && length < 500){
        serial += 4;
    }if(length >= 500 && length < 600){
        serial += 5;
    }if(length >= 600 && length < 700){
        serial += 6;
    }if(length >= 700 && length < 800){
        serial += 7;
    }if(length >= 800 && length < 900){
        serial += 8;
    }if(length >= 900){
        serial += 9;
    }

    return serial;

}

void GetData(std::string fname){
    std::string line;
    std::string entry;
    std::ifstream File;

    std::getline(File, line);
    while(std::getline(File, line)){

        std::stringstream streamline(line);

        std::string title;
        std::string author;
        std::string NF_F;
        std::string genre;
        std::string type;
        int length;
        int serial;

        int i = 0;
        while(std::getline(streamline, entry, ',')){
            if(i == 0){
                title = entry;
            }else if(i == 1){
                author = entry;
            }else if(i == 2){
                NF_F = entry;
            }else if(i == 3){
                genre = entry;
            }else if(i == 4){
                type = entry;
            }else if(i == 5){
                length = std::stoi(entry);
            }
            i++;
        }

        serial = SerialNumberGenerator;
        Book *current = new Book (title, author, NF_F, genre, type, length, serial);
        tree.insert(current);

    }
    File.close;
}

int main(int argc, char*argv[]){
   std::string fname(argv[1]);
   BookTree *tree = new BookTree();
   GetData(fname);
    
    return 0;
}
