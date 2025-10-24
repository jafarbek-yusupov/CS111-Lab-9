#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// class BinaryTree {
// public:
//     Node* root;
// private:
//     BinaryTree() {}
// };

void preorder(Node* nd) {
    if(nd == nullptr){ return; }
    cout << nd->data << " ";
    preorder(nd->left);
    preorder(nd->right);
}

void postorder(Node* nd) {
    if(nd == nullptr){ return; }
    postorder(nd->left);
    postorder(nd->right);
    cout << nd->data << " ";
}

void inorder(Node* nd) {
    if(nd == nullptr){ return; }
    inorder(nd->left);
    cout << nd->data << " ";
    inorder(nd->right);
}

void levelOrder(Node* nd) {
    if(nd == nullptr){ return; }
    queue<Node*> q;
    q.push(nd);
    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();
        cout << cur->data << " ";

        if (cur->left != nullptr) {
            q.push(cur->left);
        }
        if (cur->right != nullptr) {
            q.push(cur->right);
        }
    }
}

// p2 -- int heightTree(Node* root)
int heightTree(Node* root) {
    if(root == nullptr){ return -1;}
    int lh = heightTree(root->left);
    int rh = heightTree(root->right);

    return max(lh,rh) + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(6565);
    root->left->right = new Node(456465);
    root->right->left = new Node(98789698);
    cout << "preorder: ";
    preorder(root);
    cout << "\ninorder: ";
    inorder(root);
    cout << "\npostorder: ";
    postorder(root);
    cout << "\nlevelOrder: ";
    levelOrder(root);
    cout << endl;

    cout << "\nheight of tree: " << heightTree(root) << endl;
    cout << "height of root->left: " << heightTree(root->left) << endl;
    cout << "height of root->right: " << heightTree(root->right) << endl;
    cout << "height of root->left->left: " << heightTree(root->left->left) << endl;
    cout << "height of root->left->right: " << heightTree(root->left->right) << endl;
    cout << "height of root->right->left: " << heightTree(root->right->left) << endl;
    return 0;
}
