//
// Created by alexem on 28.03.2020.
//

#ifndef DOUBLY_LINKED_LIST_ABSTRACTDOUBLYLINKEDLIST_H
#define DOUBLY_LINKED_LIST_ABSTRACTDOUBLYLINKEDLIST_H

#include "string"

using namespace std;


template <typename Type>
struct Node {
    Type val;
    Node *next;
    Node *prev;
};


template <typename Type>
class AbstractIterator {
public:
    virtual void start() = 0;
    virtual Type getElem() = 0;
    virtual void next() = 0;
    virtual bool isFinished() = 0;
};


struct DoublyLinkedListIsEmpty {
    string message;

    DoublyLinkedListIsEmpty(const char *cmessage) {
        message = cmessage;
    }
};

template <typename Type>
class AbstractDoublyLinkedList {
public:
    virtual void insert(AbstractDoublyLinkedList<Type> *iter, Type val) = 0;
    virtual void deleteElem(AbstractDoublyLinkedList<Type> *iter) = 0;
    virtual void findElem(const Type&) = 0;
    virtual void clear() = 0;
    virtual bool isEmpty() = 0;
    virtual size_t getSize() = 0;
    virtual AbstractIterator<Type> *iter() = 0;
    virtual AbstractIterator<Type> *firstElem(Type) = 0;
};


#endif //DOUBLY_LINKED_LIST_ABSTRACTDOUBLYLINKEDLIST_H
