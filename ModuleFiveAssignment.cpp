#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Open the input file for reading (ifstream = input file stream)
    ifstream inFS("FahrenheitTemperature.txt");

    if (!inFS.is_open()) {
        cout << "Could not open FahrenheitTemperature.txt" << endl;
        return 1;
    }

    // Open the output file for writing (ofstream = output file stream)
    ofstream outFS("CelsiusTemperature.txt");

    if (!outFS.is_open()) {
        cout << "Could not create CelsiusTemperature.txt" << endl;
        inFS.close();
        return 1;
    }

    string city;
    int fahrenheit;

    // Read city name, then temperature, until there is no more data
    while (inFS >> city >> fahrenheit) {
        // Convert using (F - 32) * 5 / 9
        double celsius = (fahrenheit - 32) * 5.0 / 9.0;

        // Write city and Celsius temperature, separated by a space
        outFS << city << " " << celsius << endl;
    }

    // Close both files
    inFS.close();
    outFS.close();

    return 0;
}
