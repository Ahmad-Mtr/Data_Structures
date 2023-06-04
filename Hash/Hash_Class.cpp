//
// Created by YOUSEF MAHMOUD on 18/05/2023.
//
#include<iostream>

using namespace std;
const int TABLE_SIZE = 10;

class HashEntry {
public:
    int key;

    HashEntry(int key) {
        this->key = key;
    }
};

class HashMap {
private:
    HashEntry **table;
public:

    HashMap() {
        table = new HashEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    int HashFunc(int value) {
        return value % TABLE_SIZE;
    }

    void Insert(int value) {
        /*..Insert a value into the hash table..*/
        int key = HashFunc(value);
        int index = key;
        table = new HashEntry *[TABLE_SIZE];
        while(table[index]!=NULL)
        {
            index = (index + 1) % TABLE_SIZE;
            if(index==key)
            {
                cout<<"Hash is full";
            }
            else if(table[index]==NULL)
            {
                table[index] = value;
            }
    }

    bool Search(int value) {
        /*..search for a value in the hash table..*/
        table = new HashEntry *[TABLE_SIZE];

        int index = 0;
        for(int i = 1; i<TABLE_SIZE; (i+1)%TABLE_SIZE)
        {
            if(value == table[i])
            {
                return true;
            }
            else if(i == index)
            {
                cout<<"value not found";
            }
        }

    }

    void printTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "array[ " << i << "]" << endl;
            if (table[i] != NULL) { cout << "  key = " << table[i]->key << endl; }
        }
    }

};
int main() {

    cout<<"A";
    return 0;
}