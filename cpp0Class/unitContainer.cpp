//
// Created by alexem on 24.10.2019.
//

#include "unitContainer.h"

//amount of boxes in container
int Container::countBoxes() {
    return this->cboxes.size();
}

//summary of weights of boxes in container
double Container::countWeight() {
    double resultWeight = 0;
    for (int i = 0; i < this->countBoxes(); i++) {
        resultWeight += this->cboxes[i].getWeight();
    }
    return resultWeight;
}

//summary of values of boxes in container
int Container::countValue() {
    int resultValue = 0;
    for (int i = 0; i < this->countBoxes(); i++) {
        resultValue += this->cboxes[i].getValue();
    }
    return resultValue;
}

//get box by index
Box Container::getBox(int ind) {
    return this->cboxes[ind];
}

int Container::addBox(Box b1) {
    if (b1.getWeight() + this->countWeight() > this->cweight) {
        throw tooMuchWeight("Your box is too heavy!");
    }
    this->cboxes.insert(this->cboxes.begin(), b1);
    return this->countBoxes();

}

bool Container::delBox(const int ind) {
    if (ind > this->countBoxes()) return false;
    this->cboxes.erase(this->cboxes.begin() + ind);
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
}

const Box &Container::operator[](const int ind) const {
    return this->cboxes[ind];
}

Box &Container::operator[](const int ind) {
    return this->cboxes[ind];
};

