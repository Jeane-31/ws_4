namespace sdds
{
    class ConfirmationSender
    {
        // member variables
        Reservation **reservations;
        size_t num_res;

    public:
        // constructor
        ConfirmationSender();

        // copy constructor
        ConfirmationSender(const ConfirmationSender &cs);

        // copy assignment operator
        ConfirmationSender &operator=(const ConfirmationSender &cs);

        // move constructor
        ConfirmationSender(ConfirmationSender &&cs);

        // move assignment operator
        ConfirmationSender &operator=(ConfirmationSender &&cs);

        // destructor
        ~ConfirmationSender();

        // member functions
        ConfirmationSender &operator+=(const Reservation &res);
        ConfirmationSender &operator-=(const Reservation &res);
        friend std::ostream &operator<<(std::ostream &os, const ConfirmationSender &cs);
    };
}