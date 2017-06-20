#include <stdio.h>
#include <stdlib.h>

int buscaIndexada(int indice, int chave, int *vetor);
int main(){
    
    char arg[]={'-','3','2','1','0'};
    
    
    
    
    int vet[10]={12,7,3,90,1,17,6,2,0,-2};
    int i,j;
    int aux;
    int find = vet[8];
    
    
    //Insertion Sort
    for(j=0; j<9; j++){
        for(i=0; i<9; i++){
            if(vet[i]>vet[i+1]){
                aux = vet[i+1];
                vet[i+1] = vet[i];
                vet[i] = aux;
            }
        }
    }
    
    for(i=0; i<10; i++){
        printf("%d\t", vet[i]);
    }
    
    
    //Indices;
    int tamanhoIndex = 10/3;
    int index[tamanhoIndex];
    int resultado;
    for(i=0; i<tamanhoIndex; i++){
        index[i] = vet[i*3];
    }
    
    for(j=0; j<tamanhoIndex; j++){
        if(find>index[j]){
            if(j>=2){
                resultado = buscaIndexada(j*3,find,vet);
            }
            continue;
        } else {
            int indexResult = (j-1)*tamanhoIndex;
            indexResult = indexResult<0?0:indexResult;
            resultado = buscaIndexada(indexResult, find, vet);
            break;
        }
    }
    printf("\n O FIND ESTA NA POSICAO %d", resultado);
    return 0;
}
int buscaIndexada(int indice, int chave, int *vetor){
    int posicao;
    int i;
    for(i=indice; i<=indice+4; i++){
        if(chave==vetor[i]){
            posicao = i;
            return posicao;
        }
    }
    return -1;
}


