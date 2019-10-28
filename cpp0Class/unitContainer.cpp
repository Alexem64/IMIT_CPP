//
// Created by alexem on 24.10.2019.
//

#include "unitContainer.h"

//amount of boxes in container
int Container::countBoxes(const Container& c1) {
    return c1.cboxes.size();
}

//summary of weights of boxes in container
double Container::countWeight(const Container& c1) {
    double resultWeight = 0;
    for (int i = 0; i < countBoxes(c1); i++) {
        resultWeight += c1.cboxes[i].getWeight();
    }
    return resultWeight;
}

//summary of values of boxes in container
int Container::countValue(const Container& c1) {
    int resultValue = 0;
    for (int i = 0; i < countBoxes(c1); i++) {
        resultValue += c1.cboxes[i].getValue();
    }
    return resultValue;
}

//get box by index
Box Container::getBox(const Container &c1, int ind) {
    return c1.cboxes[ind];
}

int Container::addBox(Container &c1, Box b1) {
    if (b1.getWeight() + countWeight(c1) > c1.cweight) {
        return -1;
        //TODO: throw exception
    }
   //c1.cboxes.push_back(b1);
   c1.cboxes.insert(c1.cboxes.begin(),b1) ;
   return countBoxes(c1);
}

bool Container::delBox(Container c1, const int ind) {
    if (ind < countBoxes(c1)) return false;

    c1.cboxes.erase(c1.cboxes.begin() + ind);
    return true;
}

istream &operator>>(istream &is, Container &a) {
    int l, w, h;
    double wei;
    is >> l >> w >> h >> wei;
    a.setCLength(l);
    a.setCWidth(w);
    a.setCHeight(h);
    a.setCWeight(wei);
    return is;
}

ostream &operator<<(ostream &os, const Container &a) {
    return os << a.getCLength() << ' ' << a.getCWidth() << ' ' << a.getCHeight() << ' ' << a.getCWeight() << endl;
};
