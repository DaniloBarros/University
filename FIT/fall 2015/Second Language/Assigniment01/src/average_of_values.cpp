/*
PROGRAM: avarage_of_values.CPP
Written by Danilo Barros Mendes
This program computes the sum of five values and
 returns the avarage of that sum.
Last modification:
*/

/** DO NOT REMOVE THIS INCLUDE STATEMENT **/
#include "dummy_driver.h"
/******************************************/

/** You might need to add some headers here **/

/** DO NOT MODIFY FUNCTION SIGNATURE **/
double average_of_values(){
    
    double n=28, m=32, k=37, l=24, p=33;
    
    double sum = n+m+k+l+p;
    
    cout << sum << endl << sum/5 << endl;
    
    return sum/5;
    
    //return 30.8
}


int main()
{
    
    /**                       DO NOT MODIFY UNDER THIS LINE
     * ***************************************************************************************/
    bool retval = test5(average_of_values);
    
    if(retval)
	return 0;
    else
	return 1;
}
