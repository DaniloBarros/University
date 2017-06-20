//
//  gradecalc.cpp
//  Assigment1
//
//  Created by Danilo Mendes on 1/20/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 
 Colect homework score
 Colect quiz score
 Colect midterm score
 Colect final score
 Calculate homework part
 Calculate quiz part
 Calculate midterm part
 Calculate final part
 Calculate course percentage
 Convet course percentage to percentage
 Display in prompt course percentage
 
 */

#include<iostream>
using namespace std;

int main() {
    const double HOMEWORK_MAX = 80.0;
    const double QUIZ_MAX = 20.0;
    const double MIDTERM_MAX = 40.0;
    const double FINAL_MAX = 70.0;
    const double HOMEWORK_WEIGHT = 0.10; // 20%
    const double QUIZ_WEIGHT = 0.15;
    const double MIDTERM_WEIGHT = 0.30;
    const double FINAL_WEIGHT = 0.45;
    
    double homeworkScore= 0.0;
    double quizScore = 0.0;
    double midtermScore= 0.0;
    double finalScore = 0.0;
    double coursePercentage= 0.0;
    
    cout << "Enter homework score: " << endl;
    cin >> homeworkScore;
    
    cout << "Enter quiz score: " << endl;
    cin >> quizScore;
    
    cout << "Enter midterm exam score:" << endl;
    cin >> midtermScore;
    
    cout << "Enter final exam score: " << endl;
    cin >> finalScore;
    
    double homeworkPart = (homeworkScore / HOMEWORK_MAX);
    double quizPart = (quizScore / QUIZ_MAX);
    double midtermPart = (midtermScore / MIDTERM_MAX);
    double finalPart = (finalScore / FINAL_MAX);
    
    coursePercentage = homeworkPart*HOMEWORK_WEIGHT
        + quizPart*QUIZ_WEIGHT
        + midtermPart*MIDTERM_WEIGHT
        + finalPart*FINAL_WEIGHT;
    
    coursePercentage = coursePercentage * 100;
    cout << endl << "Your course percentage: ";
    cout << coursePercentage << endl;

    return 0;
}
