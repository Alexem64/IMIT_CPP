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

    std::cout << "Let's test our operator of comparision " << std::endl;
    BinaryTree btree1(5);
    BinaryTree btree2 = btree;

    std::cout << "Here is our tree: " << btree << std::endl;
    std::cout << "Here is our new tree1: " << btree1 << std::endl;
    std::cout << "Here is our copy of tree - btree2: " << btree2 << std::endl;

    std::cout << "Let's compare trees" << (btree == btree1 ? " btree == btree1" : " btree != btree1") << std::endl;
    std::cout << "Let's compare trees" << (btree == btree2 ? " btree == btree2" : " btree != btree2") << std::endl;

    std::cout << "In previous commit I missed left and right and comparision didn't work correctly - life's so unfair!" << std::endl;

    std::cout << "Let's test our remove constructor " << std::endl;

    std::cout << "Let's test our copy constructor " << std::endl;
    BinaryTree btree3(btree2);
    std::cout << "Let's compare trees btree3 and btree" << (btree == btree3 ? " btree == btree3" : " btree != btree3") << std::endl;

    std::cout << "Let's test our move constructor " << std::endl;
    BinaryTree btree4(std::move(btree2));
    std::cout << "Let's compare trees btree4 and btree" << (btree == btree4 ? " btree == btree4" : " btree != btree4") << std::endl;

    std::cout << "Let's compare trees btree2 and btree" << (btree == btree2 ? " btree == btree2" : " btree != btree2") << std::endl;

    std::cout << "Here is our tree: " << btree << std::endl;
    std::cout << "Here is our tree1: " << btree1 << std::endl;
    std::cout << "Here is our copy of tree - btree2, which was removed: " << btree2 << std::endl;
    std::cout << "Here is our copy of tree - btree3, which was created with copy constructor: " << btree3 << std::endl;
    std::cout << "Here is our copy of tree - btree4, which was created with remove constructor: " << btree4 << std::endl;


    return 0;
}