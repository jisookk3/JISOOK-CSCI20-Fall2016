/* Created by: Jisook Kim
 * Created on: 9/29/2016 
 * Program 2 - Functions: Banking program for an ATM (deposits, withdraws, etc.)
 * Overview: ATM transaction(deposits and withdraws) and print the bank statement(current balance)
 * My algorithm is approved on 9/29.
 */
 
#include <iostream>
using namespace std;

// class declaration
class banking
{
    private:
        int deposit;    // int type: dollar bill only accepted
        int withdraw;
        int balance;
    public:
        banking();      // default constructor
        banking(int userIn);    // overloaded constructor
        void SetDeposit(int userIn);   // mutator: store deposit value from input
        void SetWithdraw(int userIn);   //mutator: store withdraw value from input
        int GetDeposit();       // accessor
        int GetWithdraw();      // accessor
        int GetCurrentB();      // accessor: return the account balance
        const void print();   // bank statement
};
 
banking::banking() // default constructor
{
    deposit = 0;
    withdraw = 0;
    balance = 0;
}
 
banking::banking(int userIn)   // overloaded constructor
{
    deposit = userIn; 
    withdraw = userIn;
    balance = deposit - withdraw;
}

// store deposit and calculate the balance
void banking::SetDeposit(int userIn) 
{
    deposit = userIn;
    balance = balance + deposit; 
}

// store withdraw and calculate the balance
void banking::SetWithdraw(int userIn)   
{
    withdraw = userIn;
    balance = balance - withdraw;  
 }

int banking::GetDeposit() 
{
    return deposit;
}

int banking::GetWithdraw()
{
    return withdraw;
}

// current balance
int banking::GetCurrentB()   
{
    if(balance < 0)     // if overdrawn, print an error message
    {
        cout << "*** INSUFFICIENT FUND! Please check your current balance ***" << endl << endl;
    }
    return balance;
}

 
const void banking::print()
 {
    cout << "===================== Bank Statement ========================" << endl;
    cout << "Deposit: $" << GetDeposit() << " || Withdraw: $" << GetWithdraw() 
         << " || Current Balance: $" << GetCurrentB() << endl
         << " *Note: The amount of deposit and withdraw on this slip is from the last transaction" << endl;
    cout << "=============================================================" << endl << endl;
 }
 
 
int main()
{
    banking trans1;    // testing default constructor
    trans1.print();
    
    banking trans2(30);   // testing overloaded constructor
    trans2.print();
     
    trans1.SetDeposit(100);    // deposit $100
    cout << "Deposit $" << trans1.GetDeposit() << endl;
    trans1.SetWithdraw(20);    // withdraw $20
    cout << "Withdraw $" << trans1.GetWithdraw() << endl;
    trans1.print();    // bank statement printed: deposit, withdraw, current balance
     
    trans1.SetWithdraw(60);
    cout << "Withdraw $" << trans1.GetWithdraw() << endl;
    trans1.SetWithdraw(40);    // overdrawn: this should be error! (negative value printed)
    cout << "Withdraw $" << trans1.GetWithdraw() << endl;
    trans1.print();    // bank statement
     
    trans1.SetDeposit(73);
    cout << "Deposit $" << trans1.GetDeposit() << endl;
    trans1.SetWithdraw(40);
    cout << "Withdraw $" << trans1.GetWithdraw() << endl;
    trans1.print();
     
    return 0;
}