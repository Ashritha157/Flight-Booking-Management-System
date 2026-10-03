

#include <vector>
#include <string>
#include "Flight.h"

using namespace std;

class FlightManager {
private:
    vector<Flight> flights;

public:
    void loadFlights();
    void searchFlights(string source, string destination, string date);
};

