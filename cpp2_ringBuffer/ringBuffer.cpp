//
// Created by alexem on 15.12.2019.
//
#include <iostream>
#include "ringBuffer.h"

using namespace std;

int main()
{
    double a;
    Queue q(4);
    cout << endl << "Default queue with capacity: " << q.getCapacity() << endl;

    try {
        cout << "Let's try to get some elements" << endl;
        a = q.getFirst();
    }
    catch (QueueIsNull& e) {
        cout << "Error! " << e.message << endl << endl;
    }

    try {
        cout << "Let's try to take some elements" << endl;
        a = q.shift();
    }
    catch (QueueIsNull& e) {
        cout << "Error! " << e.message << endl << endl;
    }

    cout << "###########################################" << endl << endl;
    cout << "Let's push some elements" << endl;

    cout << "New size" << "\t" << "Pushed element" << "\t" <<" Capacity" << "\t" << "First element" <<endl;

    q.push(5);
    cout << q.getSize() << "\t" << q.getLast() << "\t" << q.getCapacity() << "\t" << q.getFirst() << endl;
    q.printQueue();
    q.push(3);
    cout << q.getSize() << "\t" << q.getLast() << "\t" << q.getCapacity() << "\t" << q.getFirst() << endl;
   q.printQueue();
    q.push(4);
    cout << q.getSize() << "\t" << q.getLast() << "\t" << q.getCapacity() << "\t" << q.getFirst() << endl;
   q.printQueue();
    q.push(2);
    cout << q.getSize() << "\t" << q.getLast() << "\t" << q.getCapacity() << "\t" << q.getFirst() << endl;
   q.printQueue();

    try {
        cout << "Let's try to push more elements " << endl;
        q.push(1);
    }
    catch (QueueOverflow& e) {
        cout << "Error! " << e.message << endl;
    }

   // q.getFirst();

    cout << "###########################################" << endl;
    cout << endl;
    cout << "Let's try to shift throw the queue " << endl;
   // q.printQueue();
    cout << q.shift() << endl;
  //  q.printQueue();
    cout << q.shift() << endl;
 //   q.printQueue();
    cout << q.shift() << endl;
  //  q.printQueue();
    cout << q.shift() << endl;
 //   q.printQueue();

    try {
        cout << "And once more" << endl;
        a = q.shift();
    }
    catch (QueueIsNull& e) {
        cout << "Error! " << e.message << endl;
    }

    cout << "###########################################" << endl;
    cout << endl;
    cout << "Let's clean up!" << endl;

    q.clear();
    try {
        cout << "And now let's try to get first elem and shift it" << endl;
        a = q.shift();
        a = q.getFirst();
    }
    catch (QueueIsNull& e) {
        cout << "Error!" << e.message << endl;
    }

    cout << "###########################################" << endl;
    cout << endl;
    cout << "Greetings! Here's our Iterator. Let's push some elements with it." << endl;

    q.push(5);
    q.push(7);
    q.push(11);
    q.push(23);

    auto queueIter = q.iterator();
    queueIter.start();
    cout << endl;
    cout << "And here it is:" << endl;
    while (!queueIter.finish()) {
        cout << queueIter.getValue() << endl;
        queueIter.next();
    }

    system("pause");
    return 0;
}

