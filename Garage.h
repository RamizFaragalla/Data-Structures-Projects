//Ramiz Faragalla
//Lab3

#include "ArrayStack.h"
#include<string>
#include "Car.h"
using namespace std;

#ifndef Garage_h
#define Garage_h

class Garage
{
private:
	ArrayStack<Car> lane1;
	ArrayStack<Car> lane2;
	ArrayStack<Car> street;
	int carsInStreet;									//number of cars in the street

	void move(ArrayStack<Car> &, ArrayStack<Car> &);	//move from one lane to another
	bool canAdd(ArrayStack<Car> &);						//checks if stack has room
	void leavingGarage(Car &, ArrayStack<Car> &, ArrayStack<Car> &);
	void cleanUpStreet();								//returns cars to the lanes

public:
	Garage() : carsInStreet(0){};						//constructor
	void arrive(const string &);						//add a car to garage
	void depart(const string &);						//remove a car from garage
};

//add car to garage
void Garage::arrive(const string & x)
{
	Car car = { x };
	
	//adds a car to either lane1 or 2, whichever has room
	if (lane1.push(car) || lane2.push(car))
	{
		cout << "There is room! Car with license plate #: " << car.plate <<
			" has arrived.\n\n";
	}

	//if both lanes are full
	else
		cout << "There is no room.\n\n";

}

//remove a car from garage
void Garage::depart(const string & x)
{
	Car car = { x };

	//if car is in lane1, remove it
	if(lane1.search(car))
		leavingGarage(car, lane1, lane2);

	//if car is in lane2, remove it
	else if (lane2.search(car))
		leavingGarage(car, lane2, lane1);

	//if car is not parked
	else
		cout << "Your car is not parked here!\n\n";

	//return cars in street back to the lanes
	cleanUpStreet();
}

//move from lane one to two
void Garage::move(ArrayStack<Car> & one, ArrayStack<Car> & two)
{
	Car c = one.peek();
	c.numMoves++;	//update number of moves
	two.push(c);
	one.pop();
}

//checks if a car can be added to lane a
bool Garage::canAdd(ArrayStack<Car> & a)
{
	Car c;
	//if car c can be pushed, means there is room in stack
	if (a.push(c))
	{
		a.pop();
		return true;
	}

	return false;
}

//removes a car from outLane 
void Garage::leavingGarage(Car & c, ArrayStack<Car> & outLane, ArrayStack<Car> & inLane)
{
	//while the car is not on top of stack
	while (c != outLane.peek())
	{
		//if can add to other lane, move it out
		if (canAdd(inLane))
			move(outLane, inLane);

		//else move to street
		else
		{
			move(outLane, street);
			carsInStreet++;
		}
	}//car c is now on top of stack

	//output
	cout << "Car with license plate number: " << outLane.peek().plate << " has departed. " <<
		"It was moved " << outLane.peek().numMoves << " time(s)!\n\n";

	//depart car
	outLane.pop();
}

//return cars in street back to the lanes
void Garage::cleanUpStreet()
{
	//while there are cars in street
	while(carsInStreet > 0)
	{
		if (canAdd(lane1))
			move(street, lane1);
		else
			move(street, lane2);

		carsInStreet--;
	}
}

#endif