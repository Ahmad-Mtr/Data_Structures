#include <iostream>

using namespace std;
struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

bool isEmpty() { //returns True if empty & false if ! empty
    if (top == NULL) {

        return true;
    } else
        return false;
}

void push(int data) {
    Node *_newnode = new Node;
    _newnode->next = top;
    _newnode->data = data;
    top = _newnode;
    /*if (top == NULL) {

        top = _newnode;
        _newnode->next = NULL;
        return;
    } else {
        top = _newnode;
        return;
    }*/
}

void pop() {
    if (isEmpty()) {
        cout<<"Empty Stack"<<endl;
        return;
    } else{
        Node *_pop = new Node;
        _pop = top;
        top = _pop ->next;
        delete _pop;
    }

}


int peek() {
    if (isEmpty()){
        cout<<"Empty Stack";
    } else {
        cout<<top->data;
        return top->data;
    }
}

void display() {
    struct Node *temp;
    if (isEmpty()) {
        cout << "\nThe stack is empty";
    } else {
        temp = top;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
}

int main() {
    isEmpty();
    push(10);
    push(15);
    push(20);
    display();
    cout<<endl;
    pop();
    display();
    cout<<endl;
    peek();
    return 0;
}