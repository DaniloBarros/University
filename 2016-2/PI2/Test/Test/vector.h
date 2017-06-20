//
//  vector.h
//  Test
//
//  Created by Danilo Mendes on 11/30/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef vector_h
#define vector_h

#include <math.h>
struct vector{
    float xPos;
    float yPos;
    
    vector(float x = 0.0, float y = 0.0)
    : xPos(x), yPos(y) {}
    
    float calculateMagnitude(){
        return sqrt(pow(xPos,2) + pow(yPos,2));
    }
    
    float getAngle(){
        float deg = 0;
        if(yPos > 0){
            float rad = atan2(yPos,xPos);
            deg = rad * 180/M_PI;
        } else {
            float rad = abs(atan2(yPos,xPos)) + M_PI/2;
            deg = rad * 180/M_PI;
        }
        return deg;
    }
    
    float getDifferenceVector(const vector &vec){
        return vector((xPos - vec.xPos), (yPos - vec.yPos));
    }
    
    bool operator==(const vector &vec){
        return (vec.xPos == xPos) && (vec.yPos == yPos);
    }
    
    bool operator>(vector &vec){
        float magnitude = calculateMagnitude();
        float vecMagnitude = vec.calculateMagnitude();
        
        return (magnitude > vecMagnitude);
    }
    
    bool operator<(vector &vec){
        return !(*this > vec);
    }
    
    vector operator+(const vector &vec){
        return vector((xPos + vec.xPos), (yPos + vec.yPos));
    }
    
    double operator-(vector &vec){
        return getAngle() - vec.getAngle();
    }
    
    operator double const(){
        double teta = atan2(xPos, yPos);
        return teta;
    }
};

int calculateVelocity(double oldSample, double newSample, long &lastProcess, int debug = 0){
    float deltaTime = (std::clock() - lastProcess) / 1000.0;
    lastProcess = std::clock();
    int velocity = (oldSample - newSample) / deltaTime;
    printf("%d", debug);
    return velocity;
}



#endif /* vector_h */
