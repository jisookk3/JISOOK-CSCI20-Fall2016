/* Created by: Jisook Kim
 * Created on: 11/9/2016 
 * Program 4 - Data Structures
 * Checkbook transaction history
 *** my algorithm was approved on 11/9
 */
 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

class Check
{
    private:
        int deposit;
        string checkNum;
        string date;
        string store;
        double amount;

    public:
        Check();    // default constructor
        Check(string test); // overloading 
        void SetDeposit(string depo);
        void SetCheckNum(string num);
        void SetDate(string d);
        void SetStore(string name);
        void SetAmount(string amt);
        void print();
        
        double GetDeposit();
        string GetCheckNum();
        string GetDate();
        string GetStore();
        double GetAmount();
};

Check::Check() // default constructor
{
    deposit = 0;
    checkNum = "0";
    date = "0";
    store = "0";
    amount = 0;
}

Check::Check(string test)  // overloading
{
//    deposit = test;
    checkNum = test;
    date = test;
    store = test;
//    amount = test;
}

void Check::SetDeposit(string depo)
{
    double convert = 0;
    convert = stoi(depo);    // convert string to int
    deposit = convert; // deposit amount  300 ...
}

void Check::SetCheckNum(string num)   // store check num
{
    checkNum = num; // check num  416, 417...
}

void Check::SetDate(string d)
{
    date = d;   // date  7/8, 7/9...
}

void Check::SetStore(string name)
{
    store = name;    // store name   Albertsons, Target...
}

void Check::SetAmount(string amt)
{
    double convert = 0.0;
    convert = stod(amt);   // convert string to double
    amount = convert;   // cost   15.8, 19.95 ...
}



void Check::print()
{
    cout << endl << "Deposit:" << GetDeposit() << "  Check num:" << GetCheckNum()
         << "  Date:" << GetDate() << "  Store name:" << GetStore() << "  Amount:" << GetAmount() << endl;
}

double Check::GetDeposit()
{
    return deposit;
}

string Check::GetCheckNum()
{
    return checkNum;
}

string Check::GetDate()
{
    return date;
}

string Check::GetStore()
{
    return store;
}

double Check::GetAmount()
{
    return amount;
}


