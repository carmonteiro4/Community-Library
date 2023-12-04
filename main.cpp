#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "BookTree.h"


// This Function reads the data from a file and populate the BookTree
BookTree* GetData(std::string infname, BookTree* temp){

    std::string line;
    std::string entry;
    std::ifstream File(infname);// Opens file stream for reading

    if (!File) {
        std::cerr << "Error opening file" << std::endl;// Prints an error if file opening fails
    }
    // std::getline(File, line);
    // COMMENTED OUT FOR TESTING

    while(std::getline(File, line)){// Reads each line from the file
        std::stringstream streamline(line);// Processes the line as a stream
        std::string author;
        std::string NF_F;
        std::string genre;
        std::string type;
        int length;

        int i = 0;
        while(std::getline(streamline, entry, ',')){// Parses the data separated by commas
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
                length = std::stoi(entry);// Converts string to int for length
            }
            i++;
        }

        Book *current = new Book (title, author, NF_F, genre, type, length);// Creates a new Book object
        //current->printBook();

        temp->insert(current);// Inserts the Book object into the BookTree
    }
    File.close();// Closes the file stream
    return temp;// Returns the updated BookTree
}

// Function to print the BookTree in preorder
void print_tree(BookTree* tree, std::ofstream& os){
    tree->preorder(os);
}
// Function to get user input for book attributes and creates a serial number
int getInfo(int *currentNF_F, int *currentGenre){
    int num;
    int serial = 0;

    // Genre Type Collection
    std::cout << "Enter Number for Genre Type: " << std::endl;
    std::cout << "1: Fiction" << std::endl;
    std::cout << "2: Non-Fiction" << std::endl;

    std::cin >> num;
    *currentNF_F = num;
    num == 1 ? serial+=1000 : serial+=2000;

    // Genre Collection
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

    // Type Collection
    std::cout << "Enter Number for Type: " << std::endl;
    std::cout << "0: Novel" << std::endl;
    std::cout << "1: Textbook" << std::endl;
    std::cout << "2: Poetry" << std::endl;
    std::cout << "3: Essay" << std::endl;
    std::cout << "4: Short Story" << std::endl;

    std::cin >> num;
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

    // Length Collection
    std::cout << "Enter Length: " << std::endl;

    std::cin >> num;
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
// Function to get user input for book attributes and creates a serial number
void promptUser(int argc, char*argv[]){
    std::string infname(argv[1]);
    std::string ofname(argv[2]);
    BookTree *tree = new BookTree;
    tree = GetData(infname, tree);
    int input = -1;
    while(input != 0){
        std::cout << ("0: Exit Code");
        std::cout << ("1: Get Book Recommendation");
        std::cout << ("2: Insert Book to the Database");
        std::cin >> input;
        if(input = 0){
        break;
    }
        if(input = 1){
            int serial = getInfo();

        int closestSerial = tree->closestSerial(serial);
        //    std::cout << "Closest serial to " << serial << " is " << closestSerial << std::endl;

        std::vector<Book> suggestions;
        tree->getSuggestions(closestSerial, &suggestions);

        for (int i = 0; i < suggestions.size(); i++){
            std::cout << suggestions[i].title << ", " << suggestions[i].author << ", " << suggestions[i].NF_F << ", " << suggestions[i].genre << ", " << suggestions[i].type << ", " << suggestions[i].length << std::endl;
    }
        }
        if(input = 2){
            int serial = getInfo();
            //tree->insert()

        }

    }
    

    

=======
// Function to extract a digit from a number at a specified position
int getDigit(int number, int position) {
    return abs(number) / static_cast<int>(std::pow(10, position)) % 10;
>>>>>>> 87d3867d7c5b1dd0be00dfc9690f8106ee79ba48
}

int main(int argc, char*argv[]){
    std::string infname(argv[1]);
    std::string ofname(argv[2]);
    BookTree *tree = new BookTree;
    tree = GetData(infname, tree);


    int currentNF_F = 0;
    int currentGenre = 0;
    int serial = getInfo(&currentNF_F, &currentGenre);


    int closestSerial = tree->closestSerial(serial);
//    std::cout << "Closest serial to " << serial << " is " << closestSerial << std::endl;

    std::vector<Book> suggestions;
    tree->getSuggestions(closestSerial, &suggestions);

    for (int i = 0; i < suggestions.size(); i++){
        if (getDigit(suggestions[i].serial, 3) == currentNF_F && getDigit(suggestions[i].serial, 2) == currentGenre){
            std::cout << suggestions[i].title << ", " << suggestions[i].author << ", " << suggestions[i].NF_F << ", " << suggestions[i].genre << ", " << suggestions[i].type << ", " << suggestions[i].length << std::endl;
        }
    }


    delete tree;// Deallocates memory for the BookTree
    return 0;// Returns from main function
}

