/*
PROGRAM: annual_pay.CPP
Written by Danilo Barros Mendes
This program calculates the annual pay, based on pay amount and pay periods.
Last modification: 08/27/15
*/

/** DO NOT REMOVE THIS INCLUDE STATEMENT **/
#include "dummy_driver.h"
/******************************************/

/** You might need to add some headers here **/

/** DO NOT MODIFY FUNCTION SIGNATURE **/
double annual_pay(double payAmount, int payPeriods){

    double annualPay = payAmount*payPeriods;
    
    return annualPay;

}


int main()
{
    
    /**                       DO NOT MODIFY UNDER THIS LINE
     * ***************************************************************************************/
    bool retval = test6(annual_pay);
    
    if(retval)
	return 0;
    else
	return 1;
}
