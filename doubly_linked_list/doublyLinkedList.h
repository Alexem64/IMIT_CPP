//
// Created by alexem on 31.03.2020.
//

#ifndef DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
#define DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H

#include "abstractDoublyLinkedList.h"

template<typename Type>
class DoublyLinkedList : public AbstractDoublyLinkedList<Type> {
private:
    Node<Type> *root;
    Node<Type> *current;
    size_t size;

    void createDoublyLinkedList() {
            auto *temp = new Node<Type>;
            root = temp;
            temp->next = root;
            temp->prev = root;
            current = root;
            size=0;
        }

public:
    class Iterator : public AbstractIterator<Type> {
    private:
        DoublyLinkedList *ptrList;

    public:

        explicit Iterator(DoublyLinkedList<Type> &curObj) {
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

        void previous() override {
            ptrList->current = ptrList->current->prev;
        }

        bool isFinished() override {
            return ptrList->current == ptrList->root;
        }

        Node<Type> *getNode() {
            return ptrList->current;
        }

        void printListFromStart() {
            start();
            while (!isFinished()) {
                cout << "iter: " << getElem() << endl;
                next();
            }
        }

        bool iteratorIsFounded() {
            return (ptrList = true);
        }
    };


    //конструкторы и операторы
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<Type> &obj);
    DoublyLinkedList &operator=(const DoublyLinkedList<Type> &obj);
    DoublyLinkedList(DoublyLinkedList<Type> &&obj) noexcept;
    DoublyLinkedList &operator=(DoublyLinkedList<Type> &&obj) noexcept;
    ~DoublyLinkedList();


    void insert(AbstractIterator<Type> *iter, Type elem);
    void deleteElem(AbstractIterator<Type> *iter);
    void pushElem(const Type &elem);
    void clear();
    bool isEmpty();
    size_t getSize();


    Iterator *iter() override {
        auto *iter = new Iterator(*this);
        iter->start();
        return iter;
        }

    Iterator *findElem(Type elem) {
        auto *iter = new Iterator(*this);
        iter->start();
        while(!iter->isFinished()) {
            if (iter->getElem() == elem) {return iter;}
            iter->next();
        }
        throw ElemIsNotFound("Elem is not found");
};

};


template <typename Type>
DoublyLinkedList<Type>::DoublyLinkedList() {
    createDoublyLinkedList();
    }

template <typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(const DoublyLinkedList<Type> &obj) {
    createDoublyLinkedList();
    Node<Type> *ptr = obj.root->next;
    for (size_t i = 0; i < obj.size; i++) {
        pushElem(ptr->val);
        ptr = ptr->next;
    }
}

template <typename Type>
bool DoublyLinkedList<Type>::isEmpty() {return size==0;}


template <typename Type>
size_t DoublyLinkedList<Type>::getSize() {return size;}


template <typename Type>
DoublyLinkedList<Type> &DoublyLinkedList<Type>::operator=(const DoublyLinkedList<Type> &obj) {
    if (this == &obj) {return *this;}
    if (!isEmpty()) {clear();}

    Node<Type> *ptr = obj.root->next;
    for (size_t i = 0; i<obj.size; i++) {
        pushElem(ptr->val);
        ptr = ptr->next;
    }

    delete ptr;
    return *this;
}

template <typename Type>
DoublyLinkedList<Type>::DoublyLinkedList(DoublyLinkedList<Type> &&obj) noexcept {
    createDoublyLinkedList();

    size = obj.size;
    root = obj.root;
    current = obj.current;

    obj.size = 0;
    obj.root = nullptr;
    obj.current = nullptr;
}

template <typename Type>
DoublyLinkedList<Type> &DoublyLinkedList<Type>::operator=(DoublyLinkedList<Type> &&obj) noexcept {
    if (this->root == obj.root) {return *this;}
    if (!isEmpty()) {clear();}

    size = obj.size;
    root = obj.root;
    current = obj.current;

    obj.size = 0;
    obj.root = nullptr;
    obj.current = nullptr;
}

template <typename Type>
void DoublyLinkedList<Type>::insert(AbstractIterator<Type> *iter, const Type elem) {
    auto *insertedNode = new Node<Type>;
    insertedNode->val = elem;
    Node<Type> *currentNode = iter->getNode();
    Node<Type> *nextNode = currentNode->next;

    currentNode->next = insertedNode;
    insertedNode->prev = currentNode;
    insertedNode->next = nextNode;
    nextNode->prev = insertedNode;

    size++;
}

template <typename Type>
void DoublyLinkedList<Type>::deleteElem(AbstractIterator<Type> *iter) {
    if (isEmpty()) throw DoublyLinkedListIsEmpty("List is empty!");
    Node<Type> *deletedNode = iter->getNode();
    iter->next();
    Node<Type> *nextNode = deletedNode->next;
    Node<Type> *prevNode = deletedNode->prev;

    nextNode->prev = deletedNode->prev;
    prevNode->next = deletedNode->next;

    delete deletedNode;

    size--;
}

template <typename Type>
void DoublyLinkedList<Type>::pushElem(const Type &elem) {
    auto *pushedNode = new Node<Type>;
    pushedNode->val = elem;
    pushedNode->next = current->next;
    pushedNode->prev = current;

    Node<Type> *nextNode = current->next;
    nextNode->prev = pushedNode;
    current->next = pushedNode;

    current = current->next;
    size++;
}


template <typename Type>
void DoublyLinkedList<Type>::clear() {
    if (isEmpty()) {throw DoublyLinkedListIsEmpty("List is empty");}

    current = root;

    while (!isEmpty()) {
    Node<Type> *nextNode = current->next;
    nextNode->prev = current->prev;
    current->prev->next = nextNode;
    delete current;

    current = nextNode;
    size--;
    }
    auto *iter = new Iterator(*this);
    iter->start();
}

template <typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList() {
    clear();
    root = nullptr;
    current = nullptr;
}

#endif //DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
