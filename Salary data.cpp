// Salary data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Employee {
    string firstName;
    string lastName;
    double currentSalary;
    double payIncreasePercent;
};

int main() {
    // Open input file
    ifstream inputFile("SalaryData.txt");
    if (!inputFile) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    // Open output file
    ofstream outputFile("SalaryOut.txt");
    if (!outputFile) {
        cerr << "Error: Could not create output file." << endl;
        return 1;
    }

    // Read employee data from input file and update salary
    Employee emp;
    while (inputFile >> emp.lastName >> emp.firstName >> emp.currentSalary >> emp.payIncreasePercent) {
        // Calculate updated salary
        double payIncreaseAmount = emp.currentSalary * (emp.payIncreasePercent / 100.0);
        double updatedSalary = emp.currentSalary + payIncreaseAmount;

        // Display the updated salary data
        cout << "Name: " << emp.firstName << " " << emp.lastName << ", Updated Salary: $" << fixed << setprecision(2) << updatedSalary << endl;

        // Write updated salary data to output file
        outputFile << fixed << setprecision(2) << emp.firstName << " " << emp.lastName << " " << updatedSalary << endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    cout << "Salary data updated and written to SalaryOut.txt." << endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
