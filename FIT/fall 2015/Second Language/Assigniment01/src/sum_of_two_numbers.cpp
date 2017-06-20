/*
PROGRAM: sum_of_two_numbers.CPP
Written by Danilo Barros Mendes
This program accepts two integers, 
stores the sum of these two numbers in a variable named total, and return the total.
Last modification: 08/27/15
*/

/** DO NOT REMOVE THIS INCLUDE STATEMENT **/
#include "dummy_driver.h"
/******************************************/

/** You might need to add some headers here **/

/** DO NOT MODIFY FUNCTION SIGNATURE **/
int sum_of_two_numbers(int num1, int num2){
/**************************************/

    int total = num1 + num2;
    
    return total;

}

/**                       DO NOT MODIFY UNDER THIS LINE
 * ***************************************************************************************/
int main()
{
    
    bool retval = test1(sum_of_two_numbers);
    
    if(retval)
    	return 0;
    else
	return 1;
}
