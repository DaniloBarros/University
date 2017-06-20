//
//  main.cpp
//  Assignment6
//
//  Created by Danilo Mendes on 3/14/16.
//  dbarrosmende2015@gmail.com
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 
 Create major variables, 2 arrays for keeping track (amount, sizesub), 1 JaggedArray,
 1 vector(keep track of major categories)
 
 Open categories file, register every major category and count every sub category
 on the first run, then register subcategories in dynamics array.
 (Do this and keep track of the number of subcategories)
 After initializing the major variables open expenditures file
 Register every amount and sub category
 Search for sub category in the already known, from category file
 If found sum to current amount of the category
 If not alert user and sum on MISC category
 Create output string and print to output file and screen
 
 
 FILES
 Category.txt
 File is biult with numbers and phrases
 Separeted by space
 Category/Sub category may have spaces
 New category or subcategory, new line
 Numbers represent if is a category or sub category
 1 category 2 sub category
 FORMAT: 
 1 Health
 2 Doctor
 
 Expenditures
 Have 3 fields, date, amount expent, sub category
 In that order
 Separated with one space
 Sub category can have spaces
 FORMAT:
 3/4/2016 20.22 Music
 
 OUTPUT
 FORMAT:
 Category $amount
 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void print(ostream &c, string s){
    c << s;
}

int main(int argc, const char * argv[]) {
    
    string *categories[12];
    int sizesub[12];
    double amount[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    vector<string> mCategories;
    
    ifstream catFile("/Users/DaniloBarros/Documents/FIT/spring 2016/Second Language/Assigments/Assignment6/Assignment6/Category_File.txt");
    
    int type;
    string sr;
    
    //Read Category File
    for(int i=0;i<2;i++){
        int count1=0, count2=0;
        
        while (!catFile.eof()) {
            catFile >> type;
            catFile.get(); //ignore space
            getline(catFile, sr);
            
            if (type==1) {
                if(i<1){
                    mCategories.push_back(sr);
                
                    if (count2>0) {
                        categories[count1-1] = new string[count2];
                    }
                }
                
                sizesub[count1-1] = count2;
                count1++;
                count2=0;
            }else if(type==2){
                
                if (i>0) {
                    categories[count1-1][count2] = sr;
                    
                }
                count2++;
            }
            
            
            if (catFile.eof() && count2>0 && i<1) {
                categories[count1-1] = new string[count2];
            }
        }
        catFile.clear();
        catFile.seekg(0,ios::beg);
        
    }
    
    FILE *file;
    
    file = fopen("/Users/DaniloBarros/Documents/FIT/spring 2016/Second Language/Assigments/Assignment6/Assignment6/Expenditures_1.txt", "r");
    
    char s[50];
    double p;
    int found=0;
    while (fscanf(file, "%s %lf %[^\n]s",s, &p,s) != EOF) {
        
        for (int i=0; i<12; i++) {
            for (int j=0; j<sizesub[i]; j++) {
                if (categories[i][j].compare(s)==0) {
                    amount[i]+=p;
                    found=1;
                }
            }
        }
        
        if (!found) {
            //Trow into MISC
            cout << s << " not found! Added into MISC."<<endl;
            amount[8]+=p;
        }
        found=0;
    }
    
    ostringstream stream;
    ofstream out("/Users/DaniloBarros/Documents/FIT/spring 2016/Second Language/Assigments/Assignment6/Assignment6/out.txt", ofstream::out | ofstream::app);
    for (int i=0; i<12; i++) {
        stream << mCategories[i] << "\t$" << amount[i] << endl;
    }
    
    print(out, stream.str());
    print(cout, stream.str());
    
    fclose(file);
    catFile.close();
    out.close();
    
    return 0;
}
