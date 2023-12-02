#include <iostream>
#include <fstream>
#include <sstream>

// hello

int SerialNumberGenerator(std::string NF_F, std::string genre, std::string type, int length){
    int Serial;
    if(NF_F == "Fiction"){
        Serial = 1000;
    }else if(NF_F == "Non-Fiction"){
        Serial = 2000;
    }

    if(genre == "Mystery"){
        Serial = Serial;
    }if(genre == "Science"){
        Serial += 100;
    }if(genre == "Fantasy"){
        Serial += 200;
    }if(genre == "Romance"){
        Serial += 300;
    }if(genre == "History"){
        Serial += 400;
    }if(genre == "Dystopian"){
        Serial += 500;
    }if(genre == "Comedy"){
        Serial += 600;
    }if(genre == "Horror"){
        Serial += 700;
    }if(genre == "Biography"){
        Serial += 800;
    }if(genre == "Adventure"){
        Serial += 900;
    }

    if(type == "Novel"){
        Serial = Serial;
    }if(type == "Textbook"){
        Serial += 10;
    }if(type == "Poetry"){
        Serial += 20;
    }if(type == "Essay"){
        Serial += 30;
    }if(type == "Short Essay"){
        Serial += 40;
    }

    if(length < 100){
        Serial = Serial;
    }if(length >= 100 && length < 200){
        Serial += 1;
    }if(length >= 200 && length < 300){
        Serial += 2;
    }if(length >= 300 && length < 400){
        Serial += 3;
    }if(length >= 400 && length < 500){
        Serial += 4;
    }if(length >= 500 && length < 600){
        Serial += 5;
    }if(length >= 600 && length < 700){
        Serial += 6;
    }if(length >= 700 && length < 800){
        Serial += 7;
    }if(length >= 800 && length < 900){
        Serial += 8;
    }if(length >= 900){
        Serial += 9;
    }

    return Serial;

}


int main(int argc, char*argv[]){
   std::string fname(argv[1]);
   BookTree tree;

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

      int Serial;

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
      Serial = SerialNumberGenerator;
      tree.insert(Serial, book);
    }
    File.close;
    
return 0;
}
