#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};
struct node *head = nullptr;
struct node *tail = nullptr;

void insert_first(int data) {
    struct node *newnode = new node;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insert_last(int n) {
    struct node *newnode = new node;
    newnode->data = n;
    newnode->next = nullptr;
    if (head == nullptr) {
        head = newnode;
        cout << "Empty LIST!!!" << endl;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        tail = newnode;
    }
}

void insert_postion(int position,int data) {
    int index = 1;
    struct node *newnode = new node;
    newnode->data = data;
    struct node *temp = head;
    struct node *prev = head;
    if (head == NULL) {
        head = newnode;
        cout << "List is empty:)" << endl;
        return;
    } else {
        while (temp != NULL) {
            if (position == index){
                prev->next= newnode;
                newnode->next = temp;
                break;

            } else {
                index++;
                prev =temp;
                temp =temp->next;
            }
        }
        if (temp == NULL) {
            cout << "Position != Size of List" << endl;
            return;
        }
    }

}

void traverse() {
    struct node *temp = head;
    if (temp == NULL) {
        //cout << "Empty list!" << endl;
        return;
    }
    while (temp != NULL) {

        //cout << temp->data << "  ";
        temp = temp->next;
    }

}

void print_all_list() {
    struct node *temp = head;
    if (temp == NULL) {
        cout << "Empty list!" << endl;
        return;
    }
    while (temp != NULL) {

        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout<<endl;

}

int main() {
    insert_first(1);
    insert_first(2);
    insert_last(10);
    traverse();
    print_all_list();
    insert_postion(4, 30);
    print_all_list();
    system("pause");
    return 0;
}