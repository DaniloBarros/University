//
//  main.cpp
//  URI
//
//  Created by Danilo Mendes on 3/22/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
using namespace std;

int mcd(int a, int b){
    
    if (b==0) {
        return a;
    }else
        return mcd(b,a%b);
    
}

void minimum(int *n, int *d){
    int num = *n;
    int den = *d;
    int min = mcd(num, den);
    min = abs(min);
    
    *n /= min;
    *d /= min;
    
}

void printMCD(int *n, int *d){
    
    cout << *n << "/" << *d << " = ";
    minimum(n,d);
    cout << *n << "/" << *d << endl;
    
}

int main(int argc, const char * argv[]) {
    
    int T;
    int n1, d1, n2, d2;
    char op;
    cin >> T;
    
    for (int i=0; i<T; i++) {
        
        scanf("%d / %d %c %d / %d",&n1,&d1,&op,&n2,&d2);
        
        switch (op) {
            case '/'://(N1*D2)/(N2*D1)
                n1 *= d2;
                d1 *= n2;
                printMCD(&n1, &d1);
                break;
            case '*'://(N1*N2) / (D1*D2)
                n1 *= n2;
                d1 *= d2;
                printMCD(&n1, &d1);
                break;
            case '+'://(N1*D2 + N2*D1) / (D1*D2)
                n1 = n1*d2 + n2*d1;
                d1 *= d2;
                printMCD(&n1, &d1);
                break;
            case '-'://(N1*D2 - N2*D1) / (D1*D2)
                n1 = n1*d2 - n2*d1;
                d1 *= d2;
                printMCD(&n1, &d1);
                break;
        }
        
    }
    
    return 0;
}
