//
// Created by alexem on 28.03.2020.
//

#ifndef DOUBLY_LINKED_LIST_ABSTRACTDOUBLYLINKEDLIST_H
#define DOUBLY_LINKED_LIST_ABSTRACTDOUBLYLINKEDLIST_H

#include "string"

using namespace std;


struct DoublyLinkedListIsEmpty {
    string message;

    DoublyLinkedListIsEmpty(const char *cmessage) {
        message = cmessage;
    }
};

template <typename Type>
class abstractDoublyLinkedList {
public:
    virtual void insert(abstractDoublyLinkedList<Type> *iter, Type val) = 0;
    virtual void deleteElem(abstractDoublyLinkedList<Type> *iter) = 0;
    virtual void findElem(const Type&) = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual size_t getSize() = 0;
    virtual abstractDoublyLinkedList<Type> *iter() = 0;
    virtual abstractDoublyLinkedList<Type> *firstElem(Type) = 0;
};



#endif //DOUBLY_LINKED_LIST_ABSTRACTDOUBLYLINKEDLIST_H
