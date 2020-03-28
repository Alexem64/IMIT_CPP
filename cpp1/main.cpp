#include <iostream>
#include "DynamicArrayOfInt.h"

int main() {
    //test first constructor without parameters
    DynamicArrayOfInt emptyDAI{DynamicArrayOfInt()};
     cout << "Creating emptyDAI." <<  endl;

    //test second constructor with length
    DynamicArrayOfInt varLengthZeroDAI{DynamicArrayOfInt(15)};
     cout << "Here is a variable-sized empty array: " << varLengthZeroDAI <<  endl;

    //test third constructor with length and value
    DynamicArrayOfInt varLengthNotZeroDAI{DynamicArrayOfInt(4,10)};
     cout << "Here is a variable-sized not-empty array: " << varLengthNotZeroDAI <<  endl;

    //test input in empty array
     cout << "Input 4 integers to fill empty DAI " <<  endl;
     cin >> emptyDAI;
     cout << "Here is your array: " << emptyDAI <<  endl;

    DynamicArrayOfInt emptyDAIForResizing{DynamicArrayOfInt()};
    emptyDAIForResizing = emptyDAI;


    //DynamicArrayOfInt new6DAI{emptyDAI.resize(6)};
    emptyDAIForResizing.resize(6);
    cout << "Try to resize array in bigger array" << emptyDAIForResizing  << endl;
    //DynamicArrayOfInt new2DAI{emptyDAI.resize(2)};

    emptyDAIForResizing.resize(2);
     cout << "Try to resize array in smaller array" << emptyDAIForResizing << endl;

    DynamicArrayOfInt sumVarDAIs{varLengthNotZeroDAI+varLengthNotZeroDAI};
     cout << "Sum of two DAIs: " << sumVarDAIs << endl;
    
     cout << "Checking comparisons: " <<  endl;

    if (varLengthNotZeroDAI > emptyDAI) {
         cout << varLengthNotZeroDAI << "> " << emptyDAI <<endl;
    }

    if (varLengthNotZeroDAI >= emptyDAI) {
         cout << varLengthNotZeroDAI << ">= " << emptyDAI <<endl;
    }

    if (varLengthNotZeroDAI < emptyDAI) {
         cout << varLengthNotZeroDAI << "< " << emptyDAI <<endl;
    }

    if (varLengthNotZeroDAI <= emptyDAI) {
         cout << varLengthNotZeroDAI << "<= " << emptyDAI <<endl;
    }

    if (varLengthNotZeroDAI == emptyDAI) {
         cout << varLengthNotZeroDAI << "== " << emptyDAI <<endl;
    }

    if (varLengthNotZeroDAI != emptyDAI) {
         cout << varLengthNotZeroDAI << "!= " << emptyDAI <<endl;
    }

    DynamicArrayOfInt newDAI = varLengthNotZeroDAI + emptyDAI;
    cout << "Concatenation: " <<  newDAI << endl;
    return 0;
}