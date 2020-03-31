#include <iostream>
#include <array>
#include "unitBox.h"
using namespace std;

//sum of values of all boxes
int sumValue(Box arrBox[], int arrSize)
{
    int totalVal = 0;

    for (int i = 0; i < arrSize; i++)
    {
        totalVal += arrBox[i].value;
    }
    return totalVal;
}

//сумма длины, ширины и высоты всех коробок не превосходит заданного значения
bool isSumOfAllNotGreater(Box arrBox[], int arrSize, int max)
{
    int totalSumOfAll = 0;
    for (int i = 0; i < arrSize; i++)
    {
        totalSumOfAll += arrBox[i].length + arrBox[i].width + arrBox[i].height;

    }
    return totalSumOfAll <= max;
}

//максимальный вес коробок, объем которых не превышает maxV
double maxWeightNotBiggerV(Box arrBox[], int arrSize, int maxV)
{
    double weightThatFound = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arrBox[i].length*arrBox[i].width*arrBox[i].height <= maxV)       //выбираем только интересные коробки
        {
            if (arrBox[i].weight >= weightThatFound)                       //если текущий вес больше, чем вес уже найденного
            {
                weightThatFound = arrBox[i].weight;
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
            if ((arrBox[i].height > arrBox[i + 1].height) && (arrBox[i].length > arrBox[i + 1].length) && (arrBox[i].width > arrBox[i + 1].width))
            {
                swap(arrBox[i], arrBox[i + 1]);
                swapCount++;
            }
        }
        if (swapCount == 0) {
          //  cout << "Boxes are sorted already " << endl;
            break;
        }
    }
    bool isPossible;

    cout << "Sorted boxes: " << endl;

    for (int k = 0; k < arrSize - 1; k++)
    {
     //   cout << arrBox[k].length << ' ' << arrBox[k].width << ' ' << arrBox[k].height << ' ' << arrBox[k].weight << endl;
     //   if (k == arrSize - 2) { cout << arrBox[k + 1].length << ' ' << arrBox[k + 1].width << ' ' << arrBox[k + 1].height << ' ' << arrBox[k + 1].weight << endl; }
        if ((arrBox[k].height < arrBox[k + 1].height) && (arrBox[k].length < arrBox[k + 1].length) && (arrBox[k].width < arrBox[k + 1].width))
        {
            isPossible = true;
        }
        else { isPossible = false;  break; }

    }
    return isPossible;
}

bool operator == (Box &a, Box &b)
{
    return (a.length == b.length) && (a.height == b.height) && (a.value == b.value) && (a.weight == b.weight) &&
           (a.width == b.width);
}
istream & operator >> (istream & is, Box &a)
{
    return	cin >> a.length >> a.width >> a.height >> a.weight >> a.value;

}

ostream & operator << (ostream & os, Box &a)
{
    return cout << a.length << ' ' << a.width << ' ' << a.height << ' ' << a.weight << ' ' << a.value << endl;
};



