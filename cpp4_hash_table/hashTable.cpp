//
// Created by alexem on 22.04.2020.
//

#include <iostream>
#include "hashTable.h"

using namespace std;

int main() {
    HashTable<int, char> table(5);

    table.isEmpty() ? cout << "Table is empty" << endl : cout << "Table is not empty" << endl;


    table.addNode(123, 's');
    table.addNode(224, 'e');
    table.addNode(111, 'o');
    table.addNode(555, 'y');

    std::cout << table.getNodeValue(123) << endl;
    std::cout << table.getNodeValue(224) << endl;
    std::cout << table.getNodeValue(111) << endl;
    std::cout << table.getNodeValue(555) << endl;

    table.isEmpty() ? cout << "Table is empty" << endl  : cout << "Table is not empty" << endl;
    cout << endl << "Let's clear it!" << endl;
    table.clear();
    table.isEmpty() ? cout << "Table is empty" << endl  : cout << "Table is not empty" << endl;

    cout << endl << "Let's try get elem and delete" << endl;
    try { cout << table.getNodeValue(111); }
    catch (HashTableIsEmptyExcept &err) {cout << err.message << endl;}

    try { table.deleteNode(123); }
    catch (HashTableIsEmptyExcept &err) {cout << err.message << endl;}

    cout << "Let's add more chars and delete some of them" << endl;

    table.addNode(123, 's');
    table.addNode(224, 'e');
    table.addNode(111, 'o');
    table.addNode(555, 'y');


    std::cout << table.getNodeValue(123) << endl;
    std::cout << table.getNodeValue(224) << endl;
    std::cout << table.getNodeValue(111) << endl;
    std::cout << table.getNodeValue(555) << endl;

    //table.deleteNode(123);
    //table.deleteNode(111);


    std::cout << table.getNodeValue(224) << endl;
    std::cout << table.getNodeValue(555) << endl;

 //   cout << table.getNodeValue(224) << endl;
 //   cout << table.getNodeValue(555) << endl;


 //   try { cout << table.getNodeValue(111); }
 //   catch (HashTableIsEmptyExcept &err) {cout << err.message << endl;}

//    try { table.deleteNode(123); }
//    catch (HashTableIsEmptyExcept &err) {cout << err.message << endl;}



    table.addNode(1, 'a');
    table.addNode(11, 'b');
    table.addNode(10, 'c');
    table.addNode(12, 'd');
    table.addNode(13, 'f');

    cout << "Let's try our delicious iterator" << endl;

    HashTable<int, char>::Iterator* iterator = table.iterator();

    while (!iterator->isEmpty()) {
        cout << iterator->getValue() << endl;
        iterator->next();
    }

    cout << endl << "Let's try search again" << endl << endl;

    char found = 'a';
    try {
        cout << "find value = " << found << " key = " << table.findNode(found) << endl;
    }
    catch (ElemIsNotFoundExcept& error) { cout << error.message << endl; }

    std::system("pause");
    return 0;
}