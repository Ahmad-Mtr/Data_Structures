#include <iostream>

using namespace std;
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert_first(int n) {
    struct node *newnode = new node;
    newnode->data = n;
    newnode->next = head;
    head = newnode;
}
void insert_last(int n){
    struct node *newnode = new node;
    newnode->data = n;
    newnode->next = NULL;
    if (head == NULL){
        head = newnode;
        cout<<"Empty LIST!!!"<<endl;
    }else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }



}

void traverse() {
    struct node *temp = head;
    if(temp == NULL) {
        cout << "Empty list!" << endl;
        return;
    }
    while(temp != NULL){

        cout << temp->data << "  ";
        temp = temp->next;
    }

}

int main() {
    insert_first(1);
    insert_first(2);
    insert_last(10);
    traverse();

    return 0;
}