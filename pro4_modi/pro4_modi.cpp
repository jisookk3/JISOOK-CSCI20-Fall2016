/* Created by: Jisook Kim
 * Created on: 11/9/2016   // updated on 11/16
 * Program 4 - Data Structures
 * Checkbook transaction history
 *** my algorithm was approved on 11/9 
 */
 // prompt a user to open the checkbook
 // class Checkbook // Checkbook array[30];
 // read a file(checkbook.txt) and store each item to the class array
 // separate item from colon -> store data to array[0].SetDeposit(), array[0].SetDate()...
 // calculate balance, sort store name, calculate number of payment and amount of payment
 // open output.txt to write result + put data nicely to read easily
 // close output file
 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Checkbook
{
   private: // variables for each item of checkbook
      string deposit;
      string checkNum;
      string date;
      string store;
      string amount;

    public:
      Checkbook();    // default constructor
      Checkbook(string test); // overloading 
      void SetDeposit(string depo);
      void SetCheckNum(string num);
      void SetDate(string d);
      void SetStore(string name);
      void SetAmount(string amt);
      void print();
        
      string GetDeposit();
      string GetCheckNum();
      string GetDate();
      string GetStore();
      string GetAmount();
};

Checkbook::Checkbook() // default constructor
{
   deposit = "0";
   checkNum = "0";
   date = "0";
   store = "0";
   amount = "0";
}

Checkbook::Checkbook(string temp)  // overloading
{
   deposit = temp;
   checkNum = temp;
   date = temp;
   store = temp;
   amount = temp;
}

void Checkbook::SetDeposit(string depo)
{
   deposit = depo;
}

void Checkbook::SetCheckNum(string num)   // store check num
{
   checkNum = num; // check num  416, 417...
}

void Checkbook::SetDate(string d)
{
   date = d;   // date  7/8, 7/9...
}

void Checkbook::SetStore(string name)
{
   store = name;    // store name   Albertsons, Target...
}

void Checkbook::SetAmount(string amt)
{
   amount = amt;
}

void Checkbook::print()
{
    cout << endl << "Deposit:" << GetDeposit() << "  Check num:" << GetCheckNum()
         << "  Date:" << GetDate() << "  Store:" << GetStore() << "  Amount:" << GetAmount() << endl;
}


string Checkbook::GetDeposit()
{
   return deposit;
}

string Checkbook::GetCheckNum()
{
   return checkNum;
}

string Checkbook::GetDate()
{
   return date;
}

string Checkbook::GetStore()
{
   return store;
}

string Checkbook::GetAmount()
{
   return amount;
}


