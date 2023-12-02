#ifndef CSC_212_PROJECT_BOOKTREE_H
#define CSC_212_PROJECT_BOOKTREE_H

#include <iostream>
#include <ostream>
//include "book.h"

class BookTree {

};

class BookTreeNode {
    private:
        //Book book;
        int serial;
        bool color;
        BookTreeNode* left;
        BookTreeNode* right;

    public:
        BookTreeNode();
        BookTreeNode(int node_val);
        friend class BookTree;
};

#endif //CSC_212_PROJECT_BOOKTREE_H
