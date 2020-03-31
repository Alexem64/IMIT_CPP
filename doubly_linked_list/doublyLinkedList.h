//
// Created by alexem on 31.03.2020.
//

#ifndef DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
#define DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H

#include "abstractDoublyLinkedList.h"

template<typename Type>
class DoublyLinkedList : public AbstractDoublyLinkedList<Type> {
public:
    class Iterator : public AbstractIterator<Type> {
    private:
        DoublyLinkedList *ptrList;

    public:

        Iterator(DoublyLinkedList<Type> &curObj) {
            ptrList = &curObj;
        }

        ~Iterator() {
            ptrList = nullptr;
        }

        Iterator &operator=(DoublyLinkedList<Type> &obj) {
            ptrList = obj;
            return *this;
        }

        void start() override {
            ptrList->current = ptrList->root->next;
        }

        Type getElem() override {
            return ptrList->current->val;
        }

        void next() override {
            ptrList->current = ptrList->current->next;
        }

        bool isFinished() override {
            return ptrList->current == ptrList->root;
        }
    };


    //конструкторы и операторы
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<Type> &obj);
    DoublyLinkedList &operator=(const DoublyLinkedList<Type> &obj);
    DoublyLinkedList(DoublyLinkedList<Type> &&obj);
    DoublyLinkedList &operator=(DoublyLinkedList<Type> &&obj);
};

};

#endif //DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
