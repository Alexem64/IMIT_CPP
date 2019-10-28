#include <iostream>
#include <array>
#include "unitBox.h"
#include "unitContainer.h"

using namespace std;

int main()
{
    Box a = Box(3,3,3,3.3,5);
    Box b = Box(1, 1, 1, 32.3, 11);
    Box c = Box(2, 2, 2, 3.8, 110);
    Box d = Box(5, 5, 5, 39.0, 10);
    Box arrBox[] = {a,b,c,d};
    Box e = Box(3, 3, 3, 3.3, 5);

    int arrSize = sizeof arrBox / sizeof(*arrBox);


    cout << "Here are our lovely boxes: " << endl;

    for (int k = 0; k < arrSize - 1; k++)
    {
        cout << arrBox[k].getLength() << ' ' << arrBox[k].getWidth() << ' ' << arrBox[k].getHeight() << ' ' << arrBox[k].getWeight() << ' ' << arrBox[k].getValue() <<  endl;
        if (k == arrSize - 2) { cout << arrBox[k + 1].getLength() << ' ' << arrBox[k + 1].getWidth() << ' ' << arrBox[k + 1].getHeight() << ' ' << arrBox[k + 1].getWeight() << ' ' << arrBox[k+1].getValue() << endl; }
    }

    //п.2. функция, которая для массива коробок вычисляет суммарную стоимость содержимого всех коробок
    cout << endl << "Sum of all boxes's values =" << sumValue(arrBox, arrSize) << endl;

    //п.3 функция, которая проверяет, что сумма длины, ширины и высоты всех коробок не превосходит введенного значения
    int bigmax;
    cout << endl  << "Input integer value. Program will check that sum of lengths, widths and height of all boxes are not bigger then this value. " << endl;
    cin >> bigmax;

    if (isSumOfAllNotGreater(arrBox, arrSize, bigmax))
    {
        cout << "Sum of all lengths, widths and heights is not greater then " << bigmax << "." << endl;
    }
    else {
        cout << "Sum of all lengths, widths and heights is greater then " << bigmax << "." << endl;
    }

    //п.4 функция, которая опередляет максимальный вес коробок, объем которых не более maxV
    int maxV;
    cout << endl << "Input maxV for search max weight from smaller boxes" << endl << endl;
    cin >> maxV;

    if (maxWeightNotBiggerV(arrBox, arrSize, maxV) == 0) cout <<"There are no boxes which Volume is not bigger than "<< maxV << endl  <<endl;
    else cout << "Max weight is " << maxWeightNotBiggerV(arrBox,arrSize, maxV) << endl <<endl;

    //функция матрешка. Проверка все ли коробки можно вложить друг в друга по одной штуке.
    if (isVpihyemoe(arrBox, arrSize) == 0) cout << "I can't put these boxes like matryoshka" << endl <<endl;
    else cout << "I can put these boxes like matryoshka"<<endl <<endl ;

    //оператор сравнения
    cout << "Let's try our operator of comparison! " << endl;
    cout << "Here's new matrix E:" <<  e.getLength() << ' ' << e.getWidth() << ' ' << e.getHeight() << ' ' << e.getWeight() << e.getValue() << endl;

    cout << "This is result of comparing boxes a&e: " << endl;
    if (a == e) {
        cout << "A = E" << endl;
    }
    else cout << "A != E" << endl;

    cout << "This is result of comparing boxes b&e: " << endl;
    if (b == e) {
        cout << "B = E" << endl<<endl;
    }
    else cout << "B != E" << endl<<endl;

    //оператор ввода\вывода
    Box f(0,0,0,0,0);

    cout << "Let's test input operator." << endl;
    cout << "Input some box. Put 5 values divided by space: length(integer), width(integer), height(integer), weight(double), value(integer)" << endl;
    cin >> f;
    cout << "And welcome - output operator: " << f << endl;

    Container cont100(100,100,100,100);
    Container defcont;
    Container::addBox(cont100, f);
    cout << "cont100:" <<cont100 << endl;
    cout << "Adding f: " << f << endl;
 //   cout << "defcont:" <<defcont << endl;
    cout << "Count boxes cont100: " << Container::countBoxes(cont100) << endl;
    cout << "Count weights con100: " << Container::countWeight(cont100) << endl;
    cout << "Count values con100: " << Container::countValue(cont100) << endl;
 /*   Container::addBox(defcont, f);
    cout << "Adding f: " << f << endl;
    cout << Container::addBox(defcont,f);
    cout << "Count boxes cont100: " << Container::countBoxes(defcont) << endl;
    cout << "Count weights con100: " << Container::countWeight(defcont) << endl;
    cout << "Count values con100: " << Container::countValue(defcont) << endl;
*/
        Container::addBox(cont100,a);
    cout << "Adding a: " << a << endl;
    cout << "Count boxes: " << Container::countBoxes(cont100) << endl;
    cout << "Count weights: " << Container::countWeight(cont100) << endl;
    cout << "Count values: " << Container::countValue(cont100) << endl;
    Container::addBox(cont100,b);
    cout << "Adding b: " << b << endl;
    cout << "Count boxes: " << Container::countBoxes(cont100) << endl;
    cout << "Count weights: " << Container::countWeight(cont100) << endl;
    cout << "Count values: " << Container::countValue(cont100) << endl;
    Container::addBox(cont100,c);
    cout << "Adding c: " << c << endl;
    cout << "Count boxes: " << Container::countBoxes(cont100) << endl;
    cout << "Count weights: " << Container::countWeight(cont100) << endl;
    cout << "Count values: " << Container::countValue(cont100) << endl;
    Container::addBox(cont100,d);
    cout << "Adding d: " << d << endl;
    cout << "Count boxes: " << Container::countBoxes(cont100) << endl;
    cout << "Count weights: " << Container::countWeight(cont100) << endl;
    cout << "Count values: " << Container::countValue(cont100) << endl;
    Container::addBox(cont100,e);
    cout << "Adding e: " << e << endl;
    cout << "Count boxes: " << Container::countBoxes(cont100) << endl;
    cout << "Count weights: " << Container::countWeight(cont100) << endl;
    cout << "Count values: " << Container::countValue(cont100) << endl;

    //trying getBox
    Box ff = Container::getBox(cont100,3);
    cout << "Try get third box: " << ff;


    // int forOutput;
    //cin >> forOutput;
    return (0);
}
