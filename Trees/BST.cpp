#include <iostream>
using namespace std;
struct node {
    int key;
    struct node *left, *right;
};
struct node* newNode(int item)
{
    struct node* temp=new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key<<"-";
        inorder(root->right);
    }
}
struct node* insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

struct node* minValueNode(struct node* root) {
    struct node* temp = root;
    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}

bool search(struct node* root, int key) {
    if (root == NULL)
        return false;
    else if (root->key == key)
        return true;
    if(root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

struct node* deleteNode(struct node* root, int key) {
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

        // If the key to be deleted is
        // greater than the root's
        // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is the node
        // to be deleted
    else {
        // node has no child
        if (root->left == NULL && root->right == NULL)
            return NULL;

            // node with only one child or no child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void test(node* root, int x){
    switch (search(root, x)) {
        case 1:
            cout<<x<<" was found"<<endl;
            return;
        default:
            cout<<x<<" d.n.e"<<endl;
            return;
    }
}
int main() {
    struct node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);
    insert(root, 2);
    insert(root, 4);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Min value: " << minValueNode(root)->key << endl;

    test(root, 3);
    test(root, 50);
    test(root, 0);

    return 0;
}