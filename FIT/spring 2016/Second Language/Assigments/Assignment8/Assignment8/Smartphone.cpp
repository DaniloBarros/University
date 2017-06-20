//
//  Smartphone.cpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include "Smartphone.hpp"


bool Smartphone::addFile(File file){
    
    //If file is different from image or sound, do not add
    if (file.getExtension() != ".mp3" && file.getExtension()!=".jpg") {
        return false;
    }
    
    documents.push_back(file);
    
    return true;
    
}

