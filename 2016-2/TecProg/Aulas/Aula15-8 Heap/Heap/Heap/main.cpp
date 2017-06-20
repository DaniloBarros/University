//
//  main.cpp
//  Heap
//
//  Created by Danilo Mendes on 8/15/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>

int father(int index){
    int father_index = floor(index/2);
    
    return father_index;
}

int rigth_leaf(int index){
    int right_leaf_index = (index * 2) + 1;
    
    return right_leaf_index;
}

int left_leaf(int index){
    int left_leaf_index = index * 2;
    
    return left_leaf_index;
}

void shift_up(int *vector, int index){
    
    int last = vector[0];
    
    if (index < last && index > 1) {
        
        int index_father = father(index);
        if(vector[index] < vector[index_father]){
            
            int aux = vector[index];
            vector[index] = vector[index_father];
            vector[index_father] = aux;
            
            shift_up(vector, index_father);
        }
    }
}

void insert(int vector){
    
}

int main(int argc, const char * argv[]) {
    
    int vec[9] = {7,3,7,5,4,2,1,5,6};
    std::vector<int> heap;
    
    
    
    
    
    return 0;
}
