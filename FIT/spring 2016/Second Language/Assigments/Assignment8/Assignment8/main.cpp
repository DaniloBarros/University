//
//  main.cpp
//  Assignment8
//
//  Created by Danilo Mendes on 4/17/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include "Computer.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    string pathPc = "ComputerCfg.txt";
    string pathCel = "SmartphoneCfg.txt";
    
    Computer pc = Computer("Danilo's pc", pathPc);
    Smartphone cel = Smartphone("Danilo's Phone", pathCel);
    Printer printer = Printer("Danilo's Printer");
    
    pc.installSmartphone(&cel);
    pc.installPrinter(printer);
    pc.scanPhoto(pc.getPrinters().front());
    pc.scanDoc(pc.getPrinters().back());
    pc.print(pc.getPrinters().back(), pc.getDocuments().back());
    pc.sync();
    
    return 0;
}
