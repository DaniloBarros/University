//
//  agecalc.cpp
//  Assigment2
//
//  Created by Danilo Mendes on 1/25/16.
//  dbarromendes2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 Prompt user for age in years
 Calculate heart beats through life time (72 per min)
 Display total heart beats for user
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int userAgeYears = 0;
    unsigned long int heartBeats = 0;
    
    cout << "Enter your age in years: ";
    cin >> userAgeYears;
    
    heartBeats = userAgeYears * 365 * 24 * 60 * 72;
    
    cout << "You had " << heartBeats << " heart beats in your life time." << endl;
    
    return 0;
}
