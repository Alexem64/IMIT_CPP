//
// Created by alexem on 24.10.2019.
//

#ifndef CPP0_UNITCONTAINER_H
#define CPP0_UNITCONTAINER_H

#include <vector>
#include "unitBox.h"

using namespace std;

class Container {
    int clength, cwidth, cheight;
    double cweight;
    std::vector<Box> cboxes;
public:
    int getCLength() const {
        return clength;
    }

    int getCWidth() const {
        return cwidth;
    }

    int getCHeight() const {
        return cheight;
    }

    double getCWeight() const {
        return cweight;
    }

    void setCLength(int cl) {
        clength = cl;
    }

    void setCWidth(int cw) {
        cwidth = cw;
    }

    void setCHeight(int ch) {
        cheight = ch;
    }

    void setCWeight(double cwei) {
        cweight = cwei;
    }

    //default constructor
    Container() {
        clength = 100;
        cwidth = 100;
        cheight = 100;
        cweight = 100;
        cboxes = {Box(3, 3, 3, 3.3, 5), Box(3, 3, 3, 3.3, 5), Box(3, 3, 3, 3.3, 5)};
    }

    Container(int cl, int cw, int ch, double cwei) {
        clength = cl;
        cwidth = cw;
        cheight = ch;
        cweight = cwei;
    }

    int countBoxes();

    double countWeight();

    int countValue();

    Box getBox(int);

    int addBox(Box);

    bool delBox(int);

    const Box &operator[](int ind) const;

    Box &operator[](int ind);

};

istream &operator>>(istream &is, Container &a);

ostream &operator<<(ostream &os, const Container &a);

struct tooMuchWeight{
    std::string message;
    tooMuchWeight (const char * cmessage){
        message = cmessage;
    }
};

#endif //CPP0_UNITCONTAINER_H