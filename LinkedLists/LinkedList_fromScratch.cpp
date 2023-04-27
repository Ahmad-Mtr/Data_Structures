#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};
Node *head = NULL;

void add_1st(int data) {
    struct Node *newnode = new Node;
    newnode->next = head;
    newnode->data = data;
    head = newnode;
}

void add_last(int data) {
    struct Node *newnode = new Node;
    newnode->data = data;
    newnode->next = NULL;

    struct Node *temp = head;
    if (head == NULL) {
        add_1st(data);
        cout << "Empty List!" << endl;
    } else {

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }


}

void add_pos(int data, int position) {
    struct Node *newnode = new Node;
    newnode->data = data;
    struct Node *temp = head;
    if (head == NULL) {
        head = newnode;
        cout << "Empty LIst!" << endl;
        return;
    } else {
        for (int i = 1; i != position; ++i) {
            temp = temp->next;
        }
        // thing goes here:
        newnode->next = temp->next;
        temp->next = newnode;
    }


}

void del_1st() {}

void del_last() {}

void del_pos() {}

void traverse() {
    struct Node *temp = head;
    if (head == NULL) {
        cout << "Empty List!" << endl;
    } else {
        while (temp != NULL) {
            temp = temp->next;
        }
    }
}

void printList() {
    struct Node *temp = head;
    if (head == NULL) {
        cout << "Empty List!" << endl;
    } else {
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

void duplicate_1st() {

}

void dupl_1st() {
    if (head == NULL) {
        return;
    } else {
        add_1st(head->data);
    }
}

void duplicate_pos(int pos) {

}

void dupl_pos(int pos) {
    struct Node *temp = head;
    if (head == NULL) {
        cout << "Empty LIst!" << endl;
        return;
    } else {
        for (int i = 1; i != pos; ++i) {
            temp = temp->next;
        }
        // thing goes here:
        add_pos(temp->data, pos);
    }
}

void duplicate_last() {
    struct Node *jadeed = new Node;
    jadeed->next = NULL;
    struct Node *temp = head;
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        jadeed->data = temp->data;
        temp->next = jadeed;
    }
}

void dupl_last() {
    struct Node *temp = head;
    if (head == NULL) {
        cout << "Empty List!" << endl;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
    }
    add_last(temp->data);
}

int main() {
    add_1st(20);
    add_1st(10);
    add_last(30);
    add_pos(25, 2);
    add_pos(35, 4);
    printList();
    cout << endl;
    //duplicate_1st();
    //duplicate_pos(3);
    duplicate_last();
    printList();
    cout << endl;
    dupl_1st();
    dupl_pos(3);
    dupl_last();
    printList();

    return 0;

}
