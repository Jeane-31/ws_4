// Reservation.cpp
#include "Reservation.h"
#include <string>
#include <iostream>
#include <fstream> // Include the necessary header for file operations
#include <sstream>
#include <vector>
#include <iomanip>

namespace sdds
{
    Reservation::Reservation(const std::string &res)
    {
        std::istringstream iss(res);
        std::string temp;

        // Parse the ID
        std::getline(iss, temp, ',');
        res_id = temp;

        // Parse the name
        std::getline(iss, temp, ',');
        res_name = temp;

        // Parse the email
        std::getline(iss, temp, ',');
        email = temp;

        // Parse the number of people
        std::getline(iss, temp, ',');
        try
        {
            num_people = std::stoi(temp);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid number of people: " << temp << std::endl;
            num_people = 0; // Set a default value or handle the error accordingly
        }

        // Parse the day
        std::getline(iss, temp, ',');
        try
        {
            day = std::stoi(temp);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid day: " << temp << std::endl;
            day = 0; // Set a default value or handle the error accordingly
        }

        // Parse the hour
        std::getline(iss, temp, ',');
        try
        {
            hour = std::stoi(temp);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid hour: " << temp << std::endl;
            hour = 0; // Set a default value or handle the error accordingly
        }
    }

    void Reservation::update(size_t day, size_t hour)
    {
        // Update the day and hour of the reservation
        this->day = day;
        this->hour = hour;
    }

    std::ostream &operator<<(std::ostream &os, const Reservation &res)
    {
        if (res.res_id.empty()) // Check if the reservation is valid
            return os;

        os << "Reservation ";
        os << std::setw(15) << std::left << res.res_id;
        os << ": " << std::setw(20) << std::right << res.res_name;
        os << " <" << res.email << "> ";
        os << res.res_type << " on day " << res.day << " @ ";
        os << std::setw(2) << std::setfill('0') << res.hour << ":00 for ";
        os << std::setw(2) << std::setfill(' ') << res.num_people << " people.";
        return os;
    }

}