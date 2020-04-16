//
// Created by alexem on 31.03.2020.
//

#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main() {

    DoublyLinkedList<int> list;
    cout << (list.isEmpty() ? "List of 'int' is empty" : "List of 'int' isn't empty") << endl;
    cout << "List's size is " << list.getSize() << endl;
    cout << "Let's push some elements!" << endl << endl;

    list.pushElem(1);
    list.pushElem(2);
    list.pushElem(3);
    list.pushElem(4);
    list.pushElem(5);
    list.pushElem(6);

    cout << (list.isEmpty() ? "List is empty" : "List isn't empty") << endl;
    cout << "List's size is " << list.getSize() << endl << endl;

    DoublyLinkedList<char> listCh;
    cout << (listCh.isEmpty() ? "List of 'char' is empty" : "List of 'char' isn't empty") << endl;
    cout << "ListCh's size is " << list.getSize() << endl;
    cout << "Let's push some elements!" << endl << endl;

    listCh.pushElem('a');
    listCh.pushElem('b');
    listCh.pushElem('c');
    listCh.pushElem('d');
    listCh.pushElem('e');
    listCh.pushElem('f');

    cout << (listCh.isEmpty() ? "ListCh is empty" : "ListCh isn't empty") << endl;
    cout << "ListCh's size is " << listCh.getSize() << endl << endl;

    DoublyLinkedList<int>::Iterator *it1 = list.iter();
    DoublyLinkedList<char>::Iterator *it2 = listCh.iter();

    it1->printListFromStart();
    it2->printListFromStart();

    DoublyLinkedList<int> list2 = list;
    DoublyLinkedList<int>::Iterator *it3 = list2.iter();

    it3->printListFromStart();

    cout << endl << "let's delete last elem from list2" << endl;

    it3->previous();
    list2.deleteElem(it3);

    it3->printListFromStart();

    cout << "Let's delete last elem from list2" << endl;

    it3->previous();
    list2.deleteElem(it3);
    it3->start();

    it3->printListFromStart();

    cout << endl << "Let's try clear function" << endl;

    list2.clear();
    cout << (list2.isEmpty() ? "List2 of 'int' is empty" : "List2 of 'int' isn't empty") << endl;
    cout << "List2's size is " << list2.getSize() << endl;

    list2.pushElem(1);
    list2.pushElem(12);
    list2.pushElem(123);


    cout << (list2.isEmpty() ? "List2 of 'int' is empty" : "List2 of 'int' isn't empty") << endl;
    cout << "List2's size is " << list2.getSize() << endl;


/*    DoublyLinkedList<int> list11;
    list11.pushElem(1);
    list11.pushElem(2);
    list11.pushElem(3);
    list11.pushElem(4);
    DoublyLinkedList<int>::Iterator* it11 = list11.iter();
    DoublyLinkedList<int>::Iterator* it12 = list11.iter();
*/

/*    it11->next();
    while (!it11->isFinished() || !it12->isFinished()) {
        cout << "it11 : " << it11->getElem() << "\t" << "it12 : " << it12->getElem() << endl;
        it11->next();
        it12->next();
    }
*/



    //it3->start();
   // it3->next();
   // list2.insert(it3,1234);

   // it3->printListFromStart();

    return 0;
}

