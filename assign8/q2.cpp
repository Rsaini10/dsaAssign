#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertNode(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else if (x > root->data) root->right = insertNode(root->right, x);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* minimum(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

Node* maximum(Node* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return minimum(x->right);
    Node* succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        }
        else if (x->data > root->data) {
            root = root->right;
        }
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return maximum(x->left);
    Node* pred = NULL;
    while (root) {
        if (x->data > root->data) {
            pred = root;
            root = root->right;
        }
        else if (x->data < root->data) {
            root = root->left;
        }
        else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    int a[] = {50,30,70,20,40,60,80};
    for (int i = 0; i < 7; i++)
        root = insertNode(root, a[i]);

    int key = 40;
    Node* r = searchRec(root, key);
    Node* i = searchIter(root, key);

    cout << "Recursive Search: " << (r ? "Found" : "Not Found") << endl;
    cout << "Iterative Search: " << (i ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << minimum(root)->data << endl;
    cout << "Maximum: " << maximum(root)->data << endl;

    Node* succ = inorderSuccessor(root, r);
    Node* pred = inorderPredecessor(root, r);

    if (succ) cout << "Inorder Successor of " << key << " : " << succ->data << endl;
    else cout << "No Successor for " << key << endl;

    if (pred) cout << "Inorder Predecessor of " << key << " : " << pred->data << endl;
    else cout << "No Predecessor for " << key << endl;

    return 0;
}
