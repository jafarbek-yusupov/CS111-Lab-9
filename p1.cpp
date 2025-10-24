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

// p3 -- int depthOf
int depthOf(Node* nd, Node* target, int d=0) {
    if(nd == nullptr){ return -1; }
    if (nd == target){ return d; }
    int ld = depthOf(nd->left, target, d+1);
    if(ld != -1) return ld;
    return depthOf(nd->right, target, d+1);
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

    cout << "\nheight of tree: " << heightTree(root);
    cout << "\nheight of node 2: " << heightTree(root->left);
    cout << "\nheight of node 3: " << heightTree(root->right);
    cout << "\nheight of node 6565: " << heightTree(root->left->left);
    cout << "\nheight of node 456465: " << heightTree(root->left->right);
    cout << "\nheight of node 98789698: " << heightTree(root->right->left);

    cout << "=== DEPTH OF TREE | TEST ===" << endl;
    cout << "Depth of root (1): " << depthOf(root, root) << endl;
    cout << "Depth of node 2: " << depthOf(root, root->left) << endl;
    cout << "Depth of node 3: " << depthOf(root, root->right) << endl;
    cout << "Depth of node 6565: " << depthOf(root, root->left->left) << endl;
    cout << "Depth of node 456465: " << depthOf(root, root->left->right) << endl;
    cout << "Depth of node 98789698: " << depthOf(root, root->right->left) << endl;

    // non-existent node
    Node* nonExistent = new Node(9999);
    cout << "Depth of non-existent node: " << depthOf(root, nonExistent) << endl;
    return 0;
}
