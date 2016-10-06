/* Created by: Jisook Kim
 * Created on: 10/5/2016 
 * 3.2 Lab - If/Else 
 * [overview]: calculate the income tax, and amount owed or to be refunded for a person (or couple)
 * The program will take the following basic tax information: name, filing status (single or married), 
 * gross wages, salaries and tips, and the amount of tax withheld. 
 */
 
#include <iostream>
#include <string>
using namespace std;

// tax table for individuals
double taxSingle(double agiUser)
{
    if((agiUser >= 0) && (agiUser <= 8925))
        agiUser = agiUser * 0.1;    //10% of agi
    else if(agiUser <= 36250)
        agiUser = 892.50 + ((agiUser - 8925) *  0.15);
    else if(agiUser <= 87850)
        agiUser = 4991.25 + ((agiUser - 36250) *  0.25);
    else
        agiUser = 17891.25 + ((agiUser - 87850) *  0.28);
        
    return agiUser;
}

// tax table for married couple
double taxMarried(double agiUser2)
{
    if((agiUser2 >= 0) && (agiUser2 <= 17850))
        agiUser2 = agiUser2 * 0.1;    //10% of agi
    else if(agiUser2 <= 72500)
        agiUser2 = 1785 + ((agiUser2 - 17850) *  0.15);
    else
        agiUser2 = 9982.50 + ((agiUser2 - 72500) *  0.28);
        
    return agiUser2;
}
    
int main()
{
    double wage, withheld, tax = 0.0;
    int filingStatus = 0;   //choose a number for single(1) or married(2)
    double agi = 0.0;    //adjusted gross income
    string name;  
    double taxowed, refund = 0.0;
    
    // get user info
    cout << "1. Enter the name:" << endl;
    getline(cin, name);
    cout << "2. Choose your filing status(enter a number): 1.single  2.married:" << endl;
    cin >> filingStatus;
    cout << "3. Enter your total three income sources(wages,interest, and unemployment)($): " << endl;
    cin >> wage;
    cout << "4. Enter your withheld($): " << endl;
    cin >> withheld;
    
    // Get adjusted gross income depending on filing status
    if(filingStatus == 1)   // single
        agi = wage - 3900- 6100;
    else        // married
        agi = wage - (3900*2) - (6100*2); 
    
    // single AND agi <= 0 or married AND agi <= 0   ----> no tax owed
    if(((filingStatus == 1) || (filingStatus == 2)) && (agi <= 0)) // the owed tax is zero
    {
        taxowed = 0;
        refund = 0;
    }
    else if((filingStatus == 1) && (agi > 0))    // single AND agi >0
        taxowed = taxSingle(agi);   // calculate tax using tax tables for a single
    else
        taxowed = taxMarried(agi);
    
    // if(tax > withholding) -> owes more tax
    // else  -> entitled to a refund    
    if(taxowed > withheld)
    {
        refund = 0;
    }
    else
    {
        refund = taxowed;
        taxowed = 0;
    }
    
    // print Tax result
    cout.precision(2);
    cout << "******* Tax Result *******" << endl;
    cout << "Name: " << name << endl;
    cout << "Total Gross Adjusted Income: $" << fixed << agi << endl;
    cout << "Total tax owed: $" << taxowed << endl;
    cout << name <<" is entitled to a REFUND of $" << refund << endl;
    
    return 0;
}