//
//  Printer.hpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef Printer_hpp
#define Printer_hpp

#include <iostream>

class File;

using namespace std;

class Printer{
    bool installed;
    string name;
public:
    Printer(){installed=false; name="";};
    Printer(string name):name(name){installed=false;};
    
    string getName(){return name;};
    void setName(string newName){name=newName;};
    
    File scan(int type);
    bool print(File doc);
    bool isinstalled(){return installed;};
    void install(){installed=true;};
    void unistall(){installed=false;};
    
};

#endif /* Printer_hpp */
