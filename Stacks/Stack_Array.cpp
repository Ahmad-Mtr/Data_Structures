#include <iostream>
using namespace std;

//Stack:
//Top = the index that is at Top
//Count: number of elements in a Stack
//Methods: Push/add() Adds an element to the top of the stack
//         Pop/remove() Removes an element from the top of the stack
//         Peek() Examines the element at the top of the stack
//         isEmpty() Determines whether the stack is empty
//         size() Determines the number of elements in the stack
const int maxsize = 5;
int _Stack_Array[maxsize];
int front = -1, rear = -1;

int size(){
    int i;
    for ( i = 0; _Stack_Array[i] != NULL; ++i) {

    }
    if(i == 0){
        cout<<"Stack is empty"<<endl;
        return 0;
    } else{
        cout<<"\nSize is: "<<i<<endl;
        return i;}


}
int peek(){
    cout<<"Peeking Stack...\nPeek is : "<<_Stack_Array[rear]<<endl;
    return _Stack_Array[rear];
}
bool isfull() {
    if (maxsize -1  == rear)
    return true;
    else
    return false;
}

int isempty() {
    if (rear == -1){
        return true;
    } else{
        return false;
    }
}

// push operation
void push(int value) {
    if (isfull() == true) {
        return;
    }
    if (rear == -1) {
        rear = 0;
    } else{
        rear +=1;
    }
    _Stack_Array[rear] = value;
}

// Pop operation
void pop() {
    if(isempty() == true){
        cout<<"Empty Stack"<<endl;
        return;
    }
    _Stack_Array[rear] = NULL;
    rear--;

}

void print() {
    if (isempty())
        cout << "Empty Queue" << endl;
    else {
        cout << "The Stack is:" << endl;
        for (int i = 0; rear-i != -1; ++i) {
            cout<<_Stack_Array[rear-i]<<endl;
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    //pop();
    print();
    size();
    peek();


    return 0;
}