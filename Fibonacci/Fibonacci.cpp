// <Shivam Chourey>
// Following source file contains the code to generate the Fibonacci number for an input position using memoization. 
// The memoization process is carried out by maintaining a vector of the numbers of the series generated so far.
// This speeds up the generation by avoiding duplication and using values from memory directly.

#include <iostream>
#include "include/FibonacciHead.h"

using namespace std;


// Function to generate the Fibonacci number for specified position
long FibonacciSeries::getNumber(int position)
{
    if (this->m_series.find(position) != this->m_series.end())
    {
        return this->m_series[position];
    }
    else
    {
        // Get the number through recursion
        long number = this->getNumber(position-1) + this->getNumber(position-2);

        // update the series
        this->m_series[position] = number;
        return number;
    }
}

// Function to print the Fibonacci series till the input position
void FibonacciSeries::printSeries(int fibPos)
{
    cout << "\n The Fibonacci series is as follows: \n";

    for (int index = 1; index <= fibPos; index++)
    {
        cout << this->m_series[index] << " ";
    }

    cout << "\n End of Series ";
}

// Main function
int main()
{
    int fibPos = 0;
    long fibNumber = 0;
    
    cout << " Fibonacci term generation \n Enter the position of Fibonacci number you'd like to see:  ";
    cin >> fibPos;

    // If the input is invalid allow user another chance
    if (fibPos < 1)
    {
        cout << " Incorrect input. Please input a valid position number [> 0] : ";
        cin >> fibPos;
    }

    // Exit if the input is still invalid
    if (fibPos < 1)
    {
        cout << "\n Incorrect position entered again. Exiting. \n";
    }

    // Decalre the class object
    FibonacciSeries FibSeriesObject;
    
    // Get the number and print it
    fibNumber = FibSeriesObject.getNumber(fibPos);
    cout << "\n The Fibonnaci number at position " << fibPos << " is : " << fibNumber;

    // Print the series till that number
    FibSeriesObject.printSeries(fibPos);

    return 0;
}
