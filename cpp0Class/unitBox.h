#pragma once
#ifndef unitBox_H
#define initBox_H
#include <iostream>

using namespace std;

class Box {
    int length, width, height, value;
    double weight;
public:
    int getLength() {
        return length;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    double getWeight() const {
        return weight;
    }

    int getValue() const {
        return value;
    }

    void setLength(int l) {
        length = l;
    }
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }
    void setWeight(double wei) {
        weight = wei;
    }
    void setValue(int v) {
        value = v;
    }

    Box(int l, int w, int h, double wei, int v) {
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

    bool operator==(Box &a, Box &b);

    istream &operator>>(istream &is, Box &a);

    ostream &operator<<(ostream &os, Box &a);

#endif

