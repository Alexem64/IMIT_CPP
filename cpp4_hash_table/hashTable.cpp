//
// Created by alexem on 22.04.2020.
//

#include <iostream>
#include "hashTable.h"

using namespace std;

int main() {
    HashTable<int, char> table(5);

    table.isEmpty() ? cout << "Table is empty" << endl  : cout << "Table is not empty" << endl;


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

    table.deleteNode(123);
    table.deleteNode(111);

    cout << table.getNodeValue(224) << endl;
    cout << table.getNodeValue(555) << endl;


 //   try { cout << table.getNodeValue(111); }
 //   catch (HashTableIsEmptyExcept &err) {cout << err.message << endl;}

//    try { table.deleteNode(123); }
//    catch (HashTableIsEmptyExcept &err) {cout << err.message << endl;}

    cout << "Let's try our delicious iterator" << endl;

    table.addNode(1, 'a');
    table.addNode(11, 'b');
    table.addNode(22, 'c');
    table.addNode(27, 'f');
    table.addNode(28, 'g');
    table.addNode(30, 'h');

   HashTable<int, char>::Iterator *iter = table.iterator();

    cout << "values by iterator: " << endl;
    while (!iter->isEmpty()) {
        cout << iter->getValue() << endl;
        iter->next();
    }

//    cout << "Let's try to find some not included value"  << endl;
//    try { table.findNode('d'); }
//    catch (ElemIsNotFoundExcept &err) { cout << err.message << endl; }

//   cout << "Let's try to find another value" << endl;
//    try { table.findNode('y'); }
//    catch (ElemIsNotFoundExcept &err) { cout << err.message << endl; }

    std::system("pause");
    return 0;
}