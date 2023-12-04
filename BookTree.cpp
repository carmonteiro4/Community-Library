#include <vector>
#include "BookTree.h"

BookTreeNode::BookTreeNode(Book* book) {
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

BookTreeNode* BookTree::insert(Book* book, BookTreeNode* root){
    if (!root){
        return new BookTreeNode(book);
    }

    if (book->serial < root->book->serial){
        root->left = insert(book, root->left);
    } else {
        root->right = insert(book, root->right);
    }

    if (is_red(root->right) && !is_red(root->left)){
        root = rotateLeft(root);
    }

    if (is_red(root->left) && is_red(root->left->left)){
        root = rotateRight(root);
    }

    if (is_red(root->left) && is_red(root->right)){
        flipColors(root);
    }

    return root;
}

void BookTree::insert(Book* book){
    this->root = insert(book, root);
    this->root->color = 0;
}

void BookTree::flipColors(BookTreeNode* root){
    root->color = !root->color;
    root->left->color = !root->left->color;
    root->right->color = !root->right->color;
}

BookTreeNode* BookTree::rotateLeft(BookTreeNode* root){
    BookTreeNode* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    temp->color = root->color;
    root->color = 1;
    return temp;
}

BookTreeNode* BookTree::rotateRight(BookTreeNode* root){
    BookTreeNode* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    temp->color = root->color;
    root->color = 1;
    return temp;
}


bool BookTree::is_red(BookTreeNode* root){
    if (!root){
        return 0;
    } else {
        return root->color;
    }
}

void BookTree::preorder(BookTreeNode* root, std::ostream& os){
    if(!root){
        return;
    }

    os << root->book->serial << ":" << root->color << " ";
    this->preorder(root->left, os);
    this->preorder(root->right, os);

    return;
}


void BookTree::preorder(std::ostream& os){
    this->preorder(this->root, os);
    os << "\n";
}

int BookTree::height(BookTreeNode* root){
    if(!root){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left + 1 : right + 1);
}

int BookTree::height(){
    return this->height(this->root);
}

