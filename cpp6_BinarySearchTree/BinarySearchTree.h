//
// Created by alexem on 30.04.2020.
//
/*1. Реализовать частотный словарь слов на базе дерева двоичного поиска.
Частотный словарь хранит слова и количество вхождений каждого слова (в некоторый текст).
Методы:
– необходимые служебные методы (конструкторы, деструктор, операторы =),
– поиск слова в словаре, результат — количество вхождений,
– добавить слово в словарь (если слово встретилось впервые, то в дерево добавляется новый
узел, если нет, то для слова увеличивается счетчик числа вхождений),
– удалить слово из словаря (симметрично вставке: если для слова число вхождений больше 1,
то уменьшается счетчик, иначе удаляется узел дерева),
– общее количество слов в словаре с учетом числа вхождений слов,
– оператор вывода (выводит слова в алфавитном порядке с указанием количества
                   вхождений).
2. *То же самое, но на базе АВЛ-деревьев.
*/

#ifndef CPP6_BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define CPP6_BINARYSEARCHTREE_BINARYSEARCHTREE_H


#include <string>

using namespace std;

class BinarySearchTree {
private:
    struct Node {
        string word;
        int counter;
        Node *left;
        Node *right;
        Node(std::string word, int counter = 1, Node *left = nullptr, Node *right = nullptr) :
                word(word), counter(counter), left(left), right(right) {}
    };

    Node *root;
    Node* copy(const Node *root);
    void stolen(BinarySearchTree &tree);
    void clear(Node *&currentNode);
    int findCounter(string word, Node *root) const;
    void add(string word, Node *&root);
    void remove(string word, Node *&root);
    int countAllWords(Node *root) const;
    void print(ostream &stream, const Node *root) const;
    friend bool equal(const Node *left, const Node *right);

public:
    BinarySearchTree();
    BinarySearchTree(string word);
    BinarySearchTree(const BinarySearchTree &other);
    BinarySearchTree(BinarySearchTree &&other);
    ~BinarySearchTree();

    BinarySearchTree &operator=(const BinarySearchTree& other);
    BinarySearchTree &operator=(BinarySearchTree&& other);

    int findCounter(string word) const;
    void add(string word);
    void remove(string word);
    int countAllWords() const;

    void copy(const BinarySearchTree &other);
    void clear();

    friend ostream &operator <<(ostream &stream, const BinarySearchTree &tree);

    friend  bool operator==(const BinarySearchTree &lTree, const BinarySearchTree &rTree);
};


#endif //CPP6_BINARYSEARCHTREE_BINARYSEARCHTREE_H
