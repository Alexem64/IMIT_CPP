#include <iostream>
#include <array>
#include "unitBox.h"
using namespace std;

//сумма ценностей всех коробок
int sumValue(Box arrBox[], int arrSize)
{
    int totalVal = 0;

    for (int i = 0; i < arrSize; i++)
    {
        totalVal += arrBox[i].getValue();
    }
    return totalVal;
}

//сумма длины, ширины и высоты всех коробок не превосходит заданного значения
bool isSumOfAllNotGreater(Box arrBox[], int arrSize, int max)
{
    int totalSumOfAll = 0;
    for (int i = 0; i < arrSize; i++)
    {
        totalSumOfAll += arrBox[i].getLength() + arrBox[i].getWidth() + arrBox[i].getHeight();

    }
    return totalSumOfAll <= max;
}

//максимальный вес коробок, объем которых не превышает maxV
double maxWeightNotBiggerV(Box arrBox[], int arrSize, int maxV)
{
    double weightThatFound = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arrBox[i].getLength()*arrBox[i].getWidth()*arrBox[i].getHeight() <= maxV)       //выбираем только интересные коробки
        {
            if (arrBox[i].getWeight() >= weightThatFound)                       //если текущий вес больше, чем вес уже найденного
            {
                weightThatFound = arrBox[i].getWeight();
            }
        }

    }
    return weightThatFound;
}
//отсортировать получаемый массив коробок и вернуть булево значение. сортируем пузырьковым методом
//другой вариант - найти минимальную коробку, потом следующую и т.д., посчитать что все укладываются друг в друга
bool isVpihyemoe(Box arrBox[], int arrSize)
{
    int swapCount;
    for (int j = 0; j < arrSize; j++)
    {
        swapCount = 0;
        for (int i = 0; i < arrSize - i; i++)
        {
            if ((arrBox[i].getHeight() > arrBox[i + 1].getHeight()) && (arrBox[i].getLength() > arrBox[i + 1].getLength()) && (arrBox[i].getWidth() > arrBox[i + 1].getWidth()))
            {
                swap(arrBox[i], arrBox[i + 1]);
                swapCount++;
            }
        }
        if (swapCount == 0) {
  //          cout << "Boxes've been sorted already " << endl;
            break;
        }
    }
    bool isPossible=false;

 //   cout << "Sorted boxes: " << endl;

    for (int k = 0; k < arrSize - 1; k++)
    {
 //       cout << arrBox[k].getLength() << ' ' << arrBox[k].getWidth() << ' ' << arrBox[k].getHeight() << ' ' << arrBox[k].getWeight() << endl;
 //       if (k == arrSize - 2) { cout << arrBox[k + 1].getLength() << ' ' << arrBox[k + 1].getWidth() << ' ' << arrBox[k + 1].getHeight() << ' ' << arrBox[k + 1].getWeight() << endl; }
        if ((arrBox[k].getHeight() < arrBox[k + 1].getHeight()) && (arrBox[k].getLength() < arrBox[k + 1].getLength()) && (arrBox[k].getWidth() < arrBox[k + 1].getWidth()))
        {
            isPossible = true;
        }
        else { isPossible = false;  break; }

    }
    return isPossible;
}

bool operator == (Box &a, Box &b)
{
    return (a.getLength() == b.getLength()) && (a.getHeight() == b.getHeight()) && (a.getValue() == b.getValue()) && (a.getWeight() == b.getWeight()) &&
           (a.getWidth() == b.getWidth());
}
istream & operator >> (istream & is, Box &a)
{
    int l,w,h,v;
    double wei;
     is >> l >> w >> h >> wei >> v;
    a.setLength(l);
    a.setWidth(w);
    a.setHeight(h);
    a.setWeight(wei);
    a.setValue(v);
    return is;
}

ostream & operator << (ostream & os, Box &a)
{
    return os << a.getLength() << ' ' << a.getWidth() << ' ' << a.getHeight() << ' ' << a.getWeight() << ' ' << a.getValue() << endl;
};



