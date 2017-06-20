//
//  pid.hpp
//  Test
//
//  Created by Danilo Mendes on 11/30/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef pid_hpp
#define pid_hpp

template <class T>
class PID{
    public:
    
    double error;
    T sample;
    T lastSample;
    double kP, kI, kD;
    double I;
    
    T setPoint;
    long lastProcess;
    
    PID(double _kP, double _kI, double _kD, T _set){
        kP = _kP;
        kI = _kI;
        kD = _kD;
        I = 0;
        setSetPoint(_set);
    }
    
    void addNewSample(T _sample){
        sample = _sample;
    }
    
    void setSetPoint(T _setPoint){
        setPoint = _setPoint;
    }
    
    double process(){
        error = setPoint - sample;
        
        //float deltaTime = (millis() - lastProcess) / 1000.0;
        //lastProcess = millis();
        
        double P = error * kP;
        //I = I + (error * kI) * deltaTime;
        //double D = (lastSample - sample) * kD / deltaTime;
        lastSample = sample;
        
        double pid = P + I;// + D;
        
        return pid;
    }
    
};

#endif /* pid_hpp */
