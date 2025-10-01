#include <iostream>
#include <cmath>
#include <fstream>

// Function to calculate the mean of a set of four numbers
float calculateMean(float set[]) {
	float mean = 0;
	for( int i = 0; i < 4; i++) {
		//sums the numbers
		mean += set[i];
	}
	//divides the sum by 4 to get the mean
	return mean/4;
}

// Function to calculate the standard deviation of a set of four numbers
float standardDeviation(float set[]) {
	// Calculate the mean
	float mean = calculateMean(set);
	//Population size or array size
	int n = 4;
	//instantiate variance variable
	float variance = 0;
	// Calculate the variance
	for(int x = 0; x < n; x++){
		float diff = set[x] - mean;
		float sqrDiff = diff * diff;
		variance = (variance + sqrDiff);
	}
	//Divide by population size to get variance
	variance = variance / n;
	// Return the standard deviation
	return  std::sqrt(variance);
}

int main() {

	//----------USER INPUT SECTION----------//
	
	//Array to hold the set of four numbers
	float set[4] = {};
	std::cout << "Enter a set of four integers: " << std::endl;
	// Input the set of four numbers through a loop
	for (int i = 0; i < 4; i++) {
		std::cout << i + 1 << ") ";
		std::cin >> set[i];
	}
	// Output the mean and standard deviation
	std::cout << "User Mean: " << calculateMean(set) << std::endl;
	std::cout << "User Standard Deviation: " << standardDeviation(set) << std::endl;

	//----------FILE INPUT SECTION----------//
	std::ifstream inputFile("inMeanStd.dat");
	std::ofstream outputFile("outMeanStd.dat");


	float fileSet[4] = {};
	// Check if the file opened successfully
	if (!inputFile) {
		std::cerr << "\nError opening file." << std::endl;

	}
	else {
		//If the file opened successfully, read the numbers into the array
		for (int i = 0; i < 4; i++) {
			inputFile >> fileSet[i];
		}
		outputFile << "File Mean: " << calculateMean(fileSet) << std::endl;
		std::cout << "\nFile Mean: " << calculateMean(fileSet) << std::endl;

		outputFile << "File Standard Deviation: " << standardDeviation(fileSet) << std::endl;
		std::cout << "File Standard Deviation: " << standardDeviation(fileSet) << std::endl;
	}
	outputFile.close();
	inputFile.close();
}