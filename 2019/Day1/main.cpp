#include <iostream>
#include <fstream>

int calculatFuelFromMass(int mass)
{
	int fuel = (mass/3) -2;
	return fuel;
}

int calculateFuelCompensation(int FuelAdded) 
{
	if (FuelAdded < 9)
		return 0;
	return calculatFuelFromMass(FuelAdded) + calculateFuelCompensation(calculatFuelFromMass(FuelAdded));
}

int main() {
	//Read in values:
	std::string inputFileName = "input.txt";
	std::ifstream inputFile;
	inputFile.open("input.txt");
	int totalFuel = 0;
	int currentMass = 0;
	while( inputFile >> currentMass)
	{
		totalFuel +=  calculatFuelFromMass(currentMass) + calculateFuelCompensation(calculatFuelFromMass(currentMass));
		std::cout << totalFuel << " " << currentMass << "\n";
	}
	std::cout << "The total fuel needed is: " << totalFuel << std::endl;
	return 1;

}
