# Garage-Simulation

This project simulates a two lane garage using an array based implementation of a stack.

Three stacks were used in creating this simulation. Two for each lane of the garage, and a
third one to represent the street.
Each lane can take up to 10 cars. There is only a single enterance/exit to each lane.

If a customer arrives to pick up a car which is not nearest the exit, all cars blocking the cars' path are moved into the other lane. 
If more cars still must be moved out of the way, they go into the street. When the customer's car is driven out, all cars in the street 
must be put back into the garage.

The input is taken from a file. Each line in the file contains two fields separated by a blank: a code (A = an arriving car, or 
D= a car wishes to depart) and a license plate number, which is a String. Cars are assumed to arrive and depart in the order specified 
by the input. The program prints a message whenever a car arrives or departs.

When a car arrives, the message specifies whether or not there is room in the garage for the car. If there is no room, the car leaves 
without entering. When a car departs, the message includes the number of times the car had to be moved out of the way so that other cars 
could depart. Each move from one lane to the other counts as 1; each move to the street counts as 1; each move from the street to a lane 
counts as 1. The program also checks for these conditions: if someone is wanting for a car that's not in the garage, if someone is trying to park a car but both lanes are full, if someone is trying to park a car when only one lane is full, etc.

In this program, I created a 'garage' class to represent the 2 lanes and the street. The garage class will contain three stack objects 
one for each lane and the street. The array-based implementation of the stack is used. Methods were made for manipulating the cars 
in the lanes, e.g. search for a car in a lane, move a car from a lane to somewhere, and higher-level methods like arrive and depart and 
methods to handle the output. 
A class, named Car, was also created that contains the license plate and a counter for the number of moves the car makes.
