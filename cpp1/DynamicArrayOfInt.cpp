//
// Created by alexem on 01.11.2019.
//

#include "DynamicArrayOfInt.h"

//resize(newSize) – изменение размера (массив пересоздается, элементы копируются на новое
//место, старый массив разрушается; если новый размер меньше старого, не поместившаяся часть
//элементов теряется, если новый размер больше – добавляются элементы 0),
DynamicArrayOfInt DynamicArrayOfInt::resize(const int newSize) {
    //создали новый массив размером newSize, конструктор заполняет все элементы 0
    DynamicArrayOfInt newDAI(newSize);
    int minSize;
    if (newSize >= this->size) {
        minSize = this->size;
    } else minSize = newSize;
    for (int i = 0; i < minSize; i++) {
        newDAI.Array[i] = this->Array[i];
        cout << "newDAI[" << i << "]" << newDAI.Array[i] << " ";
    }
    for (int i = minSize; i < newSize; i++) {
        cout << "newDAI[" << i << "]" << newDAI.Array[i] << " ";
    }
    //TODO: создает массив с 0, cout можно убирать. а вот после - ошибка, разобраться с удалением старого массива
    // delete []this->Array;
    //delete []this;
    return newDAI;
    /*
    this->size = newSize;
    this->Array = new int[newSize];
    for (int i = 0; i < newSize; i++) {
        this->Array[i] = newDAI.Array[i];
        cout << "this->Array[" << i << "]" << this->Array[i] << " ";
    }
*/
}

bool DynamicArrayOfInt::operator==(const DynamicArrayOfInt &a) {
    if (this->size != a.size) { throw UnequalLengths("Lengths are not equal"); }
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] != a.Array[i]) return false;
    }
    return true;
}

bool DynamicArrayOfInt::operator!=(const DynamicArrayOfInt &a) {
    if (this->size != a.size) { throw UnequalLengths("Lengths are not equal"); }
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
        if (i == this->size--)
            return this->size > a.size;
    }
    return true;
}

bool DynamicArrayOfInt::operator>=(const DynamicArrayOfInt &a) {
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] > a.Array[i]) return true;
        if (this->Array[i] < a.Array[i]) return false;
        //если дошли до последнего символа, сравниваем длину.
        //очевидно, что если верхние условия не отработали, то текст совпадает
        if (i == this->size--)
            return this->size >= a.size;
    }
    return true;
}

bool DynamicArrayOfInt::operator<(const DynamicArrayOfInt &a) {
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] < a.Array[i]) return true;
        if (this->Array[i] > a.Array[i]) return false;
        //если дошли до последнего символа, сравниваем длину.
        //очевидно, что если верхние условия не отработали, то текст совпадает
        if (i == this->size--) return this->size < a.size;
    }
    return true;
}

bool DynamicArrayOfInt::operator<=(const DynamicArrayOfInt &a) {
    for (int i = 0; i < this->size; i++) {
        if (this->Array[i] < a.Array[i]) return true;
        if (this->Array[i] > a.Array[i]) return false;
        //если дошли до последнего символа, сравниваем длину.
        //очевидно, что если верхние условия не отработали, то текст совпадает
        if (i == this->size--) return this->size <= a.size;
    }
    return true;
}

/* операторы присваивания и перемещения
 оператор + (конкатенация массивов, m1 + m2 – это новый массив, в котором сперва идут
элементы m1, а затем – m2),
 операторы ввода / вывода.
*/
//оператор присваивания
DynamicArrayOfInt &DynamicArrayOfInt::operator=(const DynamicArrayOfInt &a) {
    if (this == &a)
        return *this;

    size = a.size;
    Array = new int[size];
    for (int i = 0; i < size; i++)
        Array[i] = a.Array[i];

    return *this;
}

//оператор перемещения
DynamicArrayOfInt &DynamicArrayOfInt::operator=(DynamicArrayOfInt &&a) {
    if (this == &a)
        return *this;
    delete []Array;

    size = a.size;
    Array = new int[size];
    for (int i = 0; i < size; i++)
        Array[i] = a.Array[i];
    a.Array = nullptr;

    return *this;
}

DynamicArrayOfInt operator+(const DynamicArrayOfInt &a, const DynamicArrayOfInt &b) {
    DynamicArrayOfInt arr(DynamicArrayOfInt(a.getLength() + b.getLength()));
    /*  for (int i = 0; i < a.getLength(); i++)
      {
          cout << "a[" << i << "]: " << a[i] << endl;
      }
      for (int i = 0; i < b.getLength(); i++)
      {
          cout << "b[" << i << "]: " << b[i] << endl;
      }
      cout << "arrLength: " << arr.getLength() << " aLength+bLength = " << a.getLength() << "+" << b.getLength() << "=" << a.getLength()+b.getLength();
   */
    for (int i = 0; i < arr.getLength(); i++) {
        if (i < a.getLength()) {
            arr[i] = a[i];
        } else {
            arr[i] = b[i - a.getLength()];
        }
    }
    return arr;
}

istream &operator>>(istream &is, DynamicArrayOfInt &a) {
    // int size;
    // int array[a.getLength()];
    // is >> size;
    for (int i = 0; i < a.getLength(); i++)
        is >> a[i];
    return is;
}

ostream &operator<<(ostream &os, DynamicArrayOfInt &a) {
    for (int i = 0; i < a.getLength(); i++)
        os << a[i] << ' ';
    return os;
}
