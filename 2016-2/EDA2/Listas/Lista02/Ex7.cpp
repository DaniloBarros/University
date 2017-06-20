//
//  Ex7.cpp
//  Lista2
//
//  Created by Danilo Mendes on 9/6/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void print_vec(int vec[], int size){
    for (int i=0; i<size; i++) {
        cout << vec[i] << " ";
    }
}

int get_max(int vec[], int size){
    
    int max = vec[0];
    
    for (int i=0; i<size; i++) {
        if(vec[i] > max){
            max = vec[i];
        }
    }
    
    return max;
    
}
/**
 * @param vec[] - int : vetor a ser ordenado
 * @param size - int : tamanho do vetor
 * @param expo - int : expoente que o algoritimo ira levar em conta (0, 10, 100, ...)
 */
void count_sort(int vec[], int size, int expo){
    
    // Array para contar a recorrencia de numeros de 0-10
    int count_num[10]={0};
    
    // Faz a contagem dos numeros
    for (int i=0; i<size; i++) {
        // Unidade do algarismo equivalente ao expoente
        int num = (vec[i]/expo)%10;
        // Incrementa o numero de recorrencia do numero
        count_num[num]++;
    }
    
    /* Faz a contagem das posicoes corretas de acordo com o numero da
     contagem dos algarismos presentes
     */
    for (int i=1; i<10; i++) {
        count_num[i] += count_num[i-1];
    }
    
    // Array para copia dos valores
    int output[size];
    for (int i=size-1; i>=0; i--) {
        int num = (vec[i]/expo)%10;
        int new_index = count_num[num] - 1;
        
        output[new_index] = vec[i];
        count_num[num]--;
        
    }
    
    // Copia output ordenado para o array
    for (int i=0; i<size; i++) {
        vec[i] = output[i];
    }
    
}

void radix_sort(int vec[], int size){
    
    int higher_number = get_max(vec, size);
    
    for (int expo = 1; higher_number / expo > 0; expo *= 10) {
        count_sort(vec, size, expo);
    }
    
}

// Algoritimo de busca por interpolacao
int interpolation_search(int vec[], int size, int key){
    // Inicializa os indices
    int high = size - 1;
    int low = 0;
    int mid = 0;
    
    while (vec[low] < key && vec[high] >= key) {
        int dividend = (key - vec[low]);
        int divisor = (vec[high]-vec[low]);
        
        //Calculo para achar a mediana e dar um bom chute do indice
        mid = low + (high - low) * ( dividend / divisor );
        
        // Verifica se achou o indice correto
        if (key > vec[mid]) {
            low = mid + 1;
        }else if (key < vec[mid]){
            high = mid - 1;
        }else{
            return mid;
        }
        
    }
    
    if (vec[low] == key) {
        return low;
    }else{
        return -1;
    }
    
}

int principal(int argc, const char * argv[]) {
    
    unsigned int sizes[] = {10, 100, 1000, 10000, 100000, 1000000};
    int lenght_sizes = sizeof(sizes)/sizeof(sizes[0]);
    double times[lenght_sizes];
    
    for (int i=0; i<lenght_sizes; i++) {
        int size = sizes[i];
        int vetor[size];
        
        // Criar variaveis para criar numeros randomicos de forma uniforme
        const int range_from = 10000000;
        const int range_to = 99999999;
        random_device rand_dev;
        mt19937 generator(rand_dev());
        uniform_int_distribution<int> distribution(range_from,range_to);
        
        
        // Popular o array
        
        for (int i=0; i<size; i++) {
            vetor[i] = distribution(generator);
        }
        
        // Variavel pra guarda o tempo de clock antes da busca
        clock_t start = clock();
        
        // Ordenar o Array
        
        radix_sort(vetor, size);
        
        // Tempo de termino da busca por interpolacao
        clock_t end = clock();
        
        // Duracao em milisegundos
        double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        times[i] = duration;
        
        //print_vec(vetor, size);
        //cout << "\n\n\n";
        
    }
    
    for (int i=0; i<lenght_sizes; i++) {
        cout << "Size = " << sizes[i] << endl;
        
        cout << "CPU time used: " << times[i] << " ms" << endl;
        
    }
    
    return 0;
}
