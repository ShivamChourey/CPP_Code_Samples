#pragma once
# ifndef ELEVATORSCHEDULING
# define ELEVATORSCHEDULING

# include <vector>
# include <algorithm>

# include "Passenger.h"

using namespace std;

// Indicator for elevator status
enum class ElevatorStatus
{
	WAITING,
	MOVING,
	PICKORDROP
};

// The class Elevator
class Elevator
{

private:

	// Member indicating current status of elevator
	ElevatorStatus m_status;

	// Current direction of motion
	bool m_upDirection;

	// Current floor
	int m_currentFloor;

	// List of passenger Indices. This maps to list of passengers in main function
	vector<int> m_passengerIndexList;

	// List of pickup floors
	vector<int> m_pickupFloors;

	// List of destination floors
	vector<int> m_destinationFloors;

	// Number of passengers in the elevator
	int m_passangers;

public:

	// Counter indicating time elapsed in an activity 
    // 1. Board
    // 2. Drop
    // 3. Moving between floors
	int m_activityCounter;

	// Constructor for the elevator class
	Elevator() : m_status(ElevatorStatus::WAITING), m_upDirection(true), m_currentFloor(1), m_passangers(0), m_activityCounter(0)
	{ 
		m_pickupFloors.clear();
		m_destinationFloors.clear();
		m_passengerIndexList.clear();
	}

	// Add the index of passenger to the passenger index list of elevator
	void AddPassengerIndex(int index) { m_passengerIndexList.push_back(index); }
	// Return the passenger index list of elevator
	const vector<int> GetPassengerIndexList(void) { return m_passengerIndexList; }
	// Remove an index from passenger index list of elevator
	void RemovePassengerFromIndexList(int index);

	// Function to increment number of passengers
	void IncrementPassenger(void) {	++m_passangers; }
	// Function to decrement number of passengers
	void DecrementPassenger(void) {	--m_passangers;	}
	// Get number of passengers
	int GetPassengerCount(void) { return m_passangers; }

	// Get the elevator direction
	bool GetDirection(void) { return m_upDirection; }
	// Change the elevator direction
	void ChangeDirection(void) { m_upDirection = m_upDirection ? false : true; }

	// Return the current status of elevator
	ElevatorStatus GetStatus(void) { return m_status; }
	// Set the status of elevator
	void SetStatus(ElevatorStatus status) { m_status = status; }

	// Function ot return current floor of the elevator
	int GetCurrentFloor(void) { return m_currentFloor; }
	// Function to increment current floor
	void IncrementCurrentFloor(void) { ++m_currentFloor; }
	// Function to decrement current floor
	void DecrementCurrentFloor(void) { --m_currentFloor; }

	// Returns list of destination floors
	const vector<int> GetDestinations(void) { return m_destinationFloors; }
	// Returns list of pickup floors
	const vector<int> GetPickups(void) { return m_pickupFloors; }

	// Adds a pickup floor
	void AddPickup(int floor) { m_pickupFloors.push_back(floor); }
	// Adds a destination floor
	void AddDestination(int floor) { m_destinationFloors.push_back(floor); }

	// Board and drop passengers of current floor
    // Also handles the current passenger count
	void BoardAndDropPassengers(void);

	// Function to print Elevator information
	void PrintElevatorInformation(void);
};

# endif
