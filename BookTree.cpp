#include "BookTree.h"

BookTreeNode::BookTreeNode(Book book) {
    this->left = nullptr;
    this->right = nullptr;
    color = 1;
    this->book;
}






























BookTreeNode* BookTree::insert(Book book, BookTreeNode* root, int serial){
    if(!root){
        return new BookTreeNode(data);
    }

    // Go left if data < data at this Node
    if(serial < root->serial){
        root->left = insert(serial, root->left);
        // Go right otherwise
    }else{
        root->right = insert(serial, root->right);
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