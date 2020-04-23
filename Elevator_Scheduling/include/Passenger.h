#pragma once
# ifndef PASSENGER
# define PASSENGER

class Passenger
{
	// The total time needed for passenger from waiting to 
	// getting to their destination
	int totalTime;

public:

	// Start time - Non-modifiable
	const int m_startTime;
	// Start floor - Non-modifiable
	const int m_startFloor;
	// Destination floor - Non-modifiable
	const int m_destinationFloor;

	// Constructor
	Passenger(int time, int start, int end) :m_startTime(time), m_startFloor(start), m_destinationFloor(end), totalTime(time) {}

	// Using the end time for passenger calculates the total time
	void SetEndTime(int time) { totalTime = time - m_startTime; }

	// Returns the total time
	int GetTotalTime(void) { return totalTime; }
};

#endif
