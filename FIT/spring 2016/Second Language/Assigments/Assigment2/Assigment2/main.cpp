//
//  calorie_calc.cpp
//  Assigment2
//
//  Created by Danilo Mendes on 1/25/16.
//  dbarromendes2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 Prompt user for age in years
 Calculate calories spent in lifetime (3050 per day avarage man)
 Calculate how many items user should have eaten
 Display how many items for user
 
 http://www.livestrong.com/article/278257-how-many-calories-does-the-body-naturally-burn-per-day/
 http://www.livestrong.com/article/308862-how-many-calories-are-in-1-slice-of-cheese-pizza/
 
 */

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int userAgeYears = 0;
    int caloriesSpent = 0;
    double pizzaSlices = 0;
    
    cout << "Enter your age in years: ";
    cin >> userAgeYears;
    
    caloriesSpent = userAgeYears * 365 * 3050;
    pizzaSlices = (double) caloriesSpent / 272;
    
    cout << "You should have eaten " << pizzaSlices << " pizza slices in your lifetime." << endl;
    
    return 0;
}
