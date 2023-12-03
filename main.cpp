#include <iostream>
#include <fstream>
#include <sstream>
#include "BookTree.h"

BookTree GetData(std::string fname){
    BookTree temp;

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

        Book *current = new Book (title, author, NF_F, genre, type, length);
        temp.insert(current);

    }
    File.close();
    return temp;
}

void print_tree(BookTree* tree, std::ofstream& os){
    tree->preorder(os);

}

int main(int argc, char*argv[]){
   std::string fname(argv[1]);
   BookTree tree;
   tree = GetData(fname);
    std::ofstream fs(fname);
    print_tree(&tree, fs);
    fs << "Tree Height: " << tree.height() << std::endl;
    fs.close();
    
    return 0;
}