/////////// main ///////////
int main()
{
   ifstream inF;    // input file stream 
   ofstream outF;  // output file stream
   string filename = ""; 
   string file = ""; // data from a txt file // to store values from a file
   Checkbook array[30]; // object for class Checkbook // maximum 30 lines of checkbook
   int lineNum = 0; // number of line
   int i =0;
   int j =0;
   string minus = "";   // minus sign for deposit amount
   double balance = 0.0;
   int numStore = 0;
   
   string arrayStore[30] = {""};
   double arrayPayment[30] = {0.0};
   
   string compare[30] = { "" };  // to store storename 
   int num = 0;
   int arrayStoreCnt[30] = {0};
   double payTemp[30] = {0.0};

   Checkbook arr1;   // constructor
   arr1.print();
   Checkbook arr2("test");  // overloading
   arr2.print();
   
   // It should ask the user for the name of the file to open.
   // Prompt user for filename to open
   cout << endl << "Enter filename: " << endl;
   cin >> filename; 
   
   // Try to open file
   inF.open(filename);

   // make sure a file exists
   if(!inF.is_open()) 
   {
      cout << "Could not open file, checkbook.txt" << endl;
      return 1;
   }
   
   // read data and store to the array
   cout << endl << "Reading data from your checkbook..." << endl << endl;

   // read file and store data to the array until end of file
   while(!inF.eof()) // return true if end of file
   {
      getline(inF, file, ':'); // read data until a colon

      if(file.find("deposit") == 0) // deposit section
      {
         array[i].SetDeposit(file); // save "deposit"
         getline(inF, file, ':');
         array[i].SetDate(file); // save date
         getline(inF, file, ':'); 
         array[i].SetAmount(file);  
         minus = array[i].GetAmount(); // save '-'
         getline(inF, file);
         file = minus + file; // -300
         array[i].SetAmount(file);  // save amount deposit with the minus sign

         cout << array[i].GetDeposit() <<" " << array[i].GetDate() 
         << "  " <<array[i].GetAmount() << endl;
         i++;  // count each line
      }
      
      else // payment section
      {
         array[i].SetCheckNum(file);   // save check number  416, 417 ...
         getline(inF, file, ':');   
         array[i].SetDate(file);    // save date 
         getline(inF, file, ':');
         array[i].SetStore(file);   // save store
         arrayStore[numStore] = array[i].GetStore(); //move store name to a new array
         
         getline(inF, file);        // the last part ($$$)
         array[i].SetAmount(file);   // save amount paid
         arrayPayment[numStore] = stod(array[i].GetAmount()); //move payment to a new array

         cout << array[i].GetCheckNum() << "     " << array[i].GetDate() 
         << "  " << array[i].GetStore() << "  " << array[i].GetAmount() << endl;
         i++;
         numStore++; // count number of store 
      }
   } // end of file
   
   lineNum = i; // save number of line
   cout << endl <<"number of row = " << lineNum << endl;
   cout << endl <<"number of store = " << numStore << endl;
   
   cout << endl << "Closing file "<< filename << endl << endl;
   inF.close();   // close the file
   
   // balance calculation
   for(j=0; j<lineNum; j++)
   {
      balance += stod(array[j].GetAmount() );
   }
   cout.precision(2);
   cout << fixed << "Balance: $" << 0-balance << endl << endl;

   // check array content
   for(i=0; i< numStore; i++)
      cout << arrayStore[i] << " / $" << arrayPayment[i] << endl;
   cout << endl;
      
   // move storename to a new array not to overlap the name
   num = 0;
   compare[0] = arrayStore[0];
   for(i=1; i<numStore; i++)
   {
      if(compare[0] != arrayStore[i])
      {
         num++;
         compare[num] = arrayStore[i];
      }
   }
   // num = 5 = 4(number of store) + 1

   // count number of store and amount
   for(i=0; i<num; i++)
   {
      for(j=0; j<numStore; j++)
      {
         if(compare[i] == arrayStore[j])
         {
            arrayStoreCnt[i]++;
            payTemp[i] += arrayPayment[j];
         }
      }
   }
   
   // check content
   for(i=0; i<num; i++)
      cout << compare[i] << " / " << arrayStoreCnt[i] << " / $" << payTemp[i] << endl;
   
   
   // open file // writing to a file
    outF.open("output_Checkbook.txt");
    if(!outF.is_open())
    {
        cout << "Could not open file input.txt" << endl;
        return 1;
    }   
   
   // wrtie to file + make the output nice (aligning)
   // set data for each column, set alignment
   outF << endl << " === Checkbook Transaction === " << endl;
   outF << "__________________________________________" << endl;
   outF << setw(6) << right << "Date" << "|";
   outF << setw(9) << right << "Item" << "|";
   outF << setw(14) << right << "Payee" << "|";
   outF << setw(10) << right << "Amount($)" << endl;
   outF << "__________________________________________" << endl;


   // output checkbook all transaction
   for(i=0; i < lineNum; i++)
   {
      if(array[i].GetDeposit() == "deposit")
      {
         outF << setw(6) << right << array[i].GetDate() << "|";
         outF << setw(9) << right << array[i].GetDeposit() << "|";
         outF << setw(14) << right << " " << "|";
         outF << setw(10) << right << array[i].GetAmount() << endl;
      }
      
      else
      {
         outF << setw(6) << right << array[i].GetDate() << "|";
         outF << setw(9) << right << array[i].GetCheckNum() << "|";
         outF << setw(14) << right << array[i].GetStore() << "|";
         outF << setw(10) << right << array[i].GetAmount() << endl;
      }
   }
   
   outF.precision(2);
   outF << endl << fixed << "[Balance]: $" << 0-balance << endl << endl;   
   
   // output each payee result
   outF << endl;
   outF << " === Each payee for checks === " << endl;
   outF << "_______________________________________" << endl;
   outF << setw(14) << right << "Payee" << "|";
   outF << setw(13) << right << "# of payments" << "|";
   outF << setw(10) << right << "Total($)" << endl;
   outF << "_______________________________________" << endl;
   
   for(j=0; j<num; j++)
   {
      outF << setw(14) << right << compare[j] << "|";
      outF << setw(13) << right << arrayStoreCnt[j] << "|";
      outF << setw(10) << right << payTemp[j] << endl;
   }


   outF.close(); // close output file
   
   return 0;
} 