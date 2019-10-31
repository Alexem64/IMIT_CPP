//
// Created by alexem on 01.11.2019.
//

#ifndef CPP1_DYNAMICARRAYOFINT_H
#define CPP1_DYNAMICARRAYOFINT_H

class DynamicArrayOfInt
{
  int *Array;
  int size;

public:
    DynamicArrayOfInt()
    {
        Array = nullptr;
        size=10;
    }
    DynamicArrayOfInt(int sz)
    {
        size=sz;
        Array = new int[size];
        for (int i = 0; i < size; i++)
            Array[i] = 0;
    }

    DynamicArrayOfInt(int sz, int n)
    {
        size=sz;
        Array = new int[size];
        for (int i = 0; i < size; i++)
            Array[i] = n;
    }

    DynamicArrayOfInt(const DynamicArrayOfInt &obj)
    {
        size = obj.size;
        Array = new int[obj.size];
        for (int i = 0; i < size; i++)
            Array[i] = obj.Array[i];
    }

    DynamicArrayOfInt(DynamicArrayOfInt &&obj)
    {
        //TODO: check operator of remove
        obj.Array = nullptr;
    }

    ~DynamicArrayOfInt()
    {
        delete []Array;
    }

    int getLength(const DynamicArrayOfInt &obj)
    {
        return obj.size;
    }



};

#endif //CPP1_DYNAMICARRAYOFINT_H
