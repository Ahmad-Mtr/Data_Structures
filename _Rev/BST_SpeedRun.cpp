#include <iostream>

using namespace std;
struct Node {
    int data;
    Node *right, *left;
};

Node *newNODE(int key) {
    Node *newnode = new Node;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = key;
    return newnode;
}

Node *insert(Node *tree, int key) {
    //Base #0 Case: Empty Tree
    //Case #1 bigger than Root
    //Case #2 Less than Root
    //Case #3 Equalls/Duplication
    if (tree == NULL) {
        //Base #0
        return newNODE(key);
    } else if (tree->data == key) {
        //Case #3
        return tree;
    }
    if (tree->data < key) {
        //Case #1
        tree->right = insert(tree->right, key);
    } else
        //Case #1
        tree->left = insert(tree->left, key);
    return tree;
}

bool search(Node *tree, int key) {
    //Case ==
    //Right Subtree
    //left Subtree
    if (key == tree->data) {
        //Case ==
        return true;
    }
    if (tree->data < key) {
        //Rigght Subtree
        if (tree->right != NULL) {
            search(tree->right, key);
        } else return false;

    } else if (key < tree->data) {
        //Left Subtree
        if (tree->left != NULL) {
            search(tree->left, key);
        } else return false;
    }
    return false;
}

void test(Node *tree, int value) {
    switch (search(tree, value)) {
        case 1:
            cout << value << " Was found!" << endl;
            break;
        default:
            cout << value << " d.n.e!" << endl;
    }
}

void inorder(Node *tree) {  //PreOrder...PostOrder...LevelOrder...
    if (tree != NULL) {
        inorder(tree->left);
        cout << tree->data << "-";
        inorder(tree->right);
    }
}

Node *maxLeft(Node *tree) { //u can use minValue() but I like this name, so I've used this method
    Node *tmp = tree;
    while (tmp != NULL && tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}

Node *deleteNode(Node *tree, int key) {
    //  1st: Traverse till Equal
    //Base #0 num of Children ist Null
    //Case #1 num of Children ist 0
    //Case #2 num of Children ist 1
    //Case #3 num of Children ist 2
    if (tree == NULL) {
        //base #0
        return tree;
    }
    if (tree->data == key) {
        //Traversing Finished
        // Testing Cases:
        if (tree->right == NULL && tree->left == NULL) {
            //Case #1   num = 0
            delete tree;
            return NULL;
        } else if (tree->right == NULL && tree->left != NULL) {
            //Case #2   num = 1/ on left
            Node *x = tree->left;
            delete tree;
            return x;

        } else if (tree->right != NULL && tree->left == NULL) {
            //Case #2   num = 1/ on right
            Node *x = tree->right;
            delete tree;
            return x;
        } else {
            //Case #3   num  = 2
            Node *tempo = maxLeft(tree->left);
            int x = tempo->data;   //getting the maxleft value;
            deleteNode(tree, tempo->data); // make 3 right Null
            tree->data = x; //Assigning maxLeft data to current Root
            return tree;
        }

    } else if (tree->data < key) {
        // Traversing Right Subtree...
        tree->right = deleteNode(tree->right, key);
    } else {
        // Traversing Leftt Subtree...
        tree->left = deleteNode(tree->left, key);
    }
    return tree;

}


int main() {
    Node *_Rppt = insert(_Rppt, 5);
    insert(_Rppt, 3);
    insert(_Rppt, 7);
    insert(_Rppt, 6);
    insert(_Rppt, 8);
    insert(_Rppt, 2);
    insert(_Rppt, 4);

    cout << "inorder:";
    inorder(_Rppt);
    cout << endl;

    test(_Rppt, 5);
    test(_Rppt, 8);
    test(_Rppt, 10);

    cout << "inorder #2 :";
    inorder(_Rppt);
    cout << endl;

    deleteNode(_Rppt, 10);

    deleteNode(_Rppt, 5);

    deleteNode(_Rppt, 3);

    cout << "inorder lst:";
    inorder(_Rppt);
    cout << endl;


    return 0;
}