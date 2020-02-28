//Ramiz Faragalla
//Car class

#include<string>
using namespace std;

#ifndef Car_h
#define Car_h
class Car
{
public:
	string plate;						//plate number
	int numMoves = 0;					//number of moves, arrive and depart doesn't count
	bool operator==(const Car &);		//overload==
	bool operator!=(const Car &);		//overload!=
};

//overload==
bool Car::operator==(const Car & c)
{
	return plate == c.plate;
}

//overload!=
bool Car::operator!=(const Car & c)
{
	return plate != c.plate;
}

#endif