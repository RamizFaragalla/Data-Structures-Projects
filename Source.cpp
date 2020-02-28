//Ramiz Faragalla
//Lab3

#include<iostream>
#include<fstream>
#include "Garage.h"
using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("Data.txt");

	//creating a garage object
	Garage myGarage;					

	char c;
	string num;

	//read entire input file
	inFile >> c >> num;
	while (!inFile.eof())
	{
		//if arriving, add car
		if (c == 'A')
			myGarage.arrive(num);

		//if departing, remove car
		else if (c == 'D')
			myGarage.depart(num);

		//read next input
		inFile >> c >> num;
	}

	//closing input file
	inFile.close();

	system("PAUSE");
	return 0;
}

/*
output_iteratorThere is room! Car with license plate #: ABC123 has arrived.

There is room! Car with license plate #: ABC456 has arrived.

There is room! Car with license plate #: ABC789 has arrived.

There is room! Car with license plate #: DEF123 has arrived.

There is room! Car with license plate #: DEF456 has arrived.

There is room! Car with license plate #: DEF789 has arrived.

There is room! Car with license plate #: GHI123 has arrived.

There is room! Car with license plate #: GHI456 has arrived.

There is room! Car with license plate #: GHI789 has arrived.

There is room! Car with license plate #: JKL123 has arrived.

There is room! Car with license plate #: JKL456 has arrived.

There is room! Car with license plate #: JKL789 has arrived.

There is room! Car with license plate #: MNO123 has arrived.

There is room! Car with license plate #: MNO456 has arrived.

There is room! Car with license plate #: MNO789 has arrived.

There is room! Car with license plate #: PQR123 has arrived.

There is room! Car with license plate #: PQR456 has arrived.

There is room! Car with license plate #: PQR789 has arrived.

There is room! Car with license plate #: STU123 has arrived.

There is room! Car with license plate #: STU456 has arrived.

There is no room.

Car with license plate number: ABC123 has departed. It was moved 0 time(s)!

Car with license plate number: ABC456 has departed. It was moved 2 time(s)!

Car with license plate number: ABC789 has departed. It was moved 4 time(s)!

Car with license plate number: DEF123 has departed. It was moved 6 time(s)!

Car with license plate number: DEF456 has departed. It was moved 8 time(s)!

Car with license plate number: DEF789 has departed. It was moved 10 time(s)!

Car with license plate number: GHI123 has departed. It was moved 12 time(s)!

Car with license plate number: GHI456 has departed. It was moved 14 time(s)!

Car with license plate number: GHI789 has departed. It was moved 16 time(s)!

Car with license plate number: JKL123 has departed. It was moved 18 time(s)!

Car with license plate number: JKL456 has departed. It was moved 0 time(s)!

Car with license plate number: JKL789 has departed. It was moved 1 time(s)!

Car with license plate number: MNO123 has departed. It was moved 1 time(s)!

Car with license plate number: MNO456 has departed. It was moved 1 time(s)!

Car with license plate number: MNO789 has departed. It was moved 1 time(s)!

Car with license plate number: PQR123 has departed. It was moved 1 time(s)!

Car with license plate number: PQR456 has departed. It was moved 1 time(s)!

Car with license plate number: PQR789 has departed. It was moved 1 time(s)!

Car with license plate number: STU123 has departed. It was moved 1 time(s)!

Car with license plate number: STU456 has departed. It was moved 1 time(s)!

Your car is not parked here!

Press any key to continue . . .

*/