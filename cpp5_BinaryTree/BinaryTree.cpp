//
// Created by alexem on 28.04.2020.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree() {
    root = new Node();
}

BinaryTree::BinaryTree(int value) {
    root = new Node(value);
}

BinaryTree::BinaryTree(const BinaryTree &other) {
        if (this == &other) return;
        root = copy(other.root);
}

BinaryTree::BinaryTree(BinaryTree &&other) {
    stolen(other);
}


BinaryTree& BinaryTree::operator=(const BinaryTree &other) {
    copy(other);
    return *this;
}

BinaryTree& BinaryTree::operator=(BinaryTree &&other) {
    if (this == &other) return *this;
    stolen(other);
    return *this;
}

BinaryTree::~BinaryTree() {
    clear();
    delete root;
}

void BinaryTree::clear() {
    clear(root);
}

void BinaryTree::clear(Node *&currentNode) {
    if (currentNode == nullptr) return;
    clear(currentNode->left);
    clear(currentNode->right);

    delete currentNode;
    currentNode = nullptr;
}

void BinaryTree::addNode(int value, const std::vector<int>& seq) {
    if (root == nullptr) root = new Node;
    if (seq.empty()) root->value = value;
    addNode(value, 0, seq, root);
}

bool BinaryTree::addNode(int value, int index, const std::vector<int>& seq, Node *&currentNode) {
    if (seq.size() == index) {
        if (currentNode == nullptr) {
            currentNode = new Node(value);
            return true;
        }
        else {
            currentNode->value = value;
        }
        return true;
    }
    if (currentNode == nullptr) {
        throw IncorrectSequenceExcept("Incorrect sequence");
    }
    if ((seq[index] == 0) && (addNode(value, ++index, seq, currentNode->left))) return true;
    //если
    return (seq[index] == 1) && (addNode(value, ++index, seq, currentNode->right));

}

int BinaryTree::countEvenNodes() {
    return countEvenNodes(root);
}

int BinaryTree::countEvenNodes(Node *currentNode) {
    if (currentNode == nullptr) return 0;
    return countEvenNodes(currentNode->left) + countEvenNodes(currentNode->right) + (currentNode->value % 2 == 0 ? 1 : 0);
}

bool BinaryTree::isPositive() {
    return isPositive(root);
}

bool BinaryTree::isPositive(Node *currentNode) {
    if (currentNode == nullptr) return true;
    return (currentNode->value > 0) && isPositive(currentNode->left) && isPositive(currentNode->right);
}

void BinaryTree::deleteLeaves() {
    deleteLeaves(root);
}

bool BinaryTree::deleteLeaves(Node *&currentNode) {
    if (currentNode == nullptr) return false;
    if (currentNode->left == nullptr && currentNode->right == nullptr) {
        delete currentNode;
        currentNode == nullptr;
        return true;
    }
    else {
        if (deleteLeaves(currentNode->left))
            currentNode->left = nullptr;
        if (deleteLeaves(currentNode->right))
            currentNode->right = nullptr;
        return false;
    }
}

double BinaryTree::countAvg() {
    int sum = 0;
    int count = 0;
    countAvg(root, count, sum);
    if (count == 0)
        throw BinaryTreeIsEmptyExcept();
    return (double)sum/count;
}

void BinaryTree::countAvg(Node *currentNode, int &count, int &sum) {
    if (currentNode == nullptr) return;
    countAvg(currentNode->left, count, sum);
    countAvg(currentNode->right, count, sum);
    sum += currentNode->value;
    count++;
}

std::vector<int> BinaryTree::findNode(int value) {
    if (this->root == nullptr)
        throw BinaryTreeIsEmptyExcept();
    std::vector<int> seq;
    if (findNode(root, value, seq)) {
        return seq;
    }
    return {};
}

bool BinaryTree::findNode(Node *currentNode, int value, std::vector<int> &seq) {
    if (currentNode == nullptr) {
        seq.pop_back();
        return false;
    }
    if (currentNode->value == value)
        return true;
    seq.push_back(0);
    if (findNode(currentNode->left, value, seq))
        return true;
    seq.push_back(1);
    if (findNode(currentNode->right, value, seq))
        return true;
    if (seq.size() == 0)
        throw IncorrectSequenceExcept();
    seq.pop_back();
    return false;
}

std::ostream& operator<<(std::ostream &stream, const BinaryTree &tree) {
    BinaryTree::print(stream, tree.root);
    return stream;
}

void BinaryTree::print(std::ostream &stream, const Node *currentNode) {
    if (currentNode == nullptr)
        return;
    print(stream, currentNode->left);
    stream << currentNode->value << " ";
    print(stream, currentNode->right);
}

bool operator==(const BinaryTree &lTree, const BinaryTree &rTree) {
    if (&lTree == &rTree)
        return true;
    return equals(lTree.root,rTree.root);
}

bool equals(const BinaryTree::Node *lNode, const BinaryTree::Node *rNode) {
    if (lNode == nullptr || rNode == nullptr)
        return lNode == rNode;
    return lNode->value == rNode->value && equals(lNode->left, rNode->left) && equals(lNode->right, rNode->right);
}

void BinaryTree::copy(const BinaryTree &tree) {
    if (this == &tree)
        return;
    clear();
    copy(tree.root);
}

BinaryTree::Node* BinaryTree::copy(BinaryTree::Node *currentNode) {
    if (currentNode == nullptr)
        return nullptr;
    return new Node(currentNode->value, copy(currentNode->left), copy(currentNode->right));
}

void BinaryTree::stolen(BinaryTree &tree) {
    root = tree.root;
    tree.root = nullptr;
}