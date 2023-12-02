#include <iostream>
#include <fstream>
#include <sstream>

// hello

int main(int argc, char*argv[]){
   std::string fname(argv[1]);
   BookTree tree;

    std::string line;
    std::string entry;
    std::ifstream File;

    std::getline(File, line);
    while(std::getline(File, line)){
      
      std::stringstream streamline(line);
  
      int num;
      while(std::getline(streamline, entry, ',')){
          tree.insert(num);
      }
    }
    File.close;
    
return 0;
}
