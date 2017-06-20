//
//  main.cpp
//  class01
//
//  Created by Danilo Mendes on 8/20/15.
//  Copyright (c) 2015 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include "dummy_driver.h"

using namespace std;

void cyborg_data_type_sizes(void){
    cout << sizeof(double) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(bool) << endl;
    cout << sizeof(float) << endl;

}

bool palindrome_number(const std::string & number){
    
    int n = (int) number.length();
    
    for (int i=0; i<n/2; i++) {
        if (number[i]!=number[n-1-i]) {
            return false;
        }
    }
    return true;
}

long fibonacci_sequence(int n){
    
}

int main(int argc, const char * argv[]) {
    
    cout << test1(cyborg_data_type_sizes) << endl;
    
    bool retval = test2(palindrome_number);
    
    cout << retval << endl;
    
    cout << test3(personal_information) << endl;
    
    cout << test4(fibonacci_sequence) << endl;
    
    return 0;
}
