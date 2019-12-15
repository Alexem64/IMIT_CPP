//
// Created by alexem on 01.11.2019.
//

#ifndef CPP1_DYNAMICARRAYOFINT_H
#define CPP1_DYNAMICARRAYOFINT_H
#include <iostream>
using namespace std;

class DynamicArrayOfInt {
    int size;
    int extraSize;
    int *Array;

public:
    DynamicArrayOfInt() {
        size = 4;
        Array = new int [size];
    }

    DynamicArrayOfInt(int sz) {
        size = sz;
        Array = new int[size];
        for (int i = 0; i < size; i++)
            Array[i] = 0;
    }

    DynamicArrayOfInt(int sz, int n) {
        size = sz;
        Array = new int[size];
        for (int i = 0; i < size; i++)
            Array[i] = n;
    }
//copy constructor
    DynamicArrayOfInt(const DynamicArrayOfInt &obj) {
        size = obj.size;
        Array = new int[obj.size];
        for (int i = 0; i < size; i++)
            Array[i] = obj.Array[i];
    }
//remove constructor
    DynamicArrayOfInt(DynamicArrayOfInt &&obj) noexcept {
        size = obj.size;
        Array = new int[obj.size];
        for (int i = 0; i < size; i++)
            Array[i] = obj.Array[i];
        obj.size = 0;
        obj.Array = nullptr;
    }

    ~DynamicArrayOfInt() {
        delete[]Array;
    }

    int getLength() const {
        return this->size;
    }

    int &operator[](int ind) {
        return this->Array[ind];
    }

    const int &operator[](const int ind) const {
        return this->Array[ind];
    }

    void resize(int);

    bool operator==(const DynamicArrayOfInt &a);

    bool operator!=(const DynamicArrayOfInt &a);

    bool operator>(const DynamicArrayOfInt &a);

    bool operator>=(const DynamicArrayOfInt &a);

    bool operator<(const DynamicArrayOfInt &a);

    bool operator<=(const DynamicArrayOfInt &a);

    DynamicArrayOfInt&operator=(const DynamicArrayOfInt&);

    DynamicArrayOfInt&operator=(DynamicArrayOfInt&&);

};
    DynamicArrayOfInt  operator + (const DynamicArrayOfInt & v1, const DynamicArrayOfInt &v2);

    istream &operator>>(istream &is, DynamicArrayOfInt &a);

    ostream &operator<<(ostream &os, DynamicArrayOfInt &a);

    struct UnequalLengths{
        string message;
        explicit UnequalLengths(const char* cmessage){
            message=cmessage;
        }
    };

/*    -- resize(newSize) – изменение размера (массив пересоздается, элементы копируются на новое
                                            место, старый массив разрушается; если новый размер меньше старого,
                                            не поместившаяся часть
            элементов теряется, если новый размер больше – добавляются элементы 0),
    -- операторы присваивания и перемещения,
    -- операторы == и != (поэлементное сравнение массивов, если массивы разных длин, то
    исключение),
    -- операторы <, <=, >, >= (сравнение в лексикографическом порядке, длины массивов не обязаны
            совпадать),
    -- оператор + (конкатенация массивов, m1 + m2 – это новый массив, в котором сперва идут
    элементы m1, а затем – m2),
    -- операторы ввода / вывода.
*/


#endif //CPP1_DYNAMICARRAYOFINT_H
