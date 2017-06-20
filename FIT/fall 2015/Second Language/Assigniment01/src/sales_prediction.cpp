/*
 PROGRAM: sales_prediction.CPP
 Written by Danilo Barros Mendes
 This program accepts the amount of sales of the company in millions,
 and predicts how much the East Coast division will generate this year.
 Last modification: 08/27/15
 */

/** DO NOT REMOVE THIS INCLUDE STATEMENT **/
#include "dummy_driver.h"
/******************************************/

/** You might need to add some headers here **/

/** DO NOT MODIFY FUNCTION SIGNATURE **/
double sales_prediction(double totalSales){

    return totalSales * 0.62;

}


int main()
{
    
    /**                       DO NOT MODIFY UNDER THIS LINE
     * ***************************************************************************************/
    bool retval = test2(sales_prediction);
    
    if(retval)
    	return 0;
    else
	return 1;
}
