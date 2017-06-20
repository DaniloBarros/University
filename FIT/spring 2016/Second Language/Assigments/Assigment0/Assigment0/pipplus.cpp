//
//  main.cpp
//  Assigment0
//
//  Created by Danilo Mendes on 1/18/16.
//  Email: dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/**
 The purpose of this exercise is to acquaint you with the C++ 
 programming environment used in the course.
 **/

/*
 Prompt user for number of pods
 Get number of pods
 Prompt user for number of peas in a pod
 Get number of peas in a pod
 Calculate total, total_peas = number_of_pods * peas_per_pod
 Display total
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int number_of_pods, peas_per_pod, total_peas;
    cout << "Hello\n";
    cout << "Press return after entering a number.\n";
    cout << "Enter the number of pods:\n";
    cin >> number_of_pods;
    cout << "Enter the number of peas in a pod:\n";
    cin >> peas_per_pod;
    total_peas = number_of_pods + peas_per_pod;
    cout << "If you have "; cout << number_of_pods; cout << " pea pods\n";
    cout << "and "; cout << peas_per_pod; cout << " peas in each pod, then\n";
    cout << "you have "; cout << total_peas; cout << " peas in all the pods.\n";
    cout << "Good Bye\n";
    return 0;
}
