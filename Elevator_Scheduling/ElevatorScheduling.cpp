// ElevatorScheduling.cpp
// <Shivam Chourey>
// This file contains the implementation of the elevator scheduling
// It makes use of Elevator and Passenger classes declared in the incuded headers

#include <iostream>

#include "include/Passenger.h"
#include "include/ElevatorScheduling.h"

// Debug flag
#define DEBUG true

// Remove a passenger index from passenger index list
void Elevator::RemovePassengerFromIndexList(int index)
{
    vector<int>::iterator itr = find(this->m_passengerIndexList.begin(), this->m_passengerIndexList.end(), index);
    if (itr != this->m_passengerIndexList.end())
    {
        this->m_passengerIndexList.erase(itr);
    }
}

// Board and drop passengers of the current floor
void Elevator::BoardAndDropPassengers(void)
{
    vector<int>::iterator itr;

    // Board all the passengers
    itr = find(this->m_pickupFloors.begin(), this->m_pickupFloors.end(), this->m_currentFloor);
    while (itr != this->m_pickupFloors.end())
    {
        this->m_pickupFloors.erase(itr);
        this->m_passangers++;

        itr = find(this->m_pickupFloors.begin(), this->m_pickupFloors.end(), this->m_currentFloor);
    }

    // Drop all the passengers
    itr = find(this->m_destinationFloors.begin(), this->m_destinationFloors.end(), this->m_currentFloor);
    while (itr != this->m_destinationFloors.end())
    {
        this->m_destinationFloors.erase(itr);
        this->m_passangers--;

        itr = find(this->m_destinationFloors.begin(), this->m_destinationFloors.end(), this->m_currentFloor);
    }
}

// Function to print information of Elevator object
void Elevator::PrintElevatorInformation(void)
{
    string Status;
    if (this->m_status == ElevatorStatus::MOVING)
    {
        Status = "Moving";
    }
    else if (this->m_status == ElevatorStatus::PICKORDROP)
    {
        Status = "Picking/Dropping passenger";
    }
    else
    {
        Status = "Waiting";
    }

    cout << endl << "Elevator Status   :" << Status << endl;
    cout << "Number of Passengers :" << this->m_passangers << endl;
    cout << "Current Floor     :" << this->m_currentFloor << endl;
    cout << "Destination Floors:" << endl;

    for (int index = 0; index < this->m_destinationFloors.size(); ++index)
    {
        cout << this->m_destinationFloors[index] << " ";
    }
    cout << endl;
}

// Local Functions
// Print a command line 
void PrintSeperatorLine(void)
{
    cout << endl;
    for (int index = 0; index < 60; index++)
    {
        cout << "-";
    }
    cout << endl;
}

// Assign passengers the appropriate elevator
int  AssignElevatorsToPassengers(vector<Elevator> &ElevatorList, int MaxFloor, int ElevatorCapacity,
                                 vector<Passenger> &PassengerInput, int FloorTravelTime, int PickAndDropTime, int LatestPassengerIndex, int GlobalTimeCounter)
{
    for (int pIndex = LatestPassengerIndex; pIndex < PassengerInput.size(); ++pIndex)
    {
        bool PassengerUpDirection = PassengerInput[pIndex].m_destinationFloor > PassengerInput[pIndex].m_startFloor;

        // It's time starts now
        if (GlobalTimeCounter == PassengerInput[pIndex].m_startTime)
        {
            int elevatorIndex = -1;
            int bestTimeToReach = numeric_limits<int>::max();

            // Find the elevator that reaches it in shortest time from the list
            for (int eIndex = 0; eIndex < ElevatorList.size(); ++eIndex)
            {
                // If the elevator direction is same and passenger capacity is not exceeded
                if (ElevatorList[eIndex].GetPassengerCount() < ElevatorCapacity && (ElevatorList[eIndex].GetDirection() == PassengerUpDirection
                    || ElevatorList[eIndex].GetStatus() == ElevatorStatus::WAITING))
                {
                    vector<int> Destinations = ElevatorList[eIndex].GetDestinations();
                    int timeToReach = abs((PassengerInput[pIndex].m_destinationFloor - ElevatorList[eIndex].GetCurrentFloor())) * FloorTravelTime;

                    // Check direction

                    // For Up
                    if (PassengerUpDirection)
                    {
                        // calculate the time needed for elevator to get there
                        for (int lIndex = 0; lIndex < Destinations.size(); ++lIndex)
                        {
                            if (Destinations[lIndex] < PassengerInput[pIndex].m_destinationFloor)
                            {
                                timeToReach += PickAndDropTime;
                            }
                        }
                    }
                    else
                    {
                        // calculate the time needed for elevator to get there
                        for (int lIndex = 0; lIndex < Destinations.size(); ++lIndex)
                        {
                            if (Destinations[lIndex] > PassengerInput[pIndex].m_destinationFloor)
                            {
                                timeToReach += PickAndDropTime;
                            }
                        }
                    }

                    // If the time is better than previous recorded best time
                    // Update the time and best elevator
                    if (timeToReach < bestTimeToReach)
                    {
                        bestTimeToReach = timeToReach;
                        elevatorIndex = eIndex;
                    }
                }
            }

            // If an elevator index is assigned
            if (elevatorIndex >= 0 && elevatorIndex < ElevatorList.size())
            {
                // Add passenger to elevator
                ElevatorList[elevatorIndex].AddPassengerIndex(pIndex);

                // Add the pickup and drop to the elevator
                ElevatorList[elevatorIndex].AddPickup(PassengerInput[pIndex].m_startFloor);
                ElevatorList[elevatorIndex].AddDestination(PassengerInput[pIndex].m_destinationFloor);

                // Move to next passenger
                ++LatestPassengerIndex;
            }
        }
    }

    return LatestPassengerIndex;
}

// Update the Elevator data - status, passengers, floors for the current time step
int UpdateElevatorData(vector<Elevator>& ElevatorList, int MaxFloor, int ElevatorCapacity,
                        vector<Passenger>& PassengerInput, int FloorTravelTime, int PickAndDropTime, int GlobalTimeCounter, int PassengersDeboarded)
{
    // For every elevator, update their status for the current time step
    for (int uIndex = 0; uIndex < ElevatorList.size(); ++uIndex)
    {
        if (ElevatorList[uIndex].GetStatus() == ElevatorStatus::MOVING)
        {
            // Increment
            ++ElevatorList[uIndex].m_activityCounter;

            // If moved to a different floor update the current floor
            if (ElevatorList[uIndex].m_activityCounter == FloorTravelTime)
            {
                if (ElevatorList[uIndex].GetDirection())
                {
                    ElevatorList[uIndex].IncrementCurrentFloor();
                    if (ElevatorList[uIndex].GetCurrentFloor() == MaxFloor)
                    {
                        ElevatorList[uIndex].ChangeDirection();
                    }
                }
                else
                {
                    ElevatorList[uIndex].DecrementCurrentFloor();
                    if (ElevatorList[uIndex].GetCurrentFloor() == 1)
                    {
                        ElevatorList[uIndex].ChangeDirection();
                    }
                }

                // Check if current floor is among the destinations
                for (int destinationIndex = 0; destinationIndex < ElevatorList[uIndex].GetDestinations().size(); ++destinationIndex)
                {
                    if (ElevatorList[uIndex].GetCurrentFloor() == ElevatorList[uIndex].GetDestinations()[destinationIndex])
                    {
                        ElevatorList[uIndex].SetStatus(ElevatorStatus::PICKORDROP);
                        break;
                    }
                }

                // Check if current floor is among the pickup floors
                if (ElevatorList[uIndex].GetStatus() != ElevatorStatus::PICKORDROP)
                {
                    for (int pickIndex = 0; pickIndex < ElevatorList[uIndex].GetPickups().size(); ++pickIndex)
                    {
                        if (ElevatorList[uIndex].GetCurrentFloor() == ElevatorList[uIndex].GetPickups()[pickIndex])
                        {
                            ElevatorList[uIndex].SetStatus(ElevatorStatus::PICKORDROP);
                            break;
                        }
                    }
                }

                // Update the activity counter
                ElevatorList[uIndex].m_activityCounter = 0;
            }

        }
        else if (ElevatorList[uIndex].GetStatus() == ElevatorStatus::PICKORDROP)
        {
            // Increment
            ++ElevatorList[uIndex].m_activityCounter;

            if (ElevatorList[uIndex].m_activityCounter == PickAndDropTime)
            {
                ElevatorList[uIndex].m_activityCounter = 0;

                // Board and drop all the passengers of current floor
                ElevatorList[uIndex].BoardAndDropPassengers();

                // Check the passengers that deboarded
                const vector<int> PassengerIndexList = ElevatorList[uIndex].GetPassengerIndexList();
                for (int passIndex = 0; passIndex < PassengerIndexList.size(); passIndex++)
                {
                    if (PassengerInput[PassengerIndexList[passIndex]].m_destinationFloor == ElevatorList[uIndex].GetCurrentFloor())
                    {
                        PassengerInput[PassengerIndexList[passIndex]].SetEndTime(GlobalTimeCounter);
                        PassengersDeboarded++;

                        ElevatorList[uIndex].RemovePassengerFromIndexList(PassengerIndexList[passIndex]);
                    }
                }

                // If more passengers then Move again, else go to waiting
                if (ElevatorList[uIndex].GetDestinations().size() > 0 || ElevatorList[uIndex].GetPickups().size() > 0)
                {
                    ElevatorList[uIndex].SetStatus(ElevatorStatus::MOVING);
                }
                else
                {
                    ElevatorList[uIndex].SetStatus(ElevatorStatus::WAITING);
                }
            }
        }
        else /* ElevatorStatus::WAITING */
        {
            // If it's been assigned a passenger, get to moving
            if (ElevatorList[uIndex].GetPickups().size() > 0)
            {
                // Set the current direction according to the first pickup floor
                if (ElevatorList[uIndex].GetPickups()[0] == ElevatorList[uIndex].GetCurrentFloor())
                {
                    // Set the status to moving
                    ElevatorList[uIndex].SetStatus(ElevatorStatus::PICKORDROP);
                }
                else if (ElevatorList[uIndex].GetPickups()[0] - ElevatorList[uIndex].GetCurrentFloor() > 0)
                {
                    if (!ElevatorList[uIndex].GetDirection())
                    {
                        ElevatorList[uIndex].ChangeDirection();
                    }
                    // Set the status to moving
                    ElevatorList[uIndex].SetStatus(ElevatorStatus::MOVING);
                }
                else
                {
                    if (ElevatorList[uIndex].GetDirection())
                    {
                        ElevatorList[uIndex].ChangeDirection();
                    }
                    // Set the status to moving
                    ElevatorList[uIndex].SetStatus(ElevatorStatus::MOVING);
                }
            }
        }
    }

    return PassengersDeboarded;
}

