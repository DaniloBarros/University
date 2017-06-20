/*
 PROGRAM: dummy_driver.h
 Written by Marcello Tomasini
 This program implement the most simple driver to test a function
 */
#include<iostream>

// DO NOT MODIFY THE SIGNATURE
bool test1(void (*func)(void)){
/*****************************************/
    
    /** You can add your test cases here by calling func with different parameters **/
    func();
    
    // If we reach this point everything was good
    return true;
}

// DO NOT MODIFY THE SIGNATURE
bool test2(bool (*func)(const std::string &)){
/*****************************************/
    /** You can add your test cases here by calling func with different parameters **/
    
    bool pass = false;
    if(func("123454321"))
        pass = true;
    if(!pass)
        std::cout << "ERROR: number is palindrome\n";

    pass = false;
    if(!func("1234567890"))
	pass = true;
    if(!pass)
        std::cout << "ERROR: number is not palindrome\n";

    // If we reach this point everything was good
    return pass;
}

// DO NOT MODIFY THE SIGNATURE
bool test3(void (*func)(void)){
/*****************************************/
    
    /** You can add your test cases here by calling func with different parameters **/
    func();
    
    // If we reach this point everything was good
    return true;
}

// DO NOT MODIFY THE SIGNATURE
bool test4(long (*func)(int)){
    /*****************************************/
    /** You can add your test cases here by calling func with different parameters **/
    bool pass = false;
    if(func(43) == 433494437)
        pass = true;
    
    if(!pass)
        std::cout << "ERROR: wrong computation\n";
    
    pass = false;
    if(func(-17) == -1)
        pass = true;
    
    if(!pass)
        std::cout << "ERROR: invalid input\n";

    // If we reach this point everything was good
    return pass;
}

// DO NOT MODIFY THE SIGNATURE
int test5(std::string (*func)(int)){
    /*****************************************/
    /** You can add your test cases here by calling func with different parameters **/
    bool pass = false;
    if(func(10) == "X")
        pass = true;
    if(!pass)
        std::cout << "ERROR: wrong return value\n";
    
    pass = false;
    if( (func(11) == "none") && (func(0) == "none") )
        pass = true;
    if(!pass)
        std::cout << "ERROR: invalid input\n";
    
    // If we reach this point everything was good
    return pass;
}

