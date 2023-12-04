#ifndef CSC_212_PROJECT_BOOKTREE_H
#define CSC_212_PROJECT_BOOKTREE_H

#include <iostream>
#include <ostream>
#include <vector>
#include "Book.h"

class BookTreeNode {
    public:
        // node contains a book and the color and the left and right pointers
        Book* book;

        bool color;
        BookTreeNode* left;
        BookTreeNode* right;

        // constructor
        BookTreeNode(Book* book);
        friend class BookTree;
};

class BookTree {
    public:
        // root of the tree
        BookTreeNode* root;

        // insert function
        BookTreeNode* insert(Book* book, BookTreeNode* root);


        // function used for changing colors when rotating
        void flipColors(BookTreeNode* root);

        // rotate functions to keep balance of tree
        BookTreeNode* rotateLeft(BookTreeNode* root);
        BookTreeNode* rotateRight(BookTreeNode* root);

        // used to check color of node
        bool is_red(BookTreeNode* root);

        // constructors
        BookTree();
        ~BookTree();

        // public insert function
        void insert(Book* book);

        void preorder(std::ostream& os= std::cout);
        void postorder(std::ostream& os= std::cout);
        void inorder(std::ostream& os = std::cout);

        // searches if a book is in the tree and points to it
        bool search(int serialNum, BookTreeNode* root, BookTreeNode* &node);
        int height();

        // closest serial number to serial
        int closestSerial(int serial);

        // gets the recommended books
        void getSuggestions(int closestSerial, std::vector<Book>* suggestions);

    private:
        void preorder(BookTreeNode* root, std::ostream& os);

        // gets height of the tree
        int height(BookTreeNode* root);

        // second closestSerial function
        int closestSerial(BookTreeNode* root, int serial, int &closest);


};

#endif //CSC_212_PROJECT_BOOKTREE_H
