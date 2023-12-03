#ifndef CSC_212_PROJECT_BOOKTREE_H
#define CSC_212_PROJECT_BOOKTREE_H

#include <iostream>
#include <ostream>
#include "Book.h"

class BookTreeNode {
    private:
    // node contains book and serial #
        Book* book;

        bool color;
        BookTreeNode* left;
        BookTreeNode* right;

    public:
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

        int height(BookTreeNode* root);
        bool is_red(BookTreeNode* root);


        BookTree();
        ~BookTree();

        void insert(Book* book);

        void preorder(std::ostream& os= std::cout);
        void postorder(std::ostream& os= std::cout);
        void inorder(std::ostream& os = std::cout);
        void search(int serialNum);
        int height();

    private:
        void preorder(BookTreeNode* root, std::ostream& os);

};

#endif //CSC_212_PROJECT_BOOKTREE_H
