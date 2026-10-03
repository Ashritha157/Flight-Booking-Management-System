
#include "FlightManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

void FlightManager::loadFlights() {

    flights.push_back(
        Flight("AI101", "Air India",
               "Delhi", "Mumbai",
               "2026-10-10",
               "08:30", "10:45",
               5500)
    );

    flights.push_back(
        Flight("6E202", "IndiGo",
               "Delhi", "Mumbai",
               "2026-10-10",
               "12:15", "14:20",
               4800)
    );

    flights.push_back(
        Flight("AI303", "Air India",
               "Delhi", "Mumbai",
               "2026-10-11",
               "09:00", "11:15",
               5200)
    );

    flights.push_back(
        Flight("UK404", "Vistara",
               "Delhi", "Bangalore",
               "2026-10-10",
               "15:30", "18:15",
               6200)
    );
}

void FlightManager::searchFlights(string source,
                                   string destination,
                                   string date) {

    bool found = false;

    cout << "\nAvailable Flights\n";
    cout << "============================================================\n";

    for (Flight& flight : flights) {

        if (flight.getSource() == source &&
            flight.getDestination() == destination &&
            flight.getDate() == date) {

            found = true;

            cout << "Flight Number : " << flight.getFlightNumber() << endl;
            cout << "Airline       : " << flight.getAirline() << endl;
            cout << "From          : " << flight.getSource() << endl;
            cout << "To            : " << flight.getDestination() << endl;
            cout << "Date          : " << flight.getDate() << endl;
            cout << "Departure     : " << flight.getDepartureTime() << endl;
            cout << "Arrival       : " << flight.getArrivalTime() << endl;
            cout << "Price         : Rs. " << flight.getPrice() << endl;

            cout << "============================================================\n";
        }
    }

    if (!found) {
        cout << "\nNo flights available for the given route and date.\n";
    }
}