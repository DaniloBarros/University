//
//  BinaryTree.hpp
//  Assignment9
//
//  Created by Danilo Mendes on 4/26/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

//Structure to define node of the tree
typedef struct Node{
    
    Node *right;
    Node *left;
    int value;
    
public:
    //Constructor to create node with value
    Node(int nvalue):value(nvalue),right(nullptr),left(nullptr){};
    
}Node;

class BinaryTree {
    
    //All access to the tree is denied
    
    Node *root;
    void insert(Node *node, int value);
    void printIn(Node *node);
    void printPre(Node *node);
    void printPos(Node *node);
    Node* search(Node *node, int value, Node** parent);
    Node* min(Node *node);
    Node* max(Node *node);
    void destroyTree(Node *node);
    
public:

    BinaryTree():root(NULL){};
    ~BinaryTree();
    
    void insert(int value);
    void remove(int value);
    void printIn();
    void printPre();
    void printPos();
    int search(int value);
    int min();
    int max();
    
};

#endif /* BinaryTree_hpp */
