#ifndef CSC_212_PROJECT_BOOKTREE_H
#define CSC_212_PROJECT_BOOKTREE_H

#include <iostream>
#include <ostream>
#include <vector>
#include "Book.h"

class BookTreeNode {
    public:
    // node contains book and serial #
        Book* book;

        bool color;
        BookTreeNode* left;
        BookTreeNode* right;

        BookTreeNode(Book* book);
        friend class BookTree;
};

class BookTree {
    public:
        BookTreeNode* root;
        BookTreeNode* insert(Book* book, BookTreeNode* root);

        void flipColors(BookTreeNode* root);
        BookTreeNode* rotateLeft(BookTreeNode* root);
        BookTreeNode* rotateRight(BookTreeNode* root);

        bool is_red(BookTreeNode* root);


        BookTree();
        ~BookTree();

        void insert(Book* book);

        void preorder(std::ostream& os= std::cout);
        void postorder(std::ostream& os= std::cout);
        void inorder(std::ostream& os = std::cout);
        bool search(int serialNum, BookTreeNode* root, BookTreeNode* node);
        int height();

        int closestSerial(int serial);
        void getSuggestions(int closestSerial, std::vector<Book> *suggestions);

    private:
        void preorder(BookTreeNode* root, std::ostream& os);
        int height(BookTreeNode* root);

        int closestSerial(BookTreeNode* root, int serial, int &closest);


};

#endif //CSC_212_PROJECT_BOOKTREE_H
