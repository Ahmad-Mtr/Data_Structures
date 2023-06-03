#include <iostream>
//Think of it as a linked list and try to remember its code
//{
/*Insertion: To add an element to a BST while maintaining the order:

void insert(int key) - Inserts a new element with the given key into the BST.
Deletion: To remove an element from a BST while maintaining the order:

void remove(int key) - Removes the element with the given key from the BST.
Node* deleteNode(Node* root, int key) - Deletes the node with the given key and returns the modified BST.

Searching: To find an element in a BST:

bool search(int key) - Returns true if the element with the given key is found in the BST, otherwise false.

Traversal: To visit all elements in the BST in a specific order:

void inorderTraversal(Node* root) - Performs an inorder traversal of the BST (left subtree, current node, right subtree).
void preorderTraversal(Node* root) - Performs a preorder traversal of the BST (current node, left subtree, right subtree).
void postorderTraversal(Node* root) - Performs a postorder traversal of the BST (left subtree, right subtree, current node).

Minimum and Maximum: To find the minimum and maximum elements in a BST:

Node* findMin(Node* root) - Returns the node with the minimum key value in the BST.
Node* findMax(Node* root) - Returns the node with the maximum key value in the BST.

Successor and Predecessor: To find the successor and predecessor of a given node in a BST:

Node* findSuccessor(Node* root, int key) - Returns the node with the smallest key greater than the given key.
Node* findPredecessor(Node* root, int key) - Returns the node with the largest key smaller than the given key.*/
//}
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *newnode(int value) {
    Node *newnode = new Node;
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct Node *insert(Node *tmpNode, int key) {
    /*
    • Check, whether value in current node and a new value are equal. If so,
            duplicate is found. Otherwise,
    • if a new value is less, than the node's value:
    • if a current node has no left child, place for insertion has been
    found;
    • otherwise, handle the left child with the same algorithm.
    • if a new value is greater, than the node's value:
    • if a current node has no right child, place for insertion has been
    found;
    • otherwise, handle the right child with the same algorithm.*/

    if (tmpNode == NULL) {

        // Case #1: Tree is empty
        return newnode(key);

    } else if (tmpNode->data == key) {

        // Case #2: Duplicate is found
        cout << "Duplicate is found!!" << endl;
        return tmpNode;

    } else if (key > tmpNode->data) {

        // Case #3: Insert to right
        tmpNode->right = insert(tmpNode->right, key);

    } else if (tmpNode->data > key) {

        // Case #4: Insert to left
        tmpNode->left = insert(tmpNode->left, key);

    }
    return tmpNode;


}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << "-";
        inorder(root->right);
    }
}

bool search(Node *tree, int value) {
    if (tree->data == value)            //Case ==
        return true;

    if (value < tree->data) {                //case Left
        if (tree->left != NULL)
            search(tree->left, value);
        else
            return false;
    } else if (tree->data < value) {           //Case right
        if (tree->right != NULL)
            search(tree->right, value);
        else
            return false;
    }
    return false;
}

void test(Node *tree, int value) {
    switch (search(tree, value)) {
        case 1:
            cout << value << " Was Found!" << endl;
            break;
        default:
            cout << value << " Was NOT Found" << endl;
    }
}

void draw(Node *tree) {

}

Node *minRight(Node *tree) {
    Node *tmp = tree;
    while (tmp != NULL && tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

Node *maxleft(Node *tree) {
    Node *tmp = tree;
    while (tmp != NULL && tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}

Node *deletenode(Node *tree, int key) {
    //  Case #0:  deleting a leaf node that has 0 children
    //  Case #1:  Deleting a Node that has 1 child subtree
    //  Case #2:  Deleting a Node that Has 2 child subtrees
    //  Case #4:  Deleting the Root Node

    if (tree == NULL) {
        //Case #A: Tree is empty
        cout << "Tree is empty" << endl;
        return tree;
    }
    if (tree->data == key) {

        if (tree->right != NULL && tree->left != NULL) {

            // Both Children exist Case #2
            Node *tempo = maxleft(tree->left);
            int x = tempo->data;   //getting the maxleft value;
            deletenode(tree, tempo->data); // make 3 right Null
            tree->data = x; //Assigning maxLeft data to current Root
            return tree;

        } else if (tree->right != NULL && tree->left == NULL) {

            // Only Right          Case #1
            return tree->right;

        } else if (tree->right == NULL && tree->left != NULL) {

            // Only Left           Case #1
            return tree->left;

        } else {

            // Null Both           Case #3
            return NULL;
        }


    } else {

        if (tree->data < key) {
            //right
            tree->right = deletenode(tree->right, key);

        } else {
            //left
            tree->left = deletenode(tree->left, key);

        }
    }
    cout << "NOT FOUND TO DELETE" << endl;
    return tree;

}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);
    insert(root, 2);
    insert(root, 4);


    cout << "Inorder: ";
    inorder(root);
    cout << "\n" << endl;

    cout << "Min value: " << minRight(root)->data << endl;

//    deletenode(root, 8);
//
//    cout << "Inorder #2 aft_del_8: ";
//    inorder(root);
//    cout << "\n" << endl;
//
//    deletenode(root, 8);
//
//    cout << "Inorder #3 aft_del_8: ";
//    inorder(root);
//    cout << "\n" << endl;
//
//    deletenode(root, 2);
//
//    cout << "Inorder #4 aft_del_2: ";
//    inorder(root);
//    cout << "\n" << endl;
//    deletenode(root, 3);
//
//    cout << "Inorder aft_del_50: ";
//    inorder(root);
//    cout << "\n" << endl;

    //deletenode(root, 5);

    cout << "Inorder aft_del aft_del_5: ";
    inorder(root);
    cout << "\n" << endl;

    test(root, 3);
    test(root, 50);
    test(root, 0);
    return 0;
}