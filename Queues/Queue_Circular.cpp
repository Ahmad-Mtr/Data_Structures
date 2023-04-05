#include <iostream>

using namespace std;
const int maxsize = 10;
int Qarray[maxsize];
int front = -1, rear = -1;

bool isfull() {
    if ((rear+1)%maxsize == front)
    return true;
    else
    return false;
}

int isempty() {
    if (front == -1){
        return true;
    } else{
        return false;
    }
}

// Enqueue operation
void enqueue(int value) {
    if (isfull() == 1) {
        return;
    }
    if (front == -1) {
        front = 0, rear = 0;
    } else{
        rear +=1;
    }
    Qarray[rear] = value;
}

// Dequeue operation
int dequeue() {
}

void print() {
    int i;
    if (isempty())
        cout << "Empty Queue" << endl;
    else {
        cout << "The queue is:" << endl;
        for (i = front; i != rear; i = (i + 1) % maxsize) {
            cout << Qarray[i] << endl;
        }
        cout << Qarray[i];
    }
}

int main() {
    enqueue(10);
    print();

    return 0;
}