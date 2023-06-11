#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <ostream>

namespace sdds
{
    class Reservation
    {
        // member variables
        std::string res_id;
        std::string res_name;
        std::string email;
        size_t num_people;
        size_t day;
        size_t hour;

    public:
        // constructor
        Reservation(const std::string &res);

        // member functions
        void update(size_t day, size_t hour);
        friend std::ostream &operator<<(std::ostream &os, const Reservation &res);
    };

}
#endif