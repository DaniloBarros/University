//
//  main.cpp
//  BonusBirth
//
//  Created by Danilo Mendes on 2/23/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 
 Read file and store data in variables
 Prompt user for name to search in the rank
 Search for the name in the rank
 If the name maches save the number of the position for the gender
 If both genders are found stop the search
 Create a string that can be prompted for the user, and written in a file
 Prompt the string for the user and print it on a file
 Ask the user if he wants to use the program again
 If so, run it again
 If not end the program
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void print(ostream &c, string s){
    c << s;
}

int main(int argc, const char * argv[]) {
    
    int op=0;
    ifstream dbFile("/Users/DaniloBarros/Documents/FIT/spring 2016/Second Language/Assigments/Bonus/BonusBirth/BonusBirth/Database.txt");
    ofstream output;
    //output.open("/Users/DaniloBarros/Documents/FIT/spring 2016/Second Language/Assigments/Bonus/BonusBirth/BonusBirth/Output.txt", ofstream::out | ofstream::app);
    
    string names[2][1000];
    string name;
    
    for(int i=0; dbFile >> op >> names[0][i] >> names[1][i];i++){
        //Reading File...
    }
    
    do{
        
        cout << "Enter a name to search in the database: ";
        cin >> name;
        
        int m = -1, f = -1;
        
        for (int i=0; i<1000; i++) {
            if (names[0][i].compare(name)==0) {
                m = i + 1;
            }
            if (names[1][i].compare(name)==0) {
                f = i + 1;
            }
            if (m!=-1 && f!=-1) {
                break;
            }
        }
        
        ostringstream s, ss;
        
        if(m!=-1){
            s << name << " is ranked " << m << " in popularity among boys." << endl;
        }else{
            s << name << " is not ranked among the top 1000 boys names." << endl;
        }
        
        if (f!=-1) {
            ss << name << " is ranked " << f << " in popularity among girls." << endl;
        }else{
            ss << name << " is not ranked among the top 1000 girls names." << endl;
        }
        
        print(std::cout, s.str());
        print(std::cout, ss.str());
        
        output.open("/Users/DaniloBarros/Documents/FIT/spring 2016/Second Language/Assigments/Bonus/BonusBirth/BonusBirth/Output.txt", ofstream::out | ofstream::app);
        print(output, s.str());
        print(output, ss.str());
        output.close();
        
        
        
        cout << endl << "Do you want to continue using the program? ";
        
        do{
            cout << "(1 YES / 0 NO): ";
            cin >> op;
            
            cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            
        }while(op!=0 && op!=1);
        
    }while(op==1);
    
    return 0;
}
