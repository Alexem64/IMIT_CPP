#include <iostream>
#include "BinarySearchTree.h"

int main() {
    cout << "Let's create new BST with root 'Test' " << endl;

    BinarySearchTree tree1("Test");
    cout << "Here it is: " << endl << tree1 << endl;

    cout << "Let's find count of 'Test' in our BST " << endl << "It is " << tree1.findCounter("Test") << endl;
    cout << "Let's add some more staff" << endl;
    tree1.add("Test");
    tree1.add("Test123");
    tree1.add("Test123");
    tree1.add("Test123");
    tree1.add("Testtest");
    tree1.add("Test123");
    tree1.add("Test123");
    tree1.add("Testtest");
    tree1.add("Testtest");
    tree1.add("Abyrvalg");
    tree1.add("Glavryba");

    cout << "Here it is from left to right: " << endl;
    cout << tree1 << endl;
    cout << "Let's find count of 'Test' in our BST " << endl << "It is " << tree1.findCounter("Test") << endl;
    cout << "Let's find count of 'Test123' in our BST " << endl << "It is " << tree1.findCounter("Test123") << endl;
    cout << "Let's find count of all words in our BST " << endl << "It is " << tree1.countAllWords() << endl;

    cout << "Jokes are over. It's time to check other constructors and operators." << endl;

    BinarySearchTree tree2(tree1);
    BinarySearchTree tree3 = tree1;
    BinarySearchTree tree4(move(tree1));

    cout << "Here's tree2, copy of tree1, which made with copy constructor: " << endl << tree2 << endl;
    cout << "Here's tree3, copy of tree1, which made with assigment operator: " << endl << tree3 << endl;
    cout << "Here's tree4, copy of tree1, which made with remove constructor: " << endl << tree4 << endl;
    cout << "Here's our tree1, that have to be empty: " << endl;
    cout << "****************************************************************" << endl;
    cout << tree1 << endl;
    cout << "****************************************************************" << endl;
    cout << "If you haven't seen anything between strings with stars - tree1 is empty" << endl;

    cout << "Let's try to clear something" << endl;
    tree4.clear();
    cout << "Here grew the tree4 and now it's empty: " << tree4 << endl;
    cout << "Let's remove 'Test' from tree3" << endl;
    cout << tree3 << endl;
    tree3.remove("Test");
    cout << "Let's remove 'Test' from tree3 again and again" << endl;
    tree3.remove("Test");
    cout << tree3 << endl;
    tree3.remove("Test");
    cout << tree3 << endl;
    cout << "It doesn't work correctly, need time to find kosyaki, but I've run out of time for now" << endl;



    return 0;
}