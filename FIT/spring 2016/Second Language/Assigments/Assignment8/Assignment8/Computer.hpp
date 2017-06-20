//
//  Computer.hpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#ifndef Computer_hpp
#define Computer_hpp

#include "DeviceOS.hpp"
#include "Smartphone.hpp"
#include "Printer.hpp"

using namespace std;

class Computer : public DeviceOS {
    
    Smartphone cel;
    vector<Printer> printers;
    
public:
    Computer():DeviceOS(){};
    Computer(string name):DeviceOS(name){};
    Computer(string name, string path):DeviceOS(name,path){};
    
    Smartphone getSmartphone(){return cel;};
    vector<Printer> getPrinters(){return printers;};
    
    bool addFile(File file);
    
    bool installSmartphone(Smartphone *cell);
    bool uninstallSmartphone();
    bool sync();
    
    bool installPrinter(Printer printer);
    bool unistallLastPrinter();
    
    bool scanPhoto(Printer printer);
    bool scanDoc(Printer printer);
    bool print(Printer printer, File file);
    
};

#endif /* Computer_hpp */
