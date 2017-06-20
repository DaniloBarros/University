//
//  agecalc.cpp
//  Assigment2
//
//  Created by Danilo Mendes on 1/25/16.
//  dbarromendes2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 Prompt user for age in days
 Display age calculated for months and days for user
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int userAgeYears = 0;
    int userAgeDays = 0;
    
    cout << "Enter your age in days: ";
    cin >> userAgeDays;
    
    cout << "You are " << userAgeDays / 30 << " months and ";
    cout << userAgeDays % 30 << " days old." << endl;
    
    return 0;
}
