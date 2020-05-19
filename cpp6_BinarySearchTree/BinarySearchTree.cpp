//
// Created by alexem on 30.04.2020.
//

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = new Node("bstree");
}

BinarySearchTree::BinarySearchTree(string word) {
    root = new Node(word);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &other) {
    root = copy(other.root);
}

BinarySearchTree::BinarySearchTree(BinarySearchTree &&other) {
    stolen(other);
}

BinarySearchTree::~BinarySearchTree() {
    clear();
    delete root;
}

BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &other)  {
    copy(other);
    return *this;
}

BinarySearchTree &BinarySearchTree::operator=(BinarySearchTree &&other) {
    if (this == &other)
        return *this;
    stolen(other);
    return *this;
}

void BinarySearchTree::stolen(BinarySearchTree &tree) {
    root = tree.root;
    tree.root = nullptr;
}

void BinarySearchTree::copy(const BinarySearchTree &other) {
    if (this == &other)
        return;
    clear();
    root = copy(other.root);
}

BinarySearchTree::Node *BinarySearchTree::copy(const Node *currentNode) {
    if (currentNode == nullptr)
        return nullptr;
    return new Node(currentNode->word, currentNode->counter, copy(currentNode->left), copy(currentNode->right));
}

void BinarySearchTree::clear() {
    clear(this->root);
}

void BinarySearchTree::clear(Node *&currentNode) {
    if (currentNode == nullptr)
        return;
    clear(currentNode->left);
    clear(currentNode->right);
    delete currentNode;
    currentNode = nullptr;
}

int BinarySearchTree::findCounter(string word) const{
    return findCounter(word, root);
}

int BinarySearchTree::findCounter(string word, Node *currentNode) const{
    if (currentNode == nullptr)
        return 0;
    if (currentNode->word == word)
        return currentNode->counter;
    if (word < currentNode->word)
        return findCounter(word, currentNode->left);
    if (word > currentNode->word)
        return findCounter(word, currentNode->right);
    return 0;
}

void BinarySearchTree::add(string word) {
    add(word, root);
}

void BinarySearchTree::add(string word, Node *&currentNode) {
    if (currentNode == nullptr) {
        currentNode = new Node(word);
        return;
    }
    if (currentNode->word == word) {
        currentNode->counter++;
        return;
    }
    if (word < currentNode->word) {
        add(word, currentNode->left);
        return;
    }
    if (word > currentNode->word) {
        add(word, currentNode->right);
        return;
    }
    return;
}

// находим минимальный элемент в (под)дереве
BinarySearchTree::Node* BinarySearchTree::min(BinarySearchTree::Node *currentNode) const {
    if (currentNode == nullptr)
        return nullptr;
    if (currentNode->left == nullptr)
        return currentNode;
    return min(currentNode->left);
}
/*
string BinarySearchTree::findNext(string word) const {
    return 0; //findNext(word, root)
}

//метод для нахождения следующего элемента - требуется для реализации insert
BinarySearchTree::Node* BinarySearchTree::findNext(string word, BinarySearchTree::Node *currentNode) const {
    if (currentNode == nullptr)
        return nullptr;
    Node *way = root;
    Node *successor = nullptr;
    while (way != nullptr) {
        if (way->word > currentNode->word) {
            successor = way;
            way = way->left;
        }
        else {
            way = way->right;
        }
    }
    return successor;
} */

void BinarySearchTree::remove(string word) {
    remove(word, root);
}

void BinarySearchTree::remove(string word, BinarySearchTree::Node *&currentNode) {
    if (currentNode == nullptr)
        return;
    if (word < currentNode->word) {
        remove(word, currentNode->left);
        return;
    }
    if (word > currentNode->word) {
        remove(word, currentNode->right);
        return;
    }

    if (word == currentNode->word) {
        if (currentNode->counter == 1) {
            if (currentNode->left == nullptr) {
                Node *ptrCur = currentNode;
                currentNode = currentNode->right;
                delete ptrCur;
                return;
            } else if (currentNode->right == nullptr) {
                Node *ptrCur = currentNode;
                currentNode = currentNode->left;
                delete ptrCur;
                return;
            } else if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                return;
            } else {
             //    cout << "CurNode: " << currentNode << currentNode->word << currentNode->left->word << currentNode->right->word << endl;
                Node *minNode = min(currentNode->right);
             //    cout << "minNode: " << minNode << minNode->word  << endl;
                currentNode->word = minNode->word;
                currentNode->counter = minNode->counter;
                remove(minNode->word, currentNode->right);
         //       cout << "CurNode: " << currentNode << currentNode->word << currentNode->left->word << currentNode->right->word << endl;
          //      cout << "minNode: " << minNode << minNode->word  << endl;
                return;
            }
        }
        if (currentNode->counter > 1) {
            currentNode->counter--;
            return;
        }
    }
}

int BinarySearchTree::countAllWords() const{
    return countAllWords(root);
}

int BinarySearchTree::countAllWords(BinarySearchTree::Node *currentNode) const{
    if (currentNode == nullptr)
        return 0;
    return root->counter + countAllWords(currentNode->left) + countAllWords(currentNode->right);
}


ostream &operator<<(ostream &stream, const BinarySearchTree &tree) {
    tree.print(stream, tree.root);
    return stream;
}

void BinarySearchTree::print(ostream &stream, const Node *currentNode) const {
    if (currentNode == nullptr)
        return;
    print(stream, currentNode->left);
    stream << currentNode->word << " (" << currentNode->counter << ")" << "\t";
    print(stream, currentNode->right);
}

bool operator==(const BinarySearchTree &lTree, const BinarySearchTree &rTree) {
    if (&lTree == &rTree)
        return true;
    return equal(lTree.root, rTree.root);
}

bool equal(const BinarySearchTree::Node *lNode, const BinarySearchTree::Node *rNode) {
    if (lNode == nullptr && rNode == nullptr)
        return true;
    if (lNode == nullptr || rNode == nullptr)
        return false;
    return ((lNode->word == rNode->word) && (lNode->counter == rNode->counter) &&
            equal(lNode->left, rNode->left) && equal(lNode->right, rNode->right));
}