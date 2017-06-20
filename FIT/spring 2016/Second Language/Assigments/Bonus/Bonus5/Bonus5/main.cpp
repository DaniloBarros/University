//
//  main.cpp
//  Bonus5
//
//  Created by Danilo Mendes on 3/15/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 In the calling of the program you should enter the
 appropriate testings to run, in a format such as:
 ./main 2 3 4 ...
 The number succeeding the program name being the tests
 Each represent the number of random numbers generated per line
 
 Check if the user inserted testing case
 If not exit program
 Check if the user entered more than one test case
 If so allocate enough memory to hold the test cases
 and initializate the array testCases
 If not initializate testCases with single int
 Then run through the entire test cases and
 call the function getRandomNumbers, passing the
 values entered by the user
 Assert that every number generated is within the
 random range and print them.
 If some error occur during printing the numbers 
 or between calling the function and initializing
 array of random numbers, present to the user in 
 which case the error occured.
 End the program.
 
 */

#include <iostream>
#include <cassert>

#define DEBUG

using namespace std;

int *getRandomNumbers(int num){
    int *arr = nullptr;
    
    if (num<=0) {
        return nullptr;
    }
    
    arr = new int[num];
    
    srand((unsigned int)time(0));
    
    for (int i=0; i<num; i++) {
        arr[i] = rand();
    }
    
    return arr;
}


int main(int argc, const char * argv[]) {
    
    if (!argv[1]) {
        cerr << "ERRO! Missing argv[1]. Aborting..."<<endl;
        exit(1);
    }
    
    int *testCases, *num;
    
    if (argc > 2) {
        
        testCases = new int[argc-1];
        
        for (int i=1; i<argc; i++) {
            testCases[i-1] = atoi(argv[i]);
        }
        
    }else{
        testCases = new int(atoi(argv[1]));
    }
    
    for (int i=0; i<argc-1; i++) {
        
        try {
            num = getRandomNumbers(testCases[i]);

            for (int j=0; j<testCases[i]; j++) {
                assert(num[j] >= 0 && num[j] < RAND_MAX);
                cout << num[j] << " ";
                
            }
            cout << endl;
            
        } catch (...) {
            cout << "Error on test case: " << testCases[i] << endl;
        }
        
        
    }

    return 0;
}
