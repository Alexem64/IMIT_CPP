//
// Created by alexem on 22.04.2020.
//
/*
 1. Напишите класс «Хэш-таблица» с методами:
 добавить элемент,
 удалить элемент,
 найти элемент,
 сделать таблицу пустой,
 проверка таблицы на пустоту.
Напишите итератор для этого класса.

 2*. Напишите класс «Связанная хэш-таблица», которая сохраняет порядок вставленных
элементов (аналог LinkedHashTable в Java). Элементы такой таблицы по мере их вставки в таблицу
должны включаться в дополнительный список.
Напишите итератор для этого класса, который перебирает элементы в том порядке, в котором
они были вставлены.
 */

#ifndef CPP4_HASH_TABLE_HASHTABLE_H
#define CPP4_HASH_TABLE_HASHTABLE_H


#include <string>

template <typename TKey, typename TValue>
struct Data {
    TKey key;
    TValue value;
    Data *next;
};

template <typename TKey, typename TValue>
class AbstractIterator {
public :
    virtual void start() =0 ;
    virtual void next() = 0;
    virtual bool isEmpty() = 0;
    virtual TValue getValue() = 0;
    virtual Data<TKey, TValue> *getTable() = 0;
};

struct HashTableIsEmptyExcept {
    std::string message;

    HashTableIsEmptyExcept(const char *cmessage) {
        message = cmessage;
    }
};

struct ElemIsNotFoundExcept {
    std::string message;

    ElemIsNotFoundExcept(const char *cmessage) {
        message = cmessage;
    }
};


template <typename TKey, typename TValue>
class HashTable {
private:
    size_t hash_table_size;

    Data<TKey, TValue> **table;
    inline int hash(TKey key) const { return key % hash_table_size; }
public:
    class Iterator : public AbstractIterator<TKey, TValue> {
    public:
        Iterator(Data<TKey, TValue> *first) {
            this->begin = first;
            this->start();
        }

        ~Iterator() {
            delete this->begin;
            delete this->current;
        }
    };

    HashTable();
    HashTable(int table_size);
    virtual ~HashTable();
    void addNode(const TValue &value);
    void deleteNode(const TValue &value);
    bool isEmpty();
    void clear();

};

#endif //CPP4_HASH_TABLE_HASHTABLE_H