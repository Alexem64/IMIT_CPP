#pragma once
#ifndef unitBox_H
#define initBox_H
#include <iostream>

using namespace std;

struct Box
{
public: int length, width, height, value;
    double weight;

    Box(int l, int w, int h, double wei, int v)

    {
        length = l;
        width = w;
        height = h;
        weight = wei;
        value = v;
    }
};

int sumValue(Box arrBox[], int arrSize);

bool isSumOfAllNotGreater(Box arrBox[], int arrSize, int max);

double maxWeightNotBiggerV(Box arrBox[], int arrSize, int maxV);

bool isVpihyemoe(Box arrBox[], int arrSize);
bool operator == (Box &a, Box &b);

std::istream & operator >> (istream & is, Box &a);

std::ostream & operator << (ostream & is, Box &a);


#endif