// Perform the scheduling
vector<int> PeformScheduling(vector<Elevator> ElevatorList, int MaxFloor,  int ElevatorCapacity, 
                             vector<Passenger> PassengerInput, int FloorTravelTime, int PickAndDropTime)
{
    vector<int> PassengerWaitTimeList;
    bool LastPassengerDropped = false;

    int totalPassengers = PassengerInput.size();
    int PassengersDeboarded = 0;

    int GlobalTimeCounter = 0;
    int LatestPassengerIndex = 0;

    // Each loop is a time step
    while (!LastPassengerDropped)
    {
        // Passenger-Elevator Assignment
        if(LatestPassengerIndex < totalPassengers)
           LatestPassengerIndex = AssignElevatorsToPassengers(ElevatorList,MaxFloor, ElevatorCapacity, PassengerInput, FloorTravelTime, 
                                                              PickAndDropTime, LatestPassengerIndex, GlobalTimeCounter);

        // Elevator Status Update
        PassengersDeboarded = UpdateElevatorData(ElevatorList, MaxFloor, ElevatorCapacity, PassengerInput, FloorTravelTime, PickAndDropTime, 
                                                 GlobalTimeCounter, PassengersDeboarded);

        // If debugging
		if (DEBUG)
		{
			PrintSeperatorLine();

			cout << endl << "Time : " << GlobalTimeCounter << endl;
			for (int elevIndex = 0; elevIndex < ElevatorList.size(); elevIndex++)
			{
				cout << "Elevator No. " << elevIndex + 1;
				ElevatorList[elevIndex].PrintElevatorInformation();
			}

			PrintSeperatorLine();
		}// DEBUG


		// Check if all passengers are dropped
		if (PassengersDeboarded == totalPassengers)
			LastPassengerDropped = true;

        // Increment the timer
        ++GlobalTimeCounter;
    }

    // Get the time taken for each passenger and return it
    for (int pIndex = 0; pIndex < totalPassengers; pIndex++)
    {
        PassengerWaitTimeList.push_back(PassengerInput[pIndex].GetTotalTime());
    }

    return PassengerWaitTimeList;
}

// Function to print output
void PrintOutput(vector<int> timings)
{
    cout << endl << "The wait time for each passengers is as follows: " << endl;
    for (int index = 0; index < timings.size(); ++index)
    {
        cout << "Passenger No. " << index+1 << ": " << timings[index]<<endl;
    }
}

// Main execution function
int main()
{
    int numElevators = 2;           // m
    int highestFloor = 3;           // n
    int numPassengers = 2;          // l
    int elevatorCapacity = 1;       // z

    int floorTravelTime = 1;        // x
    int pickAndDropTime = 2;        // y

    // Create a list of elevator objects
    vector<Elevator> elevatorList;
    for (int index = 0; index < numElevators; index++)
    {
        elevatorList.push_back(Elevator());
    }

    // Get the passenger input
    vector<Passenger> passengerInput;

    // Test initialize
    Passenger p1(0,1,3);
    Passenger p2(2,2,3);
    Passenger p3(3,2,1);
 
    // Push the passenger objects to the list
    passengerInput.push_back(p1);
    passengerInput.push_back(p2);
    passengerInput.push_back(p3);

    // Vector to store output
    vector<int> waitTimeOut;

    // Create the scheduling and get the wait times
    waitTimeOut = PeformScheduling(elevatorList, highestFloor, elevatorCapacity, passengerInput, floorTravelTime, pickAndDropTime);

    // Print the wait times for all the passengers
    // in the required format
    PrintOutput(waitTimeOut);
}



