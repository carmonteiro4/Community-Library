#ifndef CSC_212_PROJECT_BOOKTREE_H
#define CSC_212_PROJECT_BOOKTREE_H

#include <iostream>
#include <ostream>
#include "book.h"

class BookTreeNode {
    private:
    // node contains book and serial #
        Book book;
        int serial;

        bool color;
        BookTreeNode* left;
        BookTreeNode* right;

    public:
        BookTreeNode(Book book);
        friend class BookTree;
};

class BookTree {
    private:
        BookTreeNode* root;
        BookTreeNode* insert(Book book, BookTreeNode* root, int serial);

        void flipColors(BookTreeNode* root);
        BookTreeNode* rotateLeft(BookTreeNode* root);
        BookTreeNode* rotateRight(BookTreeNode* root);

        int height(BookTreeNode* root);
        bool is_red(BookTreeNode* root);

    public:
        LLRBTree();

        void insert(Book book, int serial);

        void preorder(std::ostream& os= std::cout);
        void postorder(std::ostream& os= std::cout);
        void inorder(std::ostream& os = std::cout);
        void search(int serialNum);
        int height();
};

#endif //CSC_212_PROJECT_BOOKTREE_H
