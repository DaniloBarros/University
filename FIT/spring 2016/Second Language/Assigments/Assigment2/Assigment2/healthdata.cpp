//
//  healthdata.cpp
//  Assigment2
//
//  Created by Danilo Mendes on 1/25/16.
//  dbarromendes2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 Prompt user for age in years
 Get user age in years
 Calculate days from years
 Display age in days for user
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int userAgeYears = 0;
    int userAgeDays = 0;
    
    cout << "Enter your age in years: " << endl;
    cin >> userAgeYears;
    
    userAgeDays = userAgeYears * 365;
    
    cout << "You are " << userAgeDays << " days old." << endl;
    
    return 0;
}
