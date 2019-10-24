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
    //default constructor
    Container (int cl, int cw, int ch, double cwei)
    {
        clength = cl;
        cwidth = cw;
        cheight = ch;
        cweight = cwei;
    }

    int countBoxes(Container);

    double countWeight(Container);

    int countValue(Container);

    Box getBox(Container,int);

    int addBox(Container,Box);

    bool delBox(Container, const int);

    Box operator[](Container);


};

#endif //CPP0_UNITCONTAINER_H
