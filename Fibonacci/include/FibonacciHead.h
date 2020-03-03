// <Shivam Chourey> 
// Header file containing the class definition for FibonacciSeries class

#pragma once
#ifndef FIBHEAD
#define FIBHEAD

# include <map>

using namespace std;

class FibonacciSeries
{
	// Private member
	map <int, long> m_series;

public:

	// Initialize the first two numbers of series in constructor
	FibonacciSeries()
	{
		this->m_series[1] = 0;
		this->m_series[2] = 1;
	}

	// Function to get the Fibonacci number at input position
	long getNumber(int position);

	//  Function to print the Fibonacci series till the input position
	void printSeries(int position);
};


#endif
