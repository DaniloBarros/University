//
//  Ex5.cpp
//  Lista2
//
//  Created by Rafael Akiyoshi on 8/25/16.
//  Copyright © 2016 Rafael Akiyoshi. All rights reserved.
//

#include <iostream>
#include <stdio.h>

#define SORTED_NODE 0
#define FIRST_NODE 1
#define LAST_NODE 2

typedef struct Lista {
    int value;
    Lista *next;
    Lista *prev;
}Lista;

typedef struct ADMLista {
    int total;
    Lista *first;
    Lista *last;
}ADMLista;

void imprimeLista(ADMLista *adm){
    Lista *aux = (Lista*)(malloc(sizeof(Lista)));
    aux = adm->first;
    for(int i=0; i<adm->total; i++){
        printf("%d  ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}


void insereNaLista(ADMLista *adm, int key){
    Lista *node = (Lista*)malloc(sizeof(Lista));
    if(adm->total == 0){
        node->value = key;
        node->prev = nullptr;
        node->next = nullptr;
        adm->first = node;
        adm->last = node;
        adm->total += 1;
    } else {
        node->value = key;
        adm->first->prev = node;
        node->next = adm->first;
        node->prev = nullptr;
        adm->total += 1;
        adm->first = node;
    }
}

void swapNode2(ADMLista *adm, Lista *node1, Lista *node2){
    
    Lista *auxNext2 = node2->next;
    Lista *auxPrev1 = node1->prev;
    
    node1->next = auxNext2;
    node2->next = node1;
    
    node1->prev = node2;
    node2->prev = auxPrev1;
    
    if (auxPrev1 != nullptr) {
        auxPrev1->next = node2;
    }
    
    if (auxNext2 != nullptr) {
        auxNext2->prev = node1;
    }
    
    if (adm->first == node1) {
        adm->first = node2;
    }else if (adm->first == node2){
        adm->first = node1;
    }
    
    if (adm->last == node1) {
        adm->last = node2;
    }else if (adm->last == node2){
        adm->last = node1;
    }
    
}

void swapNode(ADMLista *adm, Lista *node1, Lista *node2){
    
    if(node1 == node2){
        return;
        
    }else if(node1->next == node2){
        swapNode2(adm, node1, node2);
        
    }else if(node2->next == node1){
        swapNode2(adm, node2, node1);
    }else{
        
        Lista *auxNext1 = node1->next;
        Lista *auxNext2 = node2->next;
        
        node1->next = node2->next;
        node2->next = auxNext1;
        
        Lista *auxPrev1 = node1->prev;
        Lista *auxPrev2 = node2->prev;
        
        node1->prev = node2->prev;
        node2->prev = auxPrev1;
        
        if (auxNext1 != nullptr) {
            auxNext1->prev = node2;
        }
        if (auxNext2 != nullptr) {
            auxNext2->prev = node1;
        }
        
        if (auxPrev1 != nullptr) {
            auxPrev1->next = node2;
        }
        if (auxPrev2 != nullptr) {
            auxPrev2->next = node1;
        }
        
        
        if (adm->first == node1) {
            adm->first = node2;
        }else if (adm->first == node2){
            adm->first = node1;
        }
        
        if (adm->last == node1) {
            adm->last = node2;
        }else if (adm->last == node2){
            adm->last = node1;
        }
        
    } // else end
    
    /*
     Lista *auxNode1 = (Lista*)(malloc(sizeof(Lista)));
     
     auxNode1->next = node1->next;
     auxNode1->prev = node1->prev;
     
     
     node1->next = node2->next;
     node2->next = auxNode1->next;
     
     node1->prev = node2->prev;
     node2->prev = auxNode1->prev;
     
     if (node1->next != nullptr) {
     node1->next->prev = node1;
     }
     
     if(node2->prev != nullptr){
     node2->prev->next = node2;
     }
     
     //node1->prev->next = node1;
     //node2->next->prev = node2;
     
     if(adm->first == node1){
     adm->first = node2;
     } else if(adm->first == node2){
     adm->first = node1;
     }else{
     //do nothing
     }
     
     if(adm->last == node1){
     adm->last = node2;
     } else if(adm->last == node2){
     adm->last = node1;
     }else{
     //do nothing
     }
     
     */
    
}


/*
 Lista* partition(Lista *l, Lista *h, ADMLista *adm){
 int pivo = l->value;
 
 Lista *aux = h->next; //nullptr
 
 Lista *aux2 = nullptr;
 Lista *node2 = nullptr;
 
 for(Lista *j=h; j!=l; j=j->prev){
 
 if(j->value >= pivo ){
 
 if(aux == nullptr){
 aux = h;
 }else{
 aux = aux->prev;
 }
 
 aux2 = aux;
 swapNode(adm, aux, j);
 aux = j;
 j = aux2;
 }
 }
 
 if(aux == nullptr){
 aux = h;
 }else{
 aux = aux->prev;
 swapNode(adm, aux, h);
 }
 return aux;
 }
 
 
 
 void quickSort(Lista *l, Lista *h, ADMLista *adm)
 {
 if (h != NULL && l != h && l != h->next)
 {
 Lista *p = partition(l, h, adm);
 quickSort(l, p->prev, adm);
 quickSort(p->next, h, adm);
 }
 }
 
 */

Lista** partition(ADMLista *adm, Lista *first, Lista *last){
    
    int pivot = first->value;
    
    Lista *lastSwapedNode = nullptr;
    
    for (Lista *j = last; j != first; j = j->prev) {
        
        if (j->value >= pivot) {
            
            
            if (lastSwapedNode != nullptr) {
                lastSwapedNode = lastSwapedNode->prev;
            }else{
                // As nullptr does not have prev assumes is the last
                lastSwapedNode = last;
            }
            
            
            swapNode(adm, j, lastSwapedNode);
            Lista *aux = lastSwapedNode;
            lastSwapedNode = j;
            j = aux;
            
            if (last == j) {
                last = lastSwapedNode;
            }
            
        }else{
            // Do nothing
        }
        
    }
    
    if (lastSwapedNode != nullptr) {
        lastSwapedNode = lastSwapedNode->prev;
    }else{
        lastSwapedNode = last;
    }
#pragma mark - TODO first e last por referencia estao errados
    
    
    swapNode(adm, lastSwapedNode, first);
    Lista *aux = lastSwapedNode;
    lastSwapedNode = first;
    first = aux;
    
    if (last == first) {
        last = lastSwapedNode;
    }
    
    Lista **sortedPivot = (Lista **) malloc(sizeof(Lista)*3);
    sortedPivot[SORTED_NODE] = lastSwapedNode;
    sortedPivot[FIRST_NODE] = first;
    sortedPivot[LAST_NODE] = last;
    
    imprimeLista(adm);
    return sortedPivot;
}

void quickSort(ADMLista *adm, Lista *first, Lista *last){
    
    if (first != nullptr && last != first && first != last->next && last != first->prev) {
        Lista **sortedNode = partition(adm, first, last);
        
        quickSort(adm, sortedNode[FIRST_NODE], sortedNode[SORTED_NODE]->prev);
        quickSort(adm, sortedNode[SORTED_NODE]->next, sortedNode[LAST_NODE]);
        
    }
    
}


int ex05(){
    ADMLista *adm = (ADMLista*)(malloc(sizeof(ADMLista)));
    adm->total = 0;
    
    insereNaLista(adm, 1);
    insereNaLista(adm, 4);
    insereNaLista(adm, 2);
    insereNaLista(adm, 7);
    insereNaLista(adm, 3);
    insereNaLista(adm, 5);
    imprimeLista(adm);
    quickSort(adm, adm->first, adm->last);
    imprimeLista(adm);
    
    
    return 0;
}



