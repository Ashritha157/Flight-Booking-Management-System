
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

Flight* FlightManager::searchFlights(string source,
                                     string destination,
                                     string date) {

    int count = 0;

    cout << "\nAvailable Flights\n";
    cout << "============================================================\n";

    // Display all matching flights
    for (Flight& flight : flights) {

        if (flight.getSource() == source &&
            flight.getDestination() == destination &&
            flight.getDate() == date) {

            count++;

            cout << count << ". "
                 << flight.getFlightNumber()
                 << " | " << flight.getAirline()
                 << " | " << flight.getDepartureTime()
                 << " - " << flight.getArrivalTime()
                 << " | Rs. " << flight.getPrice()
                 << endl;
        }
    }

    // No flights found
    if (count == 0) {
        cout << "No flights available.\n";
        return nullptr;
    }

    cout << "============================================================\n";

    int choice;

    cout << "\nChoose a flight (1-" << count << "): ";
    cin >> choice;

    // Check whether choice is valid
    if (choice < 1 || choice > count) {
        cout << "Invalid flight choice.\n";
        return nullptr;
    }

    // Find the selected flight
    count = 0;

    for (Flight& flight : flights) {

        if (flight.getSource() == source &&
            flight.getDestination() == destination &&
            flight.getDate() == date) {

            count++;

            if (count == choice) {
                return &flight;
            }
        }
    }

    return nullptr;
}