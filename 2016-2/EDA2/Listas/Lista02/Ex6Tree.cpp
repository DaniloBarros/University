//
//  Ex6Tree.cpp
//  Lista2
//
//  Created by Danilo Mendes on 9/18/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <ctime>

#define max(a,b) a>=b?a:b

typedef struct Node{

    Node *left_child;
    Node *rigth_child;
    Node *parent;
    
    unsigned int value;
    unsigned int height;
    
}Node;

void insert_in_tree(Node *root, unsigned int value){
    if (root == nullptr) {
        root = (Node*) malloc(sizeof(Node));
        root->value = value;
        root->height = 0;
        root->parent = nullptr;
        root->left_child = nullptr;
        root->rigth_child = nullptr;
    }
}

int main(int argc, const char * argv[]) {
   
    Node *root = nullptr;
    insert_in_tree(root, 3);
    root;
    
    return 0;
}