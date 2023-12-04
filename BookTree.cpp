#include <vector>
#include <climits>
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

int BookTree::closestSerial(BookTreeNode* root, int serial, int &closest) {
    if (root == nullptr) return closest;

    if (root->book->serial == serial) {
        closest = serial;
        return closest;
    }

    if (std::abs(serial - root->book->serial) < std::abs(serial - closest)) {
        closest = root->book->serial;
    }

    if (serial < root->book->serial) {
        return closestSerial(root->left, serial, closest);
    } else {
        return closestSerial(root->right, serial, closest);
    }
}

int BookTree::closestSerial(int serial) {
    int closest = INT_MAX;
    return closestSerial(this->root, serial, closest);
}

bool BookTree::search(int closestSerial, BookTreeNode* root, BookTreeNode* &node){
    if(!root){
        return false;
    }

    if(closestSerial == root->book->serial){
        node = root;
        return true;
    }

    if(closestSerial < root->book->serial){
        return this->search(closestSerial, root->left, node);
    }else{
        return this->search(closestSerial, root->right, node);
    }
}

void BookTree::getSuggestions(int closestSerial, std::vector<Book>* suggestions) {
    BookTreeNode *node = nullptr;
    search(closestSerial, this->root, node);

    if (node->book != nullptr) {
        suggestions->emplace_back(node->book);

        if (node->left != nullptr) {
            suggestions->emplace_back(node->left->book);

            if (node->left->left != nullptr) {
                suggestions->emplace_back(node->left->left->book);
            }

            if (node->book != nullptr && node->left != nullptr && node->left->right != nullptr) {
                suggestions->emplace_back(node->left->right->book);
            }
        }

        if (node->right != nullptr) {
            suggestions->emplace_back(node->right->book);

            if (node->book != nullptr && node->right != nullptr && node->right->left != nullptr) {
                suggestions->emplace_back(node->right->left->book);
            }

            if (node->book != nullptr && node->right != nullptr && node->right->right != nullptr) {
                suggestions->emplace_back(node->right->right->book);
            }
        }
    }
}


