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

    QueueIsNull(const char *cmessage) {
        message = cmessage;
    }
};


struct QueueOverflow {
    string message;

    QueueOverflow(const char *cmessage) {
        message = cmessage;
    }
};


class Queue {

private:
    int *arr;
    int first, last;
    int size, capacity;

public:
    Queue(int size);

    Queue(const Queue &);

    ~Queue();

    int shift();

    int getFirst();

    int getLast();

    void printQueue() const;

    void push(const int &elem);

    void clear();

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }


    class Iterator {

    private:
        Queue *queue;
        int current, count;

    public:
        Iterator(Queue &queue) {
            this->queue = &queue;
            current = -1;
            count = 0;
        }

        ~Iterator() {
            current = -1;
            count = 0;
            queue = nullptr;
        }

        inline void start() {
            current = queue->first;
        }

        inline void next() {
            current = (current + 1) % queue->capacity;
            count++;
        }

        inline bool finish() {
            return count == queue->size;
        }

        inline int getValue() {
            return queue->arr[current];
        }

    };

    Iterator iterator() {
        return Iterator(*this);
    }
};


Queue::Queue(int capacity) {
    this->capacity = capacity;
    size = 0;
    first = 0;
    last = -1;
    arr = new int[capacity];
}


Queue::Queue(const Queue &q) {
    capacity = q.capacity;
    size = q.size;
    first = q.first;
    last = q.last;

    arr = new int[capacity];
    for (int i = 0; i < capacity; i++) { arr[i] = q.arr[i]; }
}


int Queue::getFirst() {
    if (isEmpty()) throw QueueIsNull("Queue is empty");
    return arr[first];
}


int Queue::getLast() {
    if (isEmpty()) throw QueueIsNull("Queue is empty");
    return arr[last];
}


int Queue::shift() {
    if (isEmpty()) throw QueueIsNull("Queue is empty");

    first++;
    size--;

    if (first == capacity) {
        first = 0;
        return arr[capacity - 1];
    } else return arr[first - 1];
}


void Queue::printQueue() const {
    if (isEmpty()) throw QueueIsNull("Queue is empty");
    cout << endl << "Current queue: " << endl;
    cout << "#" << "\t" << "queue element" << endl;
    for (int i = first; i < size; i++) {
        cout << i << "\t" << arr[i] <<endl;
    }
    cout << endl;
}


void Queue::push(const int &elem) {
    if (size == capacity) throw QueueOverflow("Queue overflow!");
    if (last == capacity - 1) last = 0;
    //if (size == capacity - 1) last = 0;
    last++;
    arr[last] = elem;
    size++;


   // cout << first << ' ' << arr[first] << ' ' << last << ' ' << arr[last] << endl;
}


void Queue::clear() {
    first = 0;
    last = -1;
    size = 0;
}


Queue::~Queue() {
    delete[]arr;
}


#endif //CPP2_RINGBUFFER_RINGBUFFER_H
