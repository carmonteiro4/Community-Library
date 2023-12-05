#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "BookTree.h"

BookTree* GetData(std::string infname, BookTree* temp){

    std::string line;
    std::string entry;
    std::ifstream File(infname);

    if (!File) {
        std::cerr << "Error opening file" << std::endl;
    }
    std::getline(File, line);

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

        temp->insert(current);
    }
    File.close();
    return temp;
}

int getInfo(int *currentNF_F, int *currentGenre){
    int num = -1;
    int serial = 0;

    // Genre Type Collection
    while(num < 1 || num > 2) {
        std::cout << "Enter Number for Genre Type: " << std::endl;
        std::cout << "1: Fiction" << std::endl;
        std::cout << "2: Non-Fiction" << std::endl;
        std::cin >> num;
    }
    *currentNF_F = num;
    num == 1 ? serial+=1000 : serial+=2000;
    num = -1;
    // Genre Collection
    while(num < 0 || num > 9){
        std::cout << "Enter Number for Genre: " << std::endl;
        std::cout << "0: Mystery" << std::endl;
        std::cout << "1: Science" << std::endl;
        std::cout << "2: Fantasy" << std::endl;
        std::cout << "3: Romance" << std::endl;
        std::cout << "4: History" << std::endl;
        std::cout << "5: Dystopian" << std::endl;
        std::cout << "6: Comedy" << std::endl;
        std::cout << "7: Horror" << std::endl;
        std::cout << "8: Biography" << std::endl;
        std::cout << "9: Adventure" << std::endl;
        std::cin >> num;
    }

    *currentGenre = num;

    if (num == 0) {
        serial += 0;
    } else if (num == 1) {
        serial += 100;
    } else if (num == 2) {
        serial += 200;
    } else if (num == 3) {
        serial += 300;
    } else if (num == 4) {
        serial += 400;
    } else if (num == 5) {
        serial += 500;
    } else if (num == 6) {
        serial += 600;
    } else if (num == 7) {
        serial += 700;
    } else if (num == 8) {
        serial += 800;
    } else if (num == 9) {
        serial += 900;
    }

    num = -1;
    // Type Collection
    while(num < 0 || num > 4) {
        std::cout << "Enter Number for Type: " << std::endl;
        std::cout << "0: Novel" << std::endl;
        std::cout << "1: Textbook" << std::endl;
        std::cout << "2: Poetry" << std::endl;
        std::cout << "3: Essay" << std::endl;
        std::cout << "4: Short Story" << std::endl;
        std::cin >> num;
    }

    if (num == 0){
        serial+=0;
    } else if (num == 1){
        serial+=10;
    } else if (num == 2){
        serial+=20;
    } else if (num == 3){
        serial+=30;
    } else if (num == 4){
        serial+=40;
    }

    num = -1;

    // Length Collection
    while(num < 0) {
        std::cout << "Enter Length as an integer for the # of pages: " << std::endl;
        std::cin >> num;
    }

    if(num < 100){
        serial = serial;
    } else if (num >= 100 && num < 200){
        serial += 1;
    } else if (num >= 200 && num < 300){
        serial += 2;
    } else if (num >= 300 && num < 400){
        serial += 3;
    } else if (num >= 400 && num < 500){
        serial += 4;
    } else if (num >= 500 && num < 600){
        serial += 5;
    } else if (num >= 600 && num < 700){
        serial += 6;
    } else if (num >= 700 && num < 800){
        serial += 7;
    } else if (num >= 800 && num < 900){
        serial += 8;
    } else if (num >= 900){
        serial += 9;
    }

    return serial;
}

int getDigit(int number, int position) {
    return abs(number) / static_cast<int>(std::pow(10, position)) % 10;
}

