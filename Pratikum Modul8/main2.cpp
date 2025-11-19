#include <iostream>
#include "queue.h"
#include "queue2.cpp"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "--------------------------" << endl;
    cout << "H - T\t | Queue Info" << endl;
    cout << "--------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    enqueue(Q, 9);  printInfo(Q);

    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);

    enqueue(Q, 8);  printInfo(Q);
    enqueue(Q, 1);  printInfo(Q);

    enqueue(Q, 6);  printInfo(Q);

    return 0;
}
