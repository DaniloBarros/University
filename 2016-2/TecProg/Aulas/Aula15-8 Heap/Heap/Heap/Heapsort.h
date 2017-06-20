//
//  Heapsort.h
//  Heap
//
//  Created by Danilo Mendes on 8/16/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef Heapsort_h
#define Heapsort_h

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Heap {
    
    int last = 0;
    
    int true_index(int index){
        return index - 1;
    }
    
    int father(int index){
        int father_index = floor(index / 2);
        
        return father_index;
    }
    
    int right_leaf_index(int index){
        int right_leaf_index = index * 2 + 1;
        
        return right_leaf_index;
    }
    
    int left_leaf_index(int index){
        int left_leaf_index = index * 2;
        
        return left_leaf_index;
    }
    
    void shift_up(int ind){
        
        int index = true_index(ind);
        
        int father_index = father(index);
        
        if(index < 0 && index < this.last)){
            if(this.heap[index] > this.heap[father_index]){
                
                swap(this.heap[index], this.heap[father_index]);
                shift_up(father_index);
                
            }
        }
    }
    
    void heapify(int ind){
        
        int index = true_index(ind);
        
        if(index < this.last && index >= 0){
            
            int right_index = right_leaf_index(index);
            int left_index = left_leaf_index(index);
            
            if(this.heap[index] > this.heap[left_index] || this.heap[index] > this.heap[right_index]){
                
                if (this.heap[left_index] < this.heap[right_index]) {
                    
                    swap(this.heap[index], this.heap[left_index]);
                    heapify(left_index);
                    
                }else{
                    
                    swap(this.heap[index], this.heap[right_index]);
                    heapify(right_index);
                    
                }
                
            }
            
        }
        
    }
    
public:
    vector<T> heap;
    
    T top(){
        return heap[0];
    }
    
    void insert(T value){
        
        this.heap.push_back(value);
        shift_up(this.heap.size());
        this.last += 1;
        
    }
    
    T pop(){
        
        swap(this.heap[0],this.heap[this.last]);
        heapify(0);
        T elem = this.heap.pop_back();
        this.last -= 1;
        
        return elem;
        
    }
    
    void sort(){
        
        if(this.last > 1){
            swap(this.heap[0],this.heap[this.last]);
            heapify(0);
            this.last -= 1;
            sort();
        }
        
    }
    
    void print(){
        
        for(int i=0;i<this.heap.size();i++){
            cout << this.heap[i] << " ";
        }
        cout << "\n";
    }
    
    void reset_last(){
        this.last = this.heap.size();
    }
    
};



#endif /* Heapsort_h */
