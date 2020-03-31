#include <iostream>
#include <array>
#include "unitBox.h"

using namespace std;

int main()
{
    Box a = Box(3,3,3,3.3,5);
    Box b = Box(1, 1, 1, 32.3, 11);
    Box c = Box(2, 6, 2, 3.8, 110);
    Box d = Box(5, 5, 5, 39.0, 10);
    Box arrBox[] = {a,b,c,d};
    Box e = Box(3, 3, 3, 3.3, 5);

    int arrSize = sizeof arrBox / sizeof(*arrBox);


    cout << "Here are our lovely boxes: " << endl;

    for (int k = 0; k < arrSize - 1; k++)
    {
        cout << arrBox[k].length << ' ' << arrBox[k].width << ' ' << arrBox[k].height << ' ' << arrBox[k].weight << arrBox[k].value <<  endl;
        if (k == arrSize - 2) { cout << arrBox[k + 1].length << ' ' << arrBox[k + 1].width << ' ' << arrBox[k + 1].height << ' ' << arrBox[k + 1].weight << arrBox[k+1].value << endl; }
    }

    //п.2. функция, которая для массива коробок вычисляет суммарную стоимость содержимого всех коробок
    cout << endl << "Sum of all boxes's values =" << sumValue(arrBox, arrSize) << endl;

    //п.3 функция, которая проверяет, что сумма длины, ширины и высоты всех коробок не превосходит введенного значения
    int bigmax;
    cout << endl  << "Input bigmax " << endl;
    cin >> bigmax;

    if (isSumOfAllNotGreater(arrBox, arrSize, bigmax))
    {
        cout << "Sum of all lengths, widths and heigths is greater then " << bigmax << "." << endl;
    }
    else {
        cout << "Sum of all lengths, widths and heigths is not greater then " << bigmax << "." << endl;
    }

    //п.4 функция, которая опередляет максимальный вес коробок, объем которых не более maxV
    int maxV;
    cout << endl << "Input maxV for search max weight from smaller boxes" << endl << endl;
    cin >> maxV;

    if (maxWeightNotBiggerV(arrBox, arrSize, maxV) == 0) cout <<"There are no boxes which Volume is not bigger than "<< maxV << endl ;
    else cout << "Max weight is " << maxWeightNotBiggerV(arrBox,arrSize, maxV) << endl;

    //функция матрешка. Проверка все ли коробки можно вложить друг в друга по одной штуке.
    if (isVpihyemoe(arrBox, arrSize) == 0) cout << "I can't put these boxes like matryoshka" << endl;
    else cout << "I can put these boxes like matryoshka"<<endl;

    //оператор сравнения
    cout << "Let's try our operator of comparison! " << endl;
    cout << "Here's new matrix E:" <<  e.length << ' ' << e.width << ' ' << e.height << ' ' << e.weight << e.value << endl;

    cout << "This is result of comparing boxes a&e: " << endl;
    if (a == e) {
        cout << "A = E" << endl;
    }
    else cout << "A != E" << endl;

    cout << "This is result of comparing boxes b&e: " << endl;
    if (b == e) {
        cout << "B = E" << endl;
    }
    else cout << "B != E" << endl;

    //оператор ввода\вывода
    Box f(0,0,0,0,0);

    cout << "Test input operator." << endl;
    cout << "Input some box. 5 values divided by space: length(integer), width(integer), height(integer), weight(double), value(integer)" << endl;
    cin >> f;
    cout << "And welcome - output opearator: " << f << endl;

    int forOutput;
    cin >> forOutput;
    return (0);
}
