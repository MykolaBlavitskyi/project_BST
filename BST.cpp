#include <iostream>
#include "BST.h"
using namespace std;

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

void BST::insert(int value) {
    insert(root, value);
}

void BST::insert(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

bool BST::search(int value) {
    return search(root, value);
}

bool BST::search(Node* node, int value) const {
    if (node == nullptr) {
        return false;
    }
    if (node->data == value) {
        return true;
    } else if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

void BST::remove(int value) {
    remove(root, value);
}

void BST::remove(Node*& node, int value) {
    if (node == nullptr) return;
    if (value < node->data) {
        remove(node->left, value);
    } else if (value > node->data) {
        remove(node->right, value);
    } else {
        Node* temp = node;
        if (node->left == nullptr) {
            node = node->right;
        } else if (node->right == nullptr) {
            node = node->left;
        } else {
            Node* successor = node->right;
            while (successor && successor->left) {
                successor = successor->left;
            }
            node->data = successor->data;
            remove(node->right, successor->data);
        }
        delete temp;
    }
}

void BST::clear() {
    clear(root);
}

void BST::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BST::display() const {
    display(root, 0);
}

void BST::display(Node* node, int indent) const {
    if (node != nullptr) {
        if (node->right) {
            display(node->right, indent + 4);
        }
        if (indent) {
            cout << string(indent, ' ');
        }
        cout << node->data << "\n";
        if (node->left) {
            display(node->left, indent + 4);
        }
    }
}
 
void BST::remove(int value) {
    remove(root, value);
}

void BST::remove(Node*& node, int value) {
    if (node == nullptr) {
        return; 
    }

    if (value < node->data) {
        remove(node->left, value);
    } else if (value > node->data) {
        remove(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node; 
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right; 
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* minNode = findMin(node->right);
            node->data = minNode->data; 
            remove(node->right, minNode->data); 
        }
    }
}

Node* BST::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}


void BST::clear() {
    clear(root);
    root = nullptr;
}

void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}


vector<int> BST::findPath(int value) {
    vector<int> path;
    findPath(root, value, path);
    return path;
}

bool BST::findPath(Node* node, int value, vector<int>& path) {
    if (node == nullptr) {
        return false; 
    }

    path.push_back(node->data); 

    if (node->data == value) {
        return true;
    }

    if ((node->left && findPath(node->left, value, path)) ||
        (node->right && findPath(node->right, value, path))) {
        return true;
    }

    path.pop_back();
    return false;
}
