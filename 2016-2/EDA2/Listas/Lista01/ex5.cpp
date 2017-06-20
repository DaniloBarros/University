#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node *next;
    struct node *prev;
}node;

typedef struct ringList{
    int numElem;
    node *first;
    node *last;
}ringList;

/**
 *  Função de Pesquisa Binária
 *  @param *ring = Lista Circular
 *  @param chave = Valor que deseja ser encontrado
 * */
int PesquisaBinaria (ringList *ring, int chave){
    int inf = 0;
    int i;
    int sup = ring->numElem; //Limite superior  (termina em um número a menos 0 a 9 são 10 numeros )
    int meio;
    while (inf <= sup)
    {
        meio = (inf + sup)/2;
        node *aux = ring->first;
        for(i=0; i<=meio; i++){
            aux = aux->next;
        }
        if (chave == aux->value){
            return meio+1;
        }if (chave < aux->value){
            sup = meio-1;
            aux = ring->first;
        }else{
            inf = meio+1;
            aux = ring->first;
        }
    }
    return -1;   // não encontrado
    
}

int main(){
    int chave = 50; // Altere este se deseja encontrar outro valor na lista
    ringList *ringList1 = (ringList *) malloc(sizeof(ringList));
    node *node1 = (node*) malloc(sizeof(node));
    node *node2 = (node *) malloc(sizeof(node));
    node *node3 = (node *) malloc(sizeof(node));
    node *node4 = (node *) malloc(sizeof(node));
    node *node5 = (node *) malloc(sizeof(node));
    node *node6 = (node *) malloc(sizeof(node));
    node *node7= (node *) malloc(sizeof(node));
    node *node8 = (node *) malloc(sizeof(node));
    node *node9 = (node *) malloc(sizeof(node));
    node *node10 = (node *) malloc(sizeof(node));
    
    
    
    node1->value = 10;
    node2->value = 20;
    node3->value = 30;
    node4->value = 40;
    node5->value = 50;
    node6->value = 60;
    node7->value = 70;
    node8->value = 80;
    node9->value = 90;
    node10->value = 100;
    
    
    
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=node6;
    node6->next=node7;
    node7->next=node8;
    node8->next=node9;
    node9->next=node10;
    node10->next=node1;
    
    
    node1->prev=node10;
    node2->prev=node1;
    node3->prev=node2;
    node4->prev=node3;
    node5->prev=node4;
    node6->prev=node5;
    node7->prev=node6;
    node8->prev=node7;
    node9->prev=node8;
    node10->prev=node9;
    
    
    ringList1->numElem = 10;
    ringList1->first=node1;
    ringList1->last=node10;
    
    
    
    printf("POSICAO %d\n",(PesquisaBinaria(ringList1,chave)));
    node *valueAux;
    valueAux = (ringList1->first);
    int i;
    for(i=0; i<ringList1->numElem; i++){
        printf("\t%d",valueAux->value);
        valueAux=valueAux->next;
    }
    return 0;
}
