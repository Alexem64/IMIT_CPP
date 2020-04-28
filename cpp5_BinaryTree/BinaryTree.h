//
// Created by alexem on 28.04.2020.
//
/*Реализовать класс «Двоичное дерево целых чисел».
Методы:
– служебные (конструкторы, деструктор, операторы присваивания),
– вставка элемента в дерево. Метод получает на вход число x, которое нужно вставить, и
последовательность из 0 и 1, кодирующую путь в дереве: 0 – переход к левому потоку
текущего узла, 1 – к правому. Если путь ведет в уже существующий узел, то число в нем
заменяется на x. Если путь проходит через лист дерева и заканчивается на уровень ниже,
то в это место добавляется новый узел как потомок листа. В остальных случаях — ошибка.
– оператор вывода (вывод всех элементов дерева в поток слева направо).
2. Добавьте в написанный класс методы:
– количество четных чисел в дереве,
– проверка того, что в дереве только положительные числа (в пустом дереве считаем
        результат true),
– удаление в дереве всех листьев (при этом листьями станут новые узлы, их не трогаем),
– среднее арифметическое всех чисел в дереве,
– поиск заданного элемента x в дереве (если такое число входит в дерево несколько раз,
                                       то одного любого вхождения), результат — путь от корня к найденному узлу в виде
массива из 0 и 1. Массив можно хранить в виде объекта класса std::vector.
*/
#ifndef CPP5_BINARYTREE_BINARYTREE_H
#define CPP5_BINARYTREE_BINARYTREE_H


#include <vector>
#include <ostream>



struct IncorrectSequenceExcept {
    std::string message;
    IncorrectSequenceExcept() {
        message = "Incorrect sequence";
    }
    IncorrectSequenceExcept(const char *cmessage) {
        message = cmessage;
    }
};

struct BinaryTreeIsEmptyExcept {
    std::string message;
    BinaryTreeIsEmptyExcept() {
        message = "Binary tree is empty";
    }

    BinaryTreeIsEmptyExcept(const char *cmessage) {
        message = cmessage;
    }
};

class BinaryTree {
private:
    struct Node {
        int value;
        Node *left;
        Node *right;
        Node(int value = 0, Node *left = nullptr, Node *right = nullptr): value(value), left(left), right(right) {}
    };
    Node *root;

    bool addNode(int value, int index, const std::vector<int>& seq, Node *&root);
    int countEvenNodes(Node *root);
    bool isPositive(Node *root);
    bool deleteLeaves(Node *&root);
    void countAvg(Node *root, int& count, int& sum);
    bool findNode(Node *root, int value, std::vector<int>& seq);

    static void print(std::ostream &stream, const Node *root);
    friend bool equals(const Node *lNode, const Node *rNode);

    void clear(Node *&root );
    Node *copy(Node *root);
    void stolen(BinaryTree& tree);

public:
    BinaryTree();
    BinaryTree(int value);
    BinaryTree(const BinaryTree &other);
    BinaryTree(BinaryTree &&other);

    BinaryTree &operator=(const BinaryTree &other);
    BinaryTree &operator=(BinaryTree &&other);

    virtual ~BinaryTree();

    void addNode(int value, const std::vector<int>& seq);

    friend std::ostream &operator <<(std::ostream &stream, const BinaryTree &tree); //слева направо
    friend bool operator==(const BinaryTree &lTree, const BinaryTree &rTree);
    int countEvenNodes();
    bool isPositive();
    void deleteLeaves();
    double countAvg();
    std::vector<int> findNode(int value);
    void clear();
    void copy(const BinaryTree &tree);

};


#endif //CPP5_BINARYTREE_BINARYTREE_H
