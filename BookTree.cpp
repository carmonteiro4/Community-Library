#include "BookTree.h"

BookTreeNode::BookTreeNode(Book book) {
    this->left = nullptr;
    this->right = nullptr;
    color = 1;
    this->book = book;
    this->serial = book.serial;
}