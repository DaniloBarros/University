/*
 PROGRAM: dummy_driver.h
 Written by Marcello Tomasini
 This program implement the most simple driver to test a function
 */
#include <iostream>
using namespace std;
// DO NOT MODIFY THE SIGNATURE
int test1(int (*func)(int, int)){
/*****************************************/
    
    /** You can add your test cases here by calling func with different parameters **/
    int result = func(17, 11);
    
    bool pass = false;
    if(result == 28)
	pass = true;

    if(!pass)
	std::cout << "ERROR: sum is wrong\n";
    
    // If we reach this point everything was good
    return pass;
}

// DO NOT MODIFY THE SIGNATURE
int test2(double (*func)(double)){
/*****************************************/
    /** You can add your test cases here by calling func with different parameters **/
    double result = func(4.6);
    
    bool pass = false;
    if(result == 2.852)
	pass = true;

    if(!pass)
	std::cout << "ERROR: sales prediction is wrong\n";

    // If we reach this point everything was good
    return pass;
}

// DO NOT MODIFY THE SIGNATURE
int test4(void (*func)(double)){
/*****************************************/
    /** You can add your test cases here by calling func with different parameters **/
    func(10);
    cout << "The meal cost should be: " << 10 << endl
         << "Taxes should be: " << 0.675<< endl
         << "Tip should be: " << 1.60125 << endl
	 << "Total bill should be: " << 12.27625 << endl;

    // If we reach this point everything was good
    return true;
}

// DO NOT MODIFY THE SIGNATURE
int test5(double (*func)()){
/*****************************************/
    /** You can add your test cases here by calling func with different parameters **/
    double retval = func();
    cout << "The sum value should be: " << 154 << endl;
    
    bool pass = false;
    if(retval == 30.8)
	pass = true;

    if(!pass)
	std::cout << "ERROR: average of values is wrong\n";

    // If we reach this point everything was good
    return pass;
}

// DO NOT MODIFY THE SIGNATURE
int test6(double (*func)(double, int)){
/*****************************************/
    
    /** You can add your test cases here by calling func with different parameters **/
    double result = func(1700.00,26);
    
    bool pass = false;
    if(result == 44200)
	pass = true;

    if(!pass)
	std::cout << "ERROR: annual pay is wrong\n";
    
    // If we reach this point everything was good
    return pass;
}
