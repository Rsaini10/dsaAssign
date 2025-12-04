#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

bool isBSTUtil(Node* root, int &prev) {
    if (root == NULL)
        return true;

    if (!isBSTUtil(root->left, prev))
        return false;

    if (root->data <= prev)
        return false;

    prev = root->data;

    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root) {
    int prev = -1000000000;    // Very small initial value
    return isBSTUtil(root, prev);
}

int main() {
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);

    if (isBST(root))
        cout << "Binary tree is a BST";
    else
        cout << "Binary tree is NOT a BST";

    return 0;
}
