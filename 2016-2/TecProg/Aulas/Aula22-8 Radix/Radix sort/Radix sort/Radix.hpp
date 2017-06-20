//
//  Radix.hpp
//  Radix sort
//
//  Created by Danilo Mendes on 8/22/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef Radix_hpp
#define Radix_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Radix {
    vector<int> vec;
    int count_digit[10]={0};
    
public:
    
    Radix(vector<int> vec) : vec(vec){};
    
    
    void insert(int value);
    
    
};


#endif /* Radix_hpp */
