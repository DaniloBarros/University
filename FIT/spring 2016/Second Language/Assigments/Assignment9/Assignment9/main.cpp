//
//  main.cpp
//  Assignment9
//
//  Created by Danilo Mendes on 4/26/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

void randValues(int times, BinaryTree *bt){
    srand(time(nullptr));
    
    for (int i=0; i<times; i++) {
        int random = rand()%50+1;
        
        bt->insert(random);
        cout << random << " ";
    }
    
    cout << "\n";
}

void testInsert(BinaryTree *bt){
    
    bt->insert(55);
    bt->insert(30);
    bt->insert(76);
    bt->insert(20);
    bt->insert(40);
    bt->insert(70);
    bt->insert(80);
    bt->insert(50);
    bt->insert(35);
    bt->insert(90);
    bt->insert(45);
    
}

int main(int argc, const char * argv[]) {
    
    BinaryTree bt = BinaryTree();

    //Change to get a better test
    bool test = false;
    cout<<"Sequence inserted: ";
    
    if (test) {
        cout << "55 40 76 20 40 70 80 50 35 90 45\n";
        testInsert(&bt);
        
        cout<<"\nPrints (Inorder, Preorder, PostOrder):\n";
        bt.printIn(); cout << "\n";
        bt.printPre(); cout << "\n";
        bt.printPos(); cout << "\n";
        
        cout << "Insert 46.\n";
        bt.insert(46);
        bt.printIn(); cout << "\n";
        bt.printPre(); cout << "\n";
        bt.printPos(); cout << "\n";
        
        cout << "Remove 40.\n";
        bt.remove(40);
        bt.printIn(); cout << "\n";
        bt.printPre(); cout << "\n";
        bt.printPos(); cout << "\n";
        
    }else{
        randValues(8, &bt);
        
        cout<<"\nPrints (Inorder, Preorder, PostOrder):\n";
        bt.printIn(); cout << "\n";
        bt.printPre(); cout << "\n";
        bt.printPos(); cout << "\n";
        
        cout << "Insert 22.\n";
        bt.insert(22);
        bt.printIn(); cout << "\n";
        bt.printPre(); cout << "\n";
        bt.printPos(); cout << "\n";
        
        cout << "Remove 22.\n";
        bt.remove(22);
        bt.printIn(); cout << "\n";
        bt.printPre(); cout << "\n";
        bt.printPos(); cout << "\n";
    }
    return 0;
}
