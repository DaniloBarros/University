//
//  Computer.cpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include "Computer.hpp"
#include <unistd.h>

//static int to save every scanned file with different names
static int fileint = 0;

//Adds compatible files to vector
bool Computer::addFile(File file){
    
    bool test1 = file.getExtension().compare(".doc")!=0;
    bool test2 = file.getExtension().compare(".mp3")!=0;
    bool test3 = file.getExtension().compare(".jpg")!=0;
    
    if (test1 && test2 && test3) {
        return false;
    }
    
    documents.push_back(file);
    
    return true;
    
}

//Install a smartphone to the computer
bool Computer::installSmartphone(Smartphone *cell){

    //Generates a random number to wait a random time
    srand((long)time(nullptr));
    unsigned int i = (rand() % 1000000 + 500000); //0.5 - 1 s
    cout << "Installing";
    for (int j=0; j<3; j++) {
        cout << ".";
        usleep(i);
    }
    
    //Setup the installation from both sides
    cell->install();
    cell->setComputer(this);
    cel = *cell;
    
    
    cout << "\nCompleted! " << cell->getName() << " installed!\n";
    
    return true;
}

bool Computer::uninstallSmartphone(){
    
    //If a smartphone exists uninstall it from both sides
    if (cel.getName()!="") {
        cel.unistall();
        cel = Smartphone();
    }else
        return false;
    
    return true;
}

bool Computer::sync(){
    
    //return false is there is no smartphone
    if (!cel.isInstalled()) {
        return false;
    }
    
    cout << this->getName() << " is syncing with " << cel.getName() << endl;
    
    //If there is no documents in smartphone add all
    //documents from pc to cel and update the settings
    if (cel.getDocuments().size()==0) {
        for (int i=0; i<documents.size(); i++) {
            cel.addFile(documents[i]);
        }
        cel.updateSettings(cel.getDocuments());
        return true;
    }
    
    //Flag to set if file is found in other side
    bool exists = false;
    
    //Travesse all files and compare them
    for (int i=0; i<documents.size(); i++) {
        
        for (int j=0; j<cel.getDocuments().size(); j++) {
            File file = cel.getDocuments()[j];

            if (documents[i].toString().compare(file.toString())==0) {
                exists=true;
                break;
            }
        }
        
        if (!exists) {
            cel.addFile(documents[i]);
        }
        exists=false;
        
    }
    
    //Sync from smartphone side
    cel.sync(1);
    
    updateSettings(documents);
    
    return true;
}

//Just to conform with requirements "sync()"
bool Smartphone::sync(){
    
    if (!pc) {
        return false;
    }
    
    return pc->sync();
}

bool Smartphone::sync(int state){
    
    cout << this->getName() << " is syncing with " << pc->getName() << endl;
    
    if (pc->getDocuments().size()==0) {
        pc->updateSettings(documents);
        return true;
    }
    
    bool exists = false;
    
    for (int i=0; i<documents.size(); i++) {
        for (int j=0; j<pc->getDocuments().size(); j++) {
            File file = pc->getDocuments()[j];
            
            if (documents[i].toString().compare(file.toString())==0) {
                exists = true;
                
            }
        }
        
        if (!exists) {
            pc->addFile(documents[i]);
        }
        exists=false;
    }
    
    updateSettings(documents);
    
    return true;
}

bool Computer::installPrinter(Printer printer){
    
    if (printer.getName().compare("")==0) {
        return false;
    }
    
    srand((long)time(nullptr));
    unsigned int i = (rand() % 1000000 + 500000); //0.5 - 1 s
    cout << "Installing";
    for (int j=0; j<3; j++) {
        cout << ".";
        usleep(i);
    }
    
    printer.install();
    printers.push_back(printer);
    
    cout << "\nCompleted! "<<printers.back().getName() << " Installed!\n";
    
    return true;
    
}

bool Computer::unistallLastPrinter(){
    
    if (printers.size()==0) {
        return false;
    }
    cout << printers.back().getName() << " Uninstalled\n";
    printers.pop_back();
    return true;
}

bool Computer::scanDoc(Printer printer){
    
    addFile(printer.scan(0));
    
    return true;
}

bool Computer::scanPhoto(Printer printer){
    
    addFile(printer.scan(1));
    
    return true;
}

bool Computer::print(Printer printer, File file){
    
    if(!printer.isinstalled())
        return false;
    
    return printer.print(file);
    
}


bool Printer::print(File doc){
    
    srand((long)time(nullptr));
    unsigned int i = (rand() % 1000000 + 500000);
    
    //if it is a image, double the time
    if (doc.getExtension().compare(".jpg")==0){
        i*=2;
    }else if(doc.getExtension().compare(".doc")==0) {
        
    }else{
        return false;
    }
    
    cout << "Printing";
    for (int j=0; j<3; j++) {
        cout << ".";
        usleep(i);
    }
    
    cout << "\nDone!\n";
    
    return true;
}

File Printer::scan(int type){
    
    if(!isinstalled()){
        File aux = File("Error",".err");
        return aux;
    }
    
    //If entered anyother number
    if (type > 1 || type<0) {
        //Treat as a image
        type = 0;
    }
    
    //Create a unique name
    string extensions[] = {".doc", ".jpg"};
    string name = "file_" + to_string(fileint);
    fileint++;
    File file = File(name,extensions[type]);
    
    srand((long)time(nullptr));
    unsigned int i = (rand() % 1000000 + 500000);
    
    if (extensions[type].compare(".jpg")==0){
        i*=2;
    }
    
    cout << "Scaning " << (type==0?"Document":"Photo");
    for (int j=0; j<3; j++) {
        cout << ".";
        usleep(i);
    }
    
    cout << "\nDone!\n";
    
    
    return file;
}