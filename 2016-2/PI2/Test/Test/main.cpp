//
//  main.cpp
//  Test
//
//  Created by Danilo Mendes on 11/25/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include "vector.h"
#include "pid.hpp"

int main(int argc, const char * argv[]) {
 
    
    vector set_point(0.0, 20.0);
    PID<vector> pid = *new PID<vector>(0.5, 0.025, 0, set_point);
    
    vector vec(0.62, 32.14);
    vector vec2(0.0, 20.0);
    bool o = (vec != vec2);
    double x = vec.getAngle();
    double w = vec2.getAngle();
    double y = vec2 - vec;
    
    long s = std::clock();
    
    int i = calculateVelocity(0, 4, s, 1);
    
    
    pid.addNewSample(vec);
    pid.process();
    pid.addNewSample(vec2);
    pid.process();
    
    vector vec3 = vec2 - vec;
    
    
    
    return 0;
}
