/* Created by: Jisook Kim
 * Created on: 11/8/2016 
 * 4.5 Lab - File Input/Output
 * Use file input to read in a file with a list of numbers separated by a space that is four numbers in a line.
 * Store these values in a two dimensional array.  Average all numbers in the matrix.  
 * Add up each line and each column of the array.
 * Output the array and totals into an output file named output.txt.  
 * Use the stream manipulators to make the output nice.
 */
 
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream inFS;  // input file stream
    ofstream outFS; // Output file stream
    int column = 0; 
    int row = 0;
    int num = 0;
    double sumAll = 0;
    int arrOne[30][5] = {0}; //data value for storing from a file // four numbers in a line

    cout << "Opening file input.txt" << endl; // try to open file
    inFS.open("input.txt"); // open the file
    if(!inFS.is_open()) // make sure the file exists
    {
        cout << "Could not open file input.txt" << endl;
        return 1;
    }
    
    cout << "Reading numbers..." << endl;

// read and store numbers to the array from the file until end of file
   while(!inFS.eof())   
    {  
        inFS >> num;
        arrOne[row][column] = num;
        column++;
        if(column == 4)   // column 4 is fixed // four numbers in a line
        { 
            row++;
            column = 0;
        }
    }

    cout << "Closing file input.txt" << endl;
    inFS.close();   // close the file
 
//    cout << "row = " << row << endl;  // checking value of row
    
    // add up each row (line)
    for(int a=0; a<row; a++){
        for(int b=0; b<4; b++){
          
            arrOne[a][4] += arrOne[a][b];   // add up one row
        }
    }
    
    // [0][4] = [0][0] + [0][1] + [0][2] + [0][3]
    // [1][4] = [1][0] + [1][1] + [1][2] + [1][3] 

    // add up each column //  the sum stored to arr[row][0], arr[row][1]...
    for(int a=0; a<4; a++){
        for(int b=0; b<row; b++){
            arrOne[row][a] += arrOne[b][a]; // [3][0] = [0][0]+[1][0]+[2][0]
        }
    }

    // get average all numbers
    for(int a=0; a < row; a++)
        sumAll += arrOne[a][4];
    cout.precision(2);
    cout << endl << "Average all numbers: " << fixed << sumAll/(row*4) << endl;  // average

    // open file //writing to a file
    outFS.open("output.txt");
    if(!outFS.is_open())
    {
        cout << "Could not open file input.txt" << endl;
        return 1;
    }
    
    //wrtie to file + make the output nice(aligning)
    for(int i=0; i<row+1; i++){
        for(int j=0; j<5; j++){
            outFS << setw(5) << right << arrOne[i][j]; // Changes back to right alignment
        } outFS << endl;
    } 
    
  
    outFS.close();  // close file
    
    return 0;
}