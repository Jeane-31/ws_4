#include <iostream>
#include <fstream> // Include the necessary header for file operations
#include <sstream>
#include <vector>
#include "Reservation.h" // Include the Reservation header file

int main()
{
    // Open the data.txt file
    std::ifstream inFile("data.txt");

    // Check if the file was opened successfully
    if (!inFile)
    {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }

    // Create a vector to store the reservations
    std::vector<sdds::Reservation> reservations;

    // Read each line from the file
    std::string line;
    while (std::getline(inFile, line))
    {
        // Create a Reservation object and add it to the vector
        sdds::Reservation reservation(line);
        reservations.push_back(reservation);
    }

    // Close the input file stream
    inFile.close();

    // Display the reservations
    std::cout << "Reservations" << std::endl;
    std::cout << "--------------------------" << std::endl;

    // Iterate over the reservations and display their details
    for (const auto &reservation : reservations)
    {
        std::cout << reservation << std::endl;
    }

    return 0;
}