Book* CollectNBookInsertion(std::string fname){
    int num;
    int serial = 0;

    //Title Collection
    std::cin.ignore();
    std::cout << "Please enter the title of the book you would like to add:" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::string title;
    std::getline(std::cin, title);
    std::cout << std::endl;

    // Author Collection
    std::cout << "Please enter the author of the book you would like to add:" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::string author;
    std::getline(std::cin, author);
    std::cout << std::endl;

    // Genre Type Collection
    std::string NF_F = "";
    while(NF_F != "Fiction" && NF_F != "Non-Fiction"){
        std::cout << "Please enter the Genre of the book you would like to add:" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Fiction" << std::endl;
        std::cout << "Non-Fiction" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cin >> NF_F;
        if(NF_F == "Fiction" || NF_F == "Non-Fiction"){
            break;
        }else{
            std::cout << "Please enter either Fiction or Non-Fiction." << std::endl;
        }
    }
    std::cout << std::endl;

    // Genre Collection
    std::string genre = "";
    while (genre != "Mystery" && genre != "Science" && genre != "Fantasy" && genre != "Romance"
           && genre != "History" && genre != "Dystopian"  && genre != "Comedy"
           && genre != "Horror"  && genre != "Biography"  && genre != "Adventure") {

        std::cout << "Please enter the Genre of the book you would like to add:" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Mystery" << std::endl;
        std::cout << "Science" << std::endl;
        std::cout << "Fantasy" << std::endl;
        std::cout << "Romance" << std::endl;
        std::cout << "History" << std::endl;
        std::cout << "Dystopian" << std::endl;
        std::cout << "Comedy" << std::endl;
        std::cout << "Horror" << std::endl;
        std::cout << "Biography" << std::endl;
        std::cout << "Adventure" << std::endl;
        std::cout << "---------------------------------" << std::endl;

        std::cin >> genre;

        if(genre == "Mystery" || genre == "Science" || genre == "Fantasy" || genre == "Romance"
           || genre == "History" || genre == "Dystopian"  || genre == "Comedy"
           || genre == "Horror"  || genre == "Biography"  || genre == "Adventure"){
            break;
        }else{
            std::cout << "Please enter one of the ten given genres.";
        }
    }
    std::cout << std::endl;

    // Type Collection
    std::string type = "";
    while (type != "Novel" && type != "Textbook" && type != "Poetry" && type != "Essay"
           && type != "Short Story") {

        std::cout << "Please enter the Type of the book you would like to add:" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Novel" << std::endl;
        std::cout << "Textbook" << std::endl;
        std::cout << "Poetry" << std::endl;
        std::cout << "Essay" << std::endl;
        std::cout << "Short Story" << std::endl;
        std::cout << "---------------------------------" << std::endl;

        std::cin >> type;

        if(type == "Novel" || type == "Textbook" || type == "Poetry" || type == "Essay"
           || type == "Short Story"){
            break;
        }else{
            std::cout << "Please enter one of the five given types.";
        }
    }
    std::cout << std::endl;


    // Length Collection
    int length = -1;

    std::cout << "Enter Length as an integer for the # of pages: " << std::endl;
    while (!(std::cin >> length) || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter an integer." << std::endl;
    }
    std::cout << std::endl;

    //create new book and add it
    Book *current = new Book (title, author, NF_F, genre, type, length);


    //insert into library
    std::ofstream outputFile(fname, std::ios::app);
    outputFile << title << "," << author << "," << NF_F << "," << genre << "," << type << "," << length << std::endl;
    outputFile.close();

    return current;
}

void BookSuggester(BookTree *tree){
    int currentNF_F = 0;
    int currentGenre = 0;
    int serial = getInfo(&currentNF_F, &currentGenre);


    int closestSerial = tree->closestSerial(serial);
//    std::cout << "Closest serial to " << serial << " is " << closestSerial << std::endl;

    std::vector<Book> suggestions;
    tree->getSuggestions(closestSerial, &suggestions);

    std::cout << std::endl << "Here is our suggestion(s) for you, based on you input!" << std::endl << std::endl;

    for (int i = 0; i < suggestions.size(); i++){
        if (getDigit(suggestions[i].serial, 3) == currentNF_F && getDigit(suggestions[i].serial, 2) == currentGenre){
            std::cout << suggestions[i].title << ", " << suggestions[i].author << ", " << suggestions[i].NF_F << ", " << suggestions[i].genre << ", " << suggestions[i].type << ", " << suggestions[i].length  << "pages" << std::endl;
        }
    }

    std::cout << std::endl;

}

void UserInterface(BookTree *tree, std::string fname){
    int input = -1;
    while(input != 2){
        std::cout << "Welcome to The Community Library!" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "----What would you like to do?---" << std::endl;
        std::cout << "0: Insert a  book to the library." << std::endl;
        std::cout << "1: Request a Book Suggestion." << std::endl;
        std::cout << "2: Exit the Interface" << std::endl;
        std::cin >> input;
        if(input == 0){
            tree->insert(CollectNBookInsertion(fname));
        }else if(input == 1){
            BookSuggester(tree);
        }else if(input == 2){
            break;
        }else{
            std::cout << "Please insert a 0, 1, or 2." << std::endl;
        }

    }
}

int main(int argc, char*argv[]){

    std::string infname(argv[1]);

    BookTree *tree = new BookTree;
    tree = GetData(infname, tree);

    UserInterface(tree, infname);

    delete tree;
    return 0;
}