/////////// main ///////////
int main()
{
    ifstream inF;    // input file stream 
    ofstream outF;  // output file stream
    string data = {""}; // data value from a file // to store values from a file
    Check array[30]; // object for class Check // maximum 30 lines of checkbook
    int count =0; // array index
    char openYes = 0;
    int countVal = 0;   // count for rows of file
    double balanceVal = 0.0;    // balance
    int storeCount = 1;
    
    Check arr1;  // consturctor
    arr1.print();
    Check arr2("test"); // overloading
    arr2.print();


    // prompt the user for a text file to read
    // Try to open file
    while(!openYes)
    {
        cout << endl << " Would you like to open your checkbook? (y/n)" << endl;
        cin >> openYes;
        if(openYes == 'Y' || openYes == 'y')
        {
            cout << "Opening file checkbook.txt." << endl;
            openYes = 1;
        }
        else
        {
            cout << "End of the transaction" << endl;
            openYes = 0;
        }
    }

    // make sure a file exists
    inF.open("checkbook.txt");
    if(!inF.is_open())
    {
        cout << "Could not open file, checkbook.txt" << endl;
        return 1;
    }
    
    // read data and store to the array
    cout << "Reading data from your checkbook..." << endl << endl;
    
    int idxStart = 0;
    string data2 = "";
    // read and store numbers to the array from the file until end of file

    while(!inF.eof())   // continue until end of file
    { 
        getline(inF, data); // @@@ read data until the next line @@@ // getline(inF, data, ':')
        
        idxStart = 0; // start point to separate data

       if(data.find("deposit") == 0) // deposit section
       {
            while(data.find(':')!=string::npos) // as long as find ':'
            {
                data.replace(idxStart, data.find(':')+1, ""); // replace item to nothing
            }
            
            // store the last item, deposit amount!
            array[count].SetDeposit(data);
            cout << array[count].GetDeposit() << " - deposit " <<endl;
        } // end if
        
       
       else // payment section
       {
           while(data.find(':')!=string::npos) // as long as find ':'
           {
                data2 = data.substr(idxStart, data.find(':') ); // chop the item before ':'' and store it
                array[count].SetCheckNum(data2); // index stored : num 416
                data.replace(idxStart, data.find(':')+1, "");   // adjust data string deleting the chop part

                data2 = data.substr(idxStart, data.find(':') );
                array[count].SetDate(data2); // next index stored : date 7/8
                data.replace(idxStart, data.find(':')+1, "");
              
                data2 = data.substr(idxStart, data.find(':') );
                array[count].SetStore(data2); // next index stored : store albertsons

                storeCount++;
                data.replace(idxStart, data.find(':')+1, "");
              
                data2 = data.substr(idxStart, data.find(':') );
                array[count].SetAmount(data2); // next index stored : amount 88.99
           } // end while
           
           cout << array[count].GetCheckNum() << " " << array[count].GetDate() << " " 
                << array[count].GetStore() << " " << array[count].GetAmount() << endl;

        } // end else (payment section)
        
        count++;  // go to the next index of array 
    } //end while(!inF.eof())  
    
    cout << endl << "Closing file input.txt" << endl << endl;
    inF.close();   // close the file
    
    // calculate the balance
    while(count > 0) // count = 9 (8 lines)
    {
        balanceVal = balanceVal + array[countVal].GetDeposit() - array[countVal].GetAmount();
        countVal++;
        count--;
    }   
    
    //cout << countVal << "--count" << endl;   // countVal = 9  
    cout.precision(2);
    cout << fixed << "balance: $" << balanceVal << endl;
    
//    cout << storeCount << " # of store " << endl;
    
	// move the name of store to a new array: storeName[]
	int lineNum = 0;
	string storeName[30] = { "" };
	count = countVal; // numbers of rows of checkbook 
	countVal = 0;
	int i= 0;
	int j = 0;

	// if payment, save the row // if not, skip
	for (i = 0; i<count; i++) // count=9 / 8 lines
	{
		if(array[i].GetStore() != "0") // if payment, store array
		{
			storeName[lineNum] = array[i].GetStore();
	    	lineNum++;
		}
	}
	
 	// Get total number of payment
	// USE lineNum!!!
	string compare[30] = { "" }; // save store name(without the same name)
	int temp[30] = { 0 };
	int num = 1; // number of stores
	int totalN = 0;
	int check = 0;

	compare[0] = storeName[0];
	temp[0] = 1;
 	for (j = 1; j < lineNum; j++) // lineNum = 6 // number of index of storeName[]
	{
		for (i = 0; i < num; i++)
		{
			if (compare[i] == storeName[j])	
			{
			    check = 1; 
			    //temp[num]++; // count the number of payment(store name)
			}
        }

        if(check != 1) // all are not the same name of stores then save data
        {
            compare[num] = storeName[j];	
		    num++;
		    //temp[num]++;
        }
        
        check = 0;
    }
    

	//for(i=0; i< num; i++)
	//    cout << temp[i] << " / ";
	
    // open file //writing to a file
    outF.open("output_Checkbook.txt");
    if(!outF.is_open())
    {
        cout << "Could not open file input.txt" << endl;
        return 1;
    }
    
    //wrtie to file + make the output nice(aligning)
   // payee, total number of payments, total cost of payments

   // cout << num << " - count" << endl;  // number of stores
    
    for(i=0; i< num; i++)
    {
        outF << "Payee: " << compare[i] << "  "
             << " # of payments: " << endl;
    }
    
    
    outF.close(); // close output file
    
    return 0;
}