//
//  DeviceOS.hpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef DeviceOS_hpp
#define DeviceOS_hpp

#include <iostream>
#include <vector>
#include "File.hpp"

using namespace std;

class DeviceOS {
    
    
    static int id; // = 0 on .cpp

protected:
    string name;
    vector<File> documents;
    string configFilePath;
    
public:
    DeviceOS() {name = ""; id++; configFilePath="";};
    DeviceOS(string name) :name(name){id++; configFilePath="";};
    DeviceOS(string name, string path);
    
    string getName(){return name;}
    int getId(){return id;}
    vector<File> getDocuments(){return documents;}
    
    void setName(string newName){name = newName;}
    void setDocuments(vector<File> doc){documents = move(doc);}
    
    void getSettings();
    void updateSettings(vector<File> files);
};


#endif /* DeviceOS_hpp */
