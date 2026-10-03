

#include <string>
using namespace std;

class Flight {
private:
    string flightNumber;
    string airline;
    string source;
    string destination;
    string date;
    string departureTime;
    string arrivalTime;
    double price;

public:
    Flight(string flightNumber,
           string airline,
           string source,
           string destination,
           string date,
           string departureTime,
           string arrivalTime,
           double price);

    string getFlightNumber();
    string getAirline();
    string getSource();
    string getDestination();
    string getDate();
    string getDepartureTime();
    string getArrivalTime();
    double getPrice();
};


