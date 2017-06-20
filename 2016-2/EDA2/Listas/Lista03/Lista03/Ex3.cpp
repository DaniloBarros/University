//
//  main.cpp
//  Lista03
//
//  Created by Danilo Mendes on 10/1/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>

void printArray(const int* aux, const int start, const int array_size) {
    
    for(int i = start; i < start + array_size; i++){
        std::cout << aux[i] << " ";
    }
    
    std::cout << std::endl;
}

void merge(int* array, unsigned int start, unsigned int end, int* aux){
    int array_size = end - start;
    
    if(array_size > 1){
        int middle = array_size/2;
        int start_second = start + middle;
        
        merge(array, start_second, end, aux);
        merge(array, start, start_second, aux);
        
        int left = start;
        int right = start_second;
        for (int i = start; i < end; i++) {
            
            bool right_ended_or_lower = (right == end || array[left] < array[right]);
            if (left < start_second && right_ended_or_lower) {
                aux[i] = array[left];
                left++;
                
            }else{
                aux[i] = array[right];
                right++;
            }
        }
        
        for (int i = start; i < end; i++) {
            array[i] = aux[i];
        }
        
        printArray(array, start, array_size);
        
    }else{
        return ;
    }
}

int merge_sort(int* array, unsigned int size){
    
    if (size > 0) {
        int *aux = (int*) malloc(size * (sizeof(int)) );
        
        merge(array, 0, size, aux);
        
        free(aux);
        
    }else{
        return 0;
    }
    
    return 1;
}


int main() {
    
    int array[] = {3, 5, 2, 6, 4, 1};
    int array_size = sizeof(array)/sizeof(array[0]);
    
    std::cout << "Initial Array: ";
    printArray(array, 0, array_size);
    std::cout << std::endl;
    
    if(merge_sort(array, array_size)){
        std::cout << "\n\nFinal sorted Array: ";
        printArray(array, 0, array_size);
        
    }else{
        std::cout << "Array size invalid\n";
    }
    
    return 0;
}
