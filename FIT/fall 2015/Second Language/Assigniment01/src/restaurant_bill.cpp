/*
 PROGRAM: restaurant_bill.CPP
 Written by Danilo Barros Mendes
 This program
 Last modification: 08/27/15
 */

/** DO NOT REMOVE THIS INCLUDE STATEMENT **/
#include "dummy_driver.h"
/******************************************/

/** You might need to add some headers here **/

using namespace std;

/** DO NOT MODIFY FUNCTION SIGNATURE **/
void restaurant_bill(double mealCharge){

    double tax = 0.0675;
    double tip = 0.15;
    
    cout << "The meal cost should be: " << mealCharge << endl
    << "Taxes should be: " << mealCharge*tax << endl;
    cout << "Tip should be: " << (mealCharge*(1+tax))*tip << endl
    << "Total bill should be: " << (mealCharge*(1+tax))*(1+tip) << endl;
    
    
}


int main()
{
    
    /**                       DO NOT MODIFY UNDER THIS LINE
     * ***************************************************************************************/
    bool retval = test4(restaurant_bill);
    
    return 0;
}
