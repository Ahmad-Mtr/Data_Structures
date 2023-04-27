#include<iostream>
using namespace std;
static const int MAX_SIZE = 15;
int heap[MAX_SIZE];
int _size=0;
// returns the index of the parent node
static int parent(int i) {
    return (i - 1) / 2;
}
// return the index of the left child
static int leftChild(int i) {
    return 2*i + 1;
}
// return the index of the right child
static int rightChild(int i) {
    return 2*i + 2;
}
// insert the item at the appropriate position
void insert(int data) {
    if (_size == MAX_SIZE) {
        cout << "Heap is full, cannot insert more elements" << endl;
        return;
    }
    // insert the data at the end of the heap
    heap[_size] = data;
    int i = _size;
    _size++;
    // swap the data with its parent if the parent is smaller
    while (i > 0 && heap[i] > heap[parent(i)]) {
        int temp = heap[i];
        heap[i] = heap[parent(i)];
        heap[parent(i)] = temp;
        i = parent(i);
    }
}
// returns the maximum item of the heap
int getMax() {
    if (_size == 0) {
        cout << "Heap is empty, cannot get maximum element" << endl;
        return -1;
    }
    // the maximum element is always the first element of the heap
    return heap[0];
}

void maxHeapify(int i){
    // find left child node
    int left = leftChild(i);
    // find right child node
    int right = rightChild(i);
    // find the largest among 3 nodes
    int largest = i;
    // check if the left node is larger than the current node
    if (left <= _size && heap[left] > heap[largest]) {
        largest = left;
    }
    // check if the right node is larger than the current node
    // and left node
    if (right <= _size && heap[right] > heap[largest]) {
        largest = right;
    }
    // swap the largest node with the current node
    // and repeat this process until the current node is larger than
    // the right and the left node
    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        maxHeapify(largest);
    }
}
// deletes the max item
void DeleteTop() {
    if (_size == 0) {
        cout << "Heap is empty, cannot delete top element" << endl;
        return;
    }
    // replace the first element with the last element
    heap[0] = heap[_size-1];
    _size--;
    // restore the heap property by calling maxHeapify on the first element
    maxHeapify(0);

}
int main() {
    insert(10);
    insert(20);
    insert(15);
    insert(30);
    cout << getMax() << endl; // should print 30
    DeleteTop();
    cout << getMax() << endl; // should print 20
    return 0;
}