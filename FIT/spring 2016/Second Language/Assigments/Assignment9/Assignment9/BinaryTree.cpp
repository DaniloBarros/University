//
//  BinaryTree.cpp
//  Assignment9
//
//  Created by Danilo Mendes on 4/26/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include "BinaryTree.hpp"

//Insert value (Call insert private if not null)
void BinaryTree::insert(int value){
    if (this->root == nullptr) {
        root = new Node(value);
    }else{
        insert(root, value);
    }
}

//Remove node with value
void BinaryTree::remove(int value){
    //Create a parent and auxiliar pointers
    Node* parent;
    Node* aux = search(root, value, &parent);

    //If value does not exist return
    if (aux==nullptr) {
        return;
    }
    
    //If node is a leaf
    //Parent points to null and delete it
    if (!aux->right && !aux->left) {
       
        if(parent->right == aux)
            parent->right = nullptr;
        else
            parent->left = nullptr;
        
        delete aux;
        aux = nullptr;
    
    //If node has one child
    //Parent points to childs child
    //Delete node
    }else if(!aux->right || !aux->left){
        
        //If node has a right child
        if(aux->right != nullptr){
            
            //If node is the right parents child
            if (parent->right == aux)
                parent->right = aux->right;
            else
                parent->left = aux->right;
            
        }else if(aux->left != nullptr){
            
            if (parent->left == aux)
                parent->left = aux->left;
            else
                parent->right = aux->left;
        }
        
        //Delete Node
        delete aux;
        aux = nullptr;
    
    //Node has two children
    }else{
        //Will never have a left child
        //Change value of node to be removed with
        //minMax value, delete minMax
        Node *minMax;
        minMax = min(aux->right);
        
        //Create a parent pointer of the minimum
        Node *parentMinimum;
        search(aux->right, minMax->value, &parentMinimum);
        
        //Right Child does not have a left child
        if (minMax == aux->right) {
            aux->value = minMax->value;
            aux->right = minMax->right;
            
        //Minimum has a right child
        }else if(minMax->right != nullptr){
            
            aux->value = minMax->value;
            parentMinimum->left = minMax->right;
            
        //Minimum node is a leaf
        }else{
            aux->value = minMax->value;
            parentMinimum->left = nullptr;
        }
        
        //delete pointer to minimum node
        delete minMax;
        minMax = nullptr;
        return;
    }
    
    
}
//Call print for root
void BinaryTree::printIn(){
    printIn(root);
}

void BinaryTree::printPre(){
    printPre(root);
}

void BinaryTree::printPos(){
    printPos(root);
}
//Search the entire tree
int BinaryTree::search(int value){
    //Auxiliar for nothing
    Node* aux;
    return search(root, value, &aux)->value;
}
//Minimum for the whole tree
int BinaryTree::min(){
    return min(root)->value;
}

int BinaryTree::max(){
    Node *aux = max(root);
    return aux->value;
}

#pragma mark Private

void BinaryTree::insert(Node *node, int value){
    //If value greater than node value, go right
    if (value > node->value) {

        //If right not null go right
        //If null create a new node
        if (node->right != NULL) {
            insert(node->right, value);
        }else{
            node->right = new Node(value);
        }
    
    //If lesser than node value, go left
    }else if(value < node->value){
        if (node->left != nullptr) {
            insert(node->left, value);
        }else{
            node->left = new Node(value);
        }
    
    //If equal, do not accept
    }else{
        //printf("Value %d already exists in tree\n",value);
    }
    
}

//Go left, print, go right
void BinaryTree::printIn(Node *node){
    
    if (node == nullptr)
        return;
    printIn(node->left);
    printf("%d ", node->value);
    printIn(node->right);
    
}

//Print, go left, go right
void BinaryTree::printPre(Node *node){
    if (node == nullptr) {
        return ;
    }
    printf("%d ", node->value);
    printPre(node->left);
    printPre(node->right);
}

//Go left, go right, print
void BinaryTree::printPos(Node *node){
    if (node == nullptr) {
        return ;
    }
    printPos(node->left);
    printPos(node->right);
    printf("%d ", node->value);
}

Node* BinaryTree::search(Node *node, int value, Node **parent){
    //Auxiliar pointer and parent pointer start at node
    Node *aux = node;
    *parent = node;
    bool found = false;
    
    //Until Null or found
    while(aux != NULL){
        if(aux->value == value){
            found = true;
            break;
        }else {
            //Parent stays at current node
            //auxiliar goes to the next
            *parent = aux;
            if(value > aux->value)
                aux = aux->right;
            else
                aux = aux->left;
        }
    }
    
    //return auxiliar, parent is modified by reference
    return aux;
    
}

Node* BinaryTree::min(Node *node){
    Node *aux = node;
    
    //Go left until null
    while (aux->left != nullptr) {
        aux = aux->left;
    }
    
    return aux;
}

Node* BinaryTree::max(Node *node){
    Node *aux = node;
    
    //Go right until null
    while (aux->right != nullptr) {
        aux = aux->right;
    }
    
    return aux;
}

//Destroy tree in post order traverse
void BinaryTree::destroyTree(Node *node){
    if (node == nullptr) {
        return ;
    }
    
    if (node->left!=nullptr) {
        destroyTree(node->left);
    }
    if (node->right!=nullptr) {
        destroyTree(node->right);
    }
    delete node;
    node = nullptr;
}

BinaryTree::~BinaryTree(){
    destroyTree(root);
}