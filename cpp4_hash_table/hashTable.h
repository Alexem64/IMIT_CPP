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
   // Data<TKey, TValue> *begin;

};


struct SizeIncorrectExcept {
    std::string message;

    SizeIncorrectExcept(const char *cmessage) {
        message = cmessage;
    }
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
    inline int hash(const TKey key) const { return key % hash_table_size; }
    static const int DEFAULT_SIZE = 8;
public:
    class Iterator : public AbstractIterator<TKey, TValue> {
    private:
        Data<TKey, TValue> *current;
    public:
        Iterator(Data<TKey, TValue> *first) {
            this->current = first;
        }

        ~Iterator() {
            delete this->current;
        }

        void start() override {
            for (int i=0; i<hash_table_size; i++) {
                if  (table[i] != nullptr) {
                    this->current = table[i];
                    return;
                }
            }
            this->current = nullptr;
        }

        void next() override {
            if (this->current->next != nullptr) {
                this->current = this->current->next;
            }
            else {
            size_t current_table = hash(this->current->key);
            for (int i=0; i < (hash_table_size - current_table); i++) {
                if  (table[i] != nullptr) {
                    this->current = table[i];
                    return;
                    }
                }
            }
        }

        bool isEmpty() override {
            return this->current == nullptr;
        }

        TValue getValue() override {
            return this->current->value;
        }

    };

    HashTable();
    HashTable(int table_size);
    virtual ~HashTable();

    void addNode(const TKey &key, const TValue &value);
    void deleteNode(const TKey &key);
    TKey findNode(const TValue &value) const;
    bool isEmpty() const;
    void clear();
    TValue getNodeValue(const TKey &key);
    inline int size() const {return hash_table_size;}

    Iterator *iterator() {
        Iterator *iterator = new Iterator(table[0]);
        iterator->start();
        return iterator;
    }
};



template <typename TKey, typename TValue>
HashTable<TKey, TValue>::HashTable() {
    this->hash_table_size = DEFAULT_SIZE;
    this->table = new Data<TKey, TValue>*[hash_table_size];
    for(int i=0; i<hash_table_size; i++) {
        table[i] = nullptr;
    }
}


template <typename TKey, typename TValue>
HashTable<TKey, TValue>::HashTable(int table_size) {
    if (table_size < 0)
        throw SizeIncorrectExcept("Size is incorrect");
    this->hash_table_size = table_size;
    this->table = new Data<TKey, TValue>*[table_size];
    for(int i=0; i<table_size; i++) {
        table[i] = nullptr;
    }
}


template <typename TKey, typename TValue>
HashTable<TKey, TValue>::~HashTable() {
    this->clear();
    hash_table_size = 0;
}


template <typename TKey, typename TValue>
void HashTable<TKey, TValue>::addNode(const TKey &key, const TValue &value) {
    //чтобы не вычислять постоянно хэш, вычислим и запишем
    int hashTemp = hash(key);
    //если записей по данному ключу нет, то выдяляем память и складываем туда значения Key, Value, указатель на null.
    if (table[hashTemp] == nullptr) {
        table[hashTemp] = new Data<TKey, TValue>;
        table[hashTemp]->key = key;
        table[hashTemp]->value = value;
        table[hashTemp]->next = nullptr;
    }
    else //если записи есть, то надо дойти до последнего элемента по данному ключу (у него указатель на null) и поместить элемент за ним
        {
        Data<TKey, TValue> *last = table[hashTemp];
        while (last->next != nullptr)
            { last = last->next; }

        Data<TKey, TValue> *newNode = new Data<TKey, TValue>;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;
        last->next = newNode;
        }
}


template <typename TKey, typename TValue>
void HashTable<TKey, TValue>::deleteNode(const TKey &key) {
    if (isEmpty())
        throw HashTableIsEmptyExcept("Table is empty");

    int hashTemp = hash(key);
    //если указатель по вычисленному хэшу указывает на null, то обнуляем значения key, value по этому элементу
    if (table[hashTemp] == nullptr) {
        table[hashTemp]->key = 0;
        table[hashTemp]->value = 0;
    }
    else {
        //если у первого элемента совпадает key, его необходимо удалить, сохранив все последующие элементы списка
        if (table[hashTemp]->key == key) {
            Data<TKey, TValue> *temp = table[hashTemp];
            table[hashTemp] = temp->next;
            delete temp;
        }
        else {
            //если первый элемент не совпдает, необходимо проверить весь список с данным значением хэша
            Data<TKey, TValue> *currentNode = table[hashTemp];
            while ((currentNode->next->key != key) || (currentNode->next != nullptr))
                currentNode = currentNode->next;
            //если дошли до конца и не нашли элемент, то его нет
            if (currentNode->next == nullptr)
                throw ElemIsNotFoundExcept("Elem is not found");
            //при удалении элемента рассматриваем два случая - он последний в списке, тогда его просто удаляем.
            //Либо элемент не последний, тогда следует не потерять следующие за ним элементы.
            if (currentNode->next->next == nullptr) {
                delete currentNode->next;
                currentNode->next = nullptr;
            }
            else {
                Data<TKey, TValue> *temp = currentNode->next->next;
                delete currentNode->next;
                currentNode->next = temp;
            }
        }
    }
}


template <typename TKey, typename TValue>
TKey HashTable<TKey, TValue>::findNode(const TValue &value) const {
    if (isEmpty())
        throw HashTableIsEmptyExcept("Table is empty");

    for (int i=0; i<hash_table_size; i++) {
        Data<TKey, TValue> *currentNode = table[i];

        while (currentNode->next != nullptr) {
            if (currentNode->value == value) {
                return currentNode->key;
            }
            currentNode = currentNode->next;
        }
        //если дошли до конца и не нашли элемент, то его нет
    }

            throw ElemIsNotFoundExcept("Elem is not found");

}


template <typename TKey, typename TValue>
bool HashTable<TKey, TValue>::isEmpty() const {
    for (int i=0; i<hash_table_size; i++) {
        if (this->table[i] != nullptr) return false;
    }
    return true;
}


template <typename TKey, typename TValue>
void HashTable<TKey, TValue>::clear() {
    if (isEmpty()) return;

    //проходим по всем индексам (хэшам), очищаем все элементы списков, скидываем указатель этого индекса в null
    for(int i=0; i<hash_table_size; i++) {
        Data<TKey, TValue> *currentNode = table[i];
        Data<TKey, TValue> *temp = currentNode;
        while (currentNode != nullptr) {
            temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
        delete currentNode;
        this->table[i] = nullptr;
    }
}


template <typename TKey, typename TValue>
TValue HashTable<TKey, TValue>::getNodeValue(const TKey &key) {
    if (isEmpty())
        throw HashTableIsEmptyExcept("Table is empty");

    TValue founded_val;
    int hashTemp = hash(key);

    if (table[hashTemp]->next != nullptr) {
        Data<TKey, TValue> *currentNode = table[hashTemp];
        while (currentNode->key != key)
            currentNode = currentNode->next;
        founded_val = currentNode->value;
    }
    else {
        if (table[hashTemp]->key == key)
            founded_val = table[hashTemp]->value;
        else
            throw ElemIsNotFoundExcept("Elem is not found");
    }
    return founded_val;
}

#endif //CPP4_HASH_TABLE_HASHTABLE_H