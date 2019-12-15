//
// Created by alexem on 15.12.2019.
//
/*
Задача 2. Кольцевой буфер.
1. Реализовать кольцевой буфер (очередь на базе массива) в виде класса. Размер буфера задается в конструкторе. Методы:
-- добавить элемент в конец очереди (при переполнении – исключение),
-- взять элемент в начале очереди (при отсутствии – исключение),
-- получить элемент в начале очереди (без его изъятия),
-- размер очереди,
-- сделать очередь пустой,
-- проверка очереди на пустоту.
2. Реализовать итератор на написанной очереди (в виде отдельного класса). Итератор представляет собой отдельный класс с методами:
void start(); // начать перебор элементов
void next(); // перейти к следующему элементу
bool finish(); // проверка, все ли проитерировано
int getValue(); // получить очередной элемент очереди
Также должен быть конструктор, который привязывает итератор к очереди.
*/


#ifndef CPP2_RINGBUFFER_RINGBUFFER_H
#define CPP2_RINGBUFFER_RINGBUFFER_H
#include "string"
using namespace std;

struct QueueIsNull {
    string message;
    QueueIsNull(const char * cText) {
        message = cText;
    }
};

struct QueueOverflow {
    string message;
    QueueOverflow(const char * cText) {
        message = cText;
    }
};

class Queue {
private:
    int *arr;
    int first, last;
    int size, capacity;
public:
    Queue (int size);
    Queue (const Queue&);
    ~Queue();

    int shift();
    int getFirst();
    void push(const int &elem);

    void clear();

    bool isEmpty() {
        return size==0;
    }

    int getSize() const {
        return size;
    }
    int getCapacity() const{
        return capacity;
    }
};

Queue::Queue(int capacity) {
    this->capacity = capacity;
    size=0;
    first=0;
    last=0;
    arr = new int[capacity];
}

Queue::Queue(const Queue &q) {
    capacity = q.capacity;
    size = q.size;
    first = q.first;
    last = q.last;

    arr = new int [capacity];
    for (int i=0; i < capacity; i++) { arr[i] = q.arr[i];}
}

int Queue::getFirst() {
    if (isEmpty()) throw QueueIsNull("Queue is empty");
    return arr[first];
}

int Queue::shift() {
    if (isEmpty()) throw QueueIsNull("Queue is empty");

    first++;
    size--;

    if (first == capacity) {
        first = 0;
        return arr[capacity-1];
    }
    else return arr[first-1];
}

void Queue::push(const int &elem) {
    if (size == capacity) throw QueueOverflow("Queue overflow!");
    if (last == capacity-1) last = 0;
    arr[last] = elem;
    size++;
}

void Queue::clear() {
    first=0;
    last=0;
    size=0;
}

Queue::~Queue() {
    delete []arr;
}
#endif //CPP2_RINGBUFFER_RINGBUFFER_H
