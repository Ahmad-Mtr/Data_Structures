//1. Insert_1st method.
//2. Duplicate 3rd node, but square its value and save it in the new node's value.
//3. main(), and test :)

//      src code here:
//----------------------------------------------------------------
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

};
struct Node *head = NULL;

void insert(int data) {//insert begining
    struct Node *newnode = new Node;


    newnode->next = head;
    newnode->data = data;
    head = newnode;


}

void Duplicate() {
    //insert node after pos 3, this node contains   square(node.value of pos 3)
    struct Node *temp = head;
    int pos = 1;
    if (head == NULL) {
        cout << "Empty list dupl";
        return;
    } else {
        while (temp != NULL && pos != 3) {
            temp = temp->next;
            pos++;
        }
        //3 reached;
        struct Node *newnode = new Node;
        newnode->data = (temp->data * temp->data);
        // value added;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;


    }


}

void Display() {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/*
 *
 */
int main() {
    insert(40);
    insert(30);
    insert(20);
    insert(10);
    Display();
    Duplicate();
    cout << endl;
    Display();


    return (EXIT_SUCCESS);
}
