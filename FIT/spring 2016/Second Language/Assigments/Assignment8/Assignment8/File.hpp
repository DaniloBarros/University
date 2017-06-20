//
//  File.hpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef File_hpp
#define File_hpp

#include <iostream>

using namespace std;

class File {
    string name;
    string extension;
    
public:
    File():name("untitled"),extension(".jpg"){};
    File(string name, string extension):name(name),extension(extension){};
    
    string getName(){return name;}
    string getExtension(){return extension;}
    
    void setName(string newName){name = newName;}
    void setExtension(string newEx){extension = newEx;}
    
    string toString(){return name + extension;};
    
};

#endif /* File_hpp */
