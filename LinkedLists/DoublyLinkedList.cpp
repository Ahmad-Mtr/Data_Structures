#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *next; // Pointer to next node
    Node *prev; // Pointer to previous node
};
//Declare Head node
struct Node *head = NULL;

//insert at first
void insertfirst(int n) {
    Node *new_node = new Node;
    new_node->data = n;
    new_node->next = head;
    new_node->prev = NULL;
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
}

//insert last


void deletefirst() {
    if (head == NULL){
        cout<<"Empty List"<<endl;
        return;
    }
     Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;



}

void duplicate() {
    Node *newnode = new Node;
    Node *temp = head;
    newnode->next = NULL;
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newnode->data = temp->data;
    newnode->prev = temp;
    temp->next = newnode;

}

//Tavesrse
void traverse() {
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    insertfirst(5);
    insertfirst(4);
    insertfirst(3);
    insertfirst(2);
    insertfirst(1);
    traverse();
    cout<<endl;
    deletefirst();
    traverse();
    cout<<endl;
    duplicate();
    traverse();
    return 0;
}