#ifndef BST_H
#define BST_H

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();
    void insert(int value);
    bool search(int value);
    void remove(int value);
    void clear();
    void display() const; // метод для відображення дерева

private:
    Node* root;
    void insert(Node*& node, int value);
    bool search(Node* node, int value) const;
    void remove(Node*& node, int value);
    void clear(Node* node);
    void display(Node* node, int indent) const; // допоміжний метод для відображення дерева
};

#endif // BST_H
 
