#include "Flight.h"

Flight::Flight(string flightNumber,
               string airline,
               string source,
               string destination,
               string date,
               string departureTime,
               string arrivalTime,
               double price) {

    this->flightNumber = flightNumber;
    this->airline = airline;
    this->source = source;
    this->destination = destination;
    this->date = date;
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
    this->price = price;
}

string Flight::getFlightNumber() {
    return flightNumber;
}

string Flight::getAirline() {
    return airline;
}

string Flight::getSource() {
    return source;
}

string Flight::getDestination() {
    return destination;
}

string Flight::getDate() {
    return date;
}

string Flight::getDepartureTime() {
    return departureTime;
}

string Flight::getArrivalTime() {
    return arrivalTime;
}

double Flight::getPrice() {
    return price;
}