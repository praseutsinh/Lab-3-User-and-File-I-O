#include <iostream>
#include <cmath>
#include <fstream>
#include <array>

class stats {
public:
	// Function to calculate the mean of a set of four numbers
	double calculateMean(double set[]) {
		double sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += set[i];
		}
		return sum / 4;
	}

	// Function to calculate the standard deviation of a set of four numbers
	double standardDeviation(double set[]) {
		const double mean = calculateMean(set);
		double variance = 0;
		for (int x = 0; x < 4; x++) {
			double diff = set[x] - mean;
			variance += diff * diff;
		}
		return  std::sqrt(variance/4);
	}
};

int main() {
	stats calculate;
	const int SIZE = 4;

	//----------USER INPUT SECTION----------//
	double userSet[SIZE] = {};
	std::cout << "Enter a set of four integers: " << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cout << i + 1 << ") ";
		std::cin >> userSet[i];
	}

	std::cout << "User Mean: " << calculate.calculateMean(userSet) << std::endl;
	std::cout << "User Standard Deviation: " << calculate.standardDeviation(userSet) << std::endl;

	//----------FILE INPUT SECTION----------//
	std::ifstream inputFile("inMeanStd.dat");
	std::ofstream outputFile("outMeanStd.dat");
	double fileSet[SIZE] = {};

	if (!inputFile) {
		std::cerr << "\nError opening file." << std::endl;
	}
	else {
		for (int i = 0; i < SIZE; i++) {
			inputFile >> fileSet[i];
		}
		outputFile << "File Mean: " << calculate.calculateMean(fileSet) << std::endl;
		std::cout << "\nFile Mean: " << calculate.calculateMean(fileSet) << std::endl;

		outputFile << "File Standard Deviation: " << calculate.standardDeviation(fileSet) << std::endl;
		std::cout << "File Standard Deviation: " << calculate.standardDeviation(fileSet) << std::endl;
	}

	outputFile.close();
	inputFile.close();

	return 0;
}