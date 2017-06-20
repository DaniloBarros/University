//
//  Smartphone.hpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef Smartphone_hpp
#define Smartphone_hpp

class Computer;

#include "DeviceOS.hpp"

class Smartphone : public DeviceOS {
    
    bool installed;
    Computer *pc;
    
public:
    
    Smartphone():DeviceOS(){installed=false;};
    Smartphone(string name):DeviceOS(name){installed=false;};
    Smartphone(string name, string path):DeviceOS(name,path){installed=false;};
    
    Computer* getComputer(){return pc;}
    void setComputer(Computer *newPc){pc = newPc;};
    
    bool sync();
    bool sync(int state);
    bool isInstalled(){return installed;};
    void install(){installed = true;};
    void unistall(){installed = false;};
    
    bool addFile(File file);
};

#endif /* Smartphone_hpp */
