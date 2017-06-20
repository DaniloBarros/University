//
//  Ex6Array.cpp
//  Lista2
//
//  Created by Danilo Mendes on 9/6/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <ctime>

void print_heap(const int *heap, int length){
    
    for (int i = 1; i <= length; i++) {
        printf("%d ",heap[i]);
    }
    
    printf("\n");
}

int get_left(const unsigned int index){
    int left_child = index * 2;
    
    return left_child;
}

int get_right(const unsigned int index){
    int rigth_child = (index * 2) + 1;
    
    return rigth_child;
}

int get_father(const unsigned int index){
    int father_index = -1;
    
    if (index != 0) {
        father_index = floor(index/2);
    }
    
    return father_index;
}

int* max(int *value1, int *value2){
    if (*value1 >= *value2) {
        return value1;
    }else{
        return value2;
    }
}

void swap(int *value1, int *value2){
    int aux = *value1;
    
    *value1 = *value2;
    *value2 = aux;
    
}

void shift_down(int *heap, int index, int length){
    
    int left_child = get_left(index);
    int right_child = get_right(index);
    int biggest = index;
    
    if (left_child <= length && heap[left_child] > heap[index]) {
        biggest = left_child;
    }
    
    if (right_child <= length && heap[right_child] > heap[biggest]) {
        biggest = right_child;
    }
    
    if (biggest != index) {
        swap(&heap[index], &heap[biggest]);
        shift_down(heap, biggest, length);
    }
    
}

void build_heap(int *heap, int length){
    
    const unsigned int first_root = length/2;
    
    for (int i = first_root; i >= 1; i--) {
        shift_down(heap, i, length);
        
    }
}

void heapsort(int *heap){
    const int root = 1;
    int *length = &heap[0];
    
    build_heap(heap, *length);
    
    for (int i = *length; i >= 2 ; i--) {
        swap(&heap[root], &heap[i]);
        *length -= 1;
        
        shift_down(heap, root, *length);
    }
    
}

int mainn(int argc, const char * argv[]) {
    // First index counts the number of valid indexes after it
    int heap[8] = {7,3,4,2,1,6,5,7};
    int size_heap = (sizeof(heap)/sizeof(heap[0])) -1;
    
    print_heap(heap,size_heap);
    clock_t start = clock();
    heapsort(heap);
    clock_t end = clock();
    print_heap(heap,size_heap);
    double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    std::cout << duration << " ms" << std::endl;
    
    
    
    return 0;
}