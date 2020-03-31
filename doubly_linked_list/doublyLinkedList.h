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
    ~DoublyLinkedList();

    void insert(AbstractDoublyLinkedList<Type> *iter, Type val);
    void deleteElem(AbstractDoublyLinkedList<Type> *iter);
    void findElem(const Type&);
    void clear();
    bool isEmpty();
    size_t getSize();

    Iterator *iterator() override {
        Iterator *iter = new Iterator(*this);
        iter->start();
        return iter;
        }

    Iterator *findElem(Type elem) {
        Iterator *iter = new Iterator(*this);
        iter->start();
        while(!iter->isFinished()) {
            if (iter->getElem() == elem) {return iter;}
            iter->next();
        }
        //TODO: exception?
};

};

#endif //DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
