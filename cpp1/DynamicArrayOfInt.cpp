//
// Created by alexem on 01.11.2019.
//

#include "DynamicArrayOfInt.h"

void DynamicArrayOfInt::resize(const int newSize) {

}

bool DynamicArrayOfInt::operator==(const DynamicArrayOfInt &a) {
    if (this->size != a.size) { throw ("Lengths are not equal"); }
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] != a.Array[i]) return false;
    }
    return true;
}

bool DynamicArrayOfInt::operator!=(const DynamicArrayOfInt &a) {
    if (this->size != a.size) { throw ("Lengths are not equal"); }
    bool result = false;
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] == a.Array[i]) result = false;
        else return true;

    }
    return result;
}

bool DynamicArrayOfInt::operator>(const DynamicArrayOfInt &a) {
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] > a.Array[i]) return true;
        if (this->Array[i] < a.Array[i]) return false;
        //если дошли до последнего символа, сравниваем длину.
        //очевидно, что если верхние условия не отработали, то текст до size-1 совпадает
        if (i == this->size--) return this->size > a.size;
    }
    return true;
}

bool DynamicArrayOfInt::operator>=(const DynamicArrayOfInt &a) {
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] > a.Array[i]) return true;
        if (this->Array[i] < a.Array[i]) return false;
        //если дошли до последнего символа, сравниваем длину.
        //очевидно, что если верхние условия не отработали, то текст совпадает
        if ((i == this->size--) && (this->size < a.size)) {
            return false;
        } else return true;
    }
    return true;
}

bool DynamicArrayOfInt::operator<(const DynamicArrayOfInt &a) {
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] < a.Array[i]) return true;
        if (this->Array[i] > a.Array[i]) return false;
        //если дошли до последнего символа, сравниваем длину.
        //очевидно, что если верхние условия не отработали, то текст совпадает
        if ((i == this->size--) && (this->size >= a.size)) {
            return false;
        } else return true;
    }
    return true;
}

bool DynamicArrayOfInt::operator<=(const DynamicArrayOfInt &a) {
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] < a.Array[i]) return true;
        if (this->Array[i] > a.Array[i]) return false;
        //если дошли до последнего символа, сравниваем длину.
        //очевидно, что если верхние условия не отработали, то текст совпадает
        if ((i == this->size--) && (this->size > a.size)) {
            return false;
        } else return true;
    }
    return true;
}

/* операторы присваивания и перемещения
 оператор + (конкатенация массивов, m1 + m2 – это новый массив, в котором сперва идут
элементы m1, а затем – m2),
 операторы ввода / вывода.
*/


DynamicArrayOfInt *operator+(const DynamicArrayOfInt &a, const DynamicArrayOfInt &b) {
    DynamicArrayOfInt arr;
    arr = DynamicArrayOfInt(a.getLength()+b.getLength());
    for (int i=0; i<v1.getDim, i++)
    {
        v3.set(i,v1.get(i)+v2.get(i));
    }
    return v3;
}

istream &operator>>(istream &is, DynamicArrayOfInt &a) {

}

ostream &operator<<(ostream &os, DynamicArrayOfInt &a) {

}
