//
//  main.cpp
//  Aula8-8 Progamacao Defensiva
//
//  Created by Danilo Mendes on 8/8/16.
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

#include <iostream>
#include <limits.h>

long double multiplica(long double num1, long double num2){
    
    long double res;
    
    res = num1 * num2;
    
    return res;
    
}

int main(int argc, const char * argv[]) {
    
    long double num1, num2;
    
    std::cout << "Digite um numero: ";
    std::cin >> num1;
    std::cout << "Digite um numero: ";
    std::cin >> num2;
    
    std::cout << multiplica(num1, num2);
    
    
    return 0;
}
