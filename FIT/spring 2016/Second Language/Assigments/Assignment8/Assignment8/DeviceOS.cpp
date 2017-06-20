//
//  DeviceOS.cpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include "DeviceOS.hpp"
#include <fstream>
#include <sstream>
#include <string>

//static variable that increases with every instance
int DeviceOS::id = 0;

DeviceOS::DeviceOS(string name, string path):DeviceOS(name){
    configFilePath=path;
    getSettings();
}

void DeviceOS::getSettings(){
    //If a path is not defined, defines one
    if (configFilePath.compare("")==0) {
        configFilePath = "Cg" + to_string(id) + ".txt";
    }
    
    //Create a file
    ifstream cfgFile(configFilePath);
    
    string filename, extension;
    //Delimitador to separate the two strings
    char delimitator('.');
    
    while (!cfgFile.eof()) {
        getline(cfgFile, filename, delimitator);
        getline(cfgFile, extension);
        
        //if getline gets nothing go to next loop
        if (filename.compare("")==0) {
            continue;
        }
        
        //Create a file, adding the delimitator to the extension
        File file(filename,delimitator+extension);
        
        //Add the file to documents
        documents.push_back(file);
        
    }
    cfgFile.close();
}

void DeviceOS::updateSettings(vector<File> files){
    if (configFilePath.compare("")==0) {
        configFilePath = "Cg" + to_string(id) + ".txt";
    }
    
    ostringstream ss;
    
    //For every file print a line with name.extension
    for (int i=0; i<files.size(); i++) {
        ss << files[i].toString() << "\n";
    }
    
    //Output file that rewrites everything
    ofstream output(configFilePath,ofstream::out | ofstream::trunc);
    
    output << ss.str();
    
    output.close();
    
    //update documents from output file
    getSettings();
    
}
