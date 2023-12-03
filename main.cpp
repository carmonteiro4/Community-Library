#include <iostream>
#include <fstream>
#include <sstream>
#include "BookTree.h"

BookTree GetData(std::string infname){
    BookTree temp;

    std::string line;
    std::string entry;
    std::ifstream File(infname);

    if (!File) {
        std::cerr << "Error opening file" << std::endl;
    }
    // std::getline(File, line);
    // COMMENTED OUT FOR TESTING

    while(std::getline(File, line)){
        std::stringstream streamline(line);
        std::string title;
        std::string author;
        std::string NF_F;
        std::string genre;
        std::string type;
        int length;

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
        //current->printBook();
        temp.insert(current);

    }
    File.close();
    return temp;
}

void print_tree(BookTree* tree, std::ofstream& os){
    tree->preorder(os);

}

int main(int argc, char*argv[]){
    std::string infname(argv[1]);
    std::string ofname(argv[2]);
    BookTree tree;
    tree = GetData(infname);

    std::ofstream of(ofname);
    print_tree(&tree, of);
    of << "Tree Height: " << tree.height() << std::endl;
    of.close();
    
    return 0;
}

