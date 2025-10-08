/*******************************
Nikolas Praseutsinh
Computer Science Fall 2025
Due: Oct, 14, 2025
Lab 3: User and File I/O
Demo of file and user input and output
*********************************/
#include <iostream>
#include <cmath>
#include <fstream>

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

    // Function to calculate the population standard deviation of a set of four numbers
    double standardDeviation(double set[]) {
        double mean = calculateMean(set);
        double variance = 0;
        for (int i = 0; i < 4; i++) {
            double diff = set[i] - mean;
            variance += diff * diff;
        }
        return std::sqrt(variance / 4);
    }
};

int main() {
    stats calculate;
    const int SIZE = 4;
    double userSet[SIZE];
    double fileSet[SIZE];

    // ---------- USER INPUT SECTION ----------
    std::cout << "Enter four integers:\n";

    for (int i = 0; i < SIZE; i++) {
        std::cout << "Value " << (i + 1) << ": ";
        std::cin >> userSet[i];
    }

    double userMean = calculate.calculateMean(userSet);
    double userStd = calculate.standardDeviation(userSet);

    std::cout << "\nResults for User Input:\n";
    std::cout << "Mean = " << userMean << std::endl;
    std::cout << "Population Standard Deviation = " << userStd << std::endl;

    // ---------- FILE INPUT SECTION ----------
    std::ifstream inputFile("inMeanStd.dat");
    std::ofstream outputFile("outMeanStd.dat");

    if (!inputFile) {
        std::cerr << "\nError: Could not open input file 'inMeanStd.dat'.\n";
        return 1;
    }
    if (!outputFile) {
        std::cerr << "\nError: Could not open output file 'outMeanStd.dat'.\n";
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        inputFile >> fileSet[i];
    }

    double fileMean = calculate.calculateMean(fileSet);
    double fileStd = calculate.standardDeviation(fileSet);

    std::cout << "\nResults for File Input:\n";
    std::cout << "Mean = " << fileMean << std::endl;
    std::cout << "Population Standard Deviation = " << fileStd << std::endl;

    outputFile << "Results for File Input:\n";
    outputFile << "Mean = " << fileMean << std::endl;
    outputFile << "Population Standard Deviation = " << fileStd << std::endl;

    inputFile.close();
    outputFile.close();

    std::cout << "\nResults successfully written to 'outMeanStd.dat'.\n";
    return 0;
}
