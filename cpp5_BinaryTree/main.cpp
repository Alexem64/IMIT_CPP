#include <iostream>
#include "BinaryTree.h"


int main() {
    BinaryTree btree(4);
    btree.addNode(1,{0});
    btree.addNode(11, {1});
    btree.addNode(2, {0, 0});
    btree.addNode(2, {0, 1});
    btree.addNode(0, {0, 1, 0});
    btree.addNode(55, {1, 1});
    btree.addNode(50, {1, 0});
    //добавляем элемент в уже занятый
    btree.addNode(30, {1, 0});
    //добавляем элемен по несуществующему пути
    try {btree.addNode(30, {1, 0, 1, 1, 1}); }
    catch (IncorrectSequenceExcept &err) {
        std::cout << err.message << std::endl;
    }

    std::cout << std::endl << "Here is our tree: " << btree << std::endl;
    std::cout << "Let's count all even numbers: " << btree.countEvenNodes() << std::endl;
    std::cout << "Let's count average of all numbers: " << btree.countAvg() << std::endl;
    std::cout << "Let's check sign of all numbers: " << btree.isPositive() << std::endl;

    std::cout << std::endl << "Let's delete leaves" << std::endl;
    btree.deleteLeaves();
    std::cout << "Here is our tree: " << btree << std::endl;
    std::cout << "Let's count all even numbers: " << btree.countEvenNodes() << std::endl;
    std::cout << "Let's count average of all numbers: " << btree.countAvg() << std::endl;

    std::cout << std::endl << "Let's clear our tree" << std::endl;

    btree.clear();

    btree.addNode(4, {});
    btree.addNode(1,{0});
    btree.addNode(11, {1});
    btree.addNode(2, {0, 0});
    btree.addNode(2, {0, 1});
    btree.addNode(0, {0, 1, 0});
    btree.addNode(55, {1, 1});
    btree.addNode(50, {1, 0});
    btree.addNode(-1, {1, 1, 1});

    std::cout << "Here is our new tree: " << btree << std::endl;
    std::cout << "Let's check sign of all numbers: " << btree.isPositive() << std::endl;

    std::vector<int> seq1 = btree.findNode(0);
    for (size_t i = 0; i< seq1.size(); i++) {
        std::cout << seq1[i] << " ";
    }

    try {
        std::vector<int> v3 = btree.findNode(111);
    }
    catch (IncorrectSequenceExcept &err) {
        std::cout << err.message << std::endl;
    }

    BinaryTree btree1(5);
    BinaryTree btree2 = btree;

    std::cout << "Let's compare trees" << (btree == btree1 ? " btree == btree1" : " btree != btree1") << std::endl;
    std::cout << "Let's compare trees" << (btree == btree2 ? " btree == btree2" : " btree != btree2") << std::endl;

    return 0;
}