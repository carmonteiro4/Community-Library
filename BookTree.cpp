#include "BookTree.h"

BookTreeNode::BookTreeNode(Book book) {
    this->left = nullptr;
    this->right = nullptr;
    color = 1;
    this->book = book;
}

BookTree::BookTree(){
   this->root = nullptr;
}

BookTree::~BookTree(){
    delete this->root;
}

BookTreeNode* BookTree::insert(Book book, BookTreeNode* root){
    if(!root){
        return new LLRBNode(book);
    }

    // Go left if data < data at this Node
    if(book->serial < root->book->serial){
        root->left = insert(book, root->left);
        // Go right otherwise
    }else{
        root->right = insert(book, root->right);
    }

    // LLRBTree addition
    if (isRed(root->right) && !isRed(root->left)){
        root = rotateLeft(root);
    }

    if (isRed(root->left) && isRed(root->left->left)){
        root = rotateRight(root);
    }

    if (isRed(root->left) && isRed(root->right)){
        flipColors(root);
    }

    return root;
}


