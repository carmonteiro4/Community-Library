#include <iostream>
#include <fstream>
#include <sstream>

// hello

int SerialNumberGenerator(std::string NF_F, std::string genre, std::string type, std::string length){

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
      std::string length;

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
              length = entry;
          }
          i++;
      }
      Serial = SerialNumberGenerator;
      tree.insert(Serial, title, author);
    }
    File.close;
    
return 0;
}
