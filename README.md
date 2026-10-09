
# Flight Booking Management System

A C++ console-based Flight Booking Management System developed using Object-Oriented Programming (OOP) concepts. The application simulates a complete flight reservation workflow, including user registration and login, flight search, flight selection, seat selection, baggage and meal options, fare calculation, payment selection, PNR generation, and boarding pass display.

---

## Project Overview

The **Flight Booking Management System** is designed to provide a simple and structured way for users to search for flights and complete a flight booking process through a command-line interface.

The system begins with **user registration and authentication**. User details are stored locally using a CSV file, allowing registered users to log in during subsequent executions.

After successful login, users can search for flights by entering:

* Source
* Destination
* Travel date

The system displays matching flights with their flight number, airline, departure time, arrival time, and ticket price. The user can then select one of the available flights.

The booking process continues with **seat selection**, where the application displays a seat map containing available and already-booked seats. Users can book one or more seats depending on the number of tickets requested.

The system also provides additional travel options such as **baggage selection and meal selection**. Extra baggage charges are calculated when the selected baggage exceeds the allowed limit, while users can choose between vegetarian and non-vegetarian meal options.

Finally, the application calculates the **total fare**, provides payment method options, confirms the payment, generates a unique **PNR number**, and displays a **boarding pass** containing the booking information.

---

## Features

### User Management

* User registration
* User login
* Email-based user identification
* Password verification
* Phone number collection
* Persistent user data using CSV files

### Flight Search

Users can search for flights based on:

* Source
* Destination
* Travel date

The system displays matching flight details including:

* Flight number
* Airline
* Source
* Destination
* Date
* Departure time
* Arrival time
* Ticket price

### Flight Selection

After searching, users can select a flight from the available matching flights.

The system validates the user's flight selection and returns the selected flight for the booking process.

### Seat Selection

The system provides an interactive console-based seat map.

Example:

```text
========== SEAT MAP ==========

[ ]A1  [X]A2  [ ]A3  [X]A4 ...
[ ]B1  [X]B2  [ ]B3  [ ]B4 ...
[X]C1  [X]C2  [X]C3  [ ]C4 ...
[ ]D1  [X]D2  [X]D3  [X]D4 ...

[ ] Available    [X] Booked
```

Users can:

* Select the number of tickets
* Choose seats individually
* Check whether a seat exists
* Check whether a seat is already booked
* Receive confirmation after successfully selecting a seat

### Baggage Selection

The system allows users to enter their baggage weight.

Each ticket provides an allowed baggage limit, and additional baggage is charged when the selected weight exceeds the allowed limit.

Current implementation:

```text
Maximum baggage allowed: 15 kg per ticket
Extra baggage charge: Rs. 500/kg
```

The system calculates the additional baggage charge automatically.

### Meal Selection

Users can optionally add meals to their booking.

Available options include:

```text
1. Veg Meal       - Rs. 250
2. Non-Veg Meal   - Rs. 350
```

Users can select the meal type and quantity. The corresponding meal charges are added to the total fare.

### Fare Calculation

The system calculates the final booking amount using:

```text
Flight Fare
+ Baggage Charges
+ Meal Charges
-----------------
= Total Fare
```

For multiple tickets, the flight fare is calculated according to the number of tickets selected.

### Payment Options

The system provides multiple payment method options:

* UPI
* Credit/Debit Card
* Net Banking

The user can select a payment method and confirm or cancel the payment.

> Note: The current payment implementation is a console simulation. It does not connect to a real payment gateway.

### PNR Generation

After successful payment, the system generates a unique PNR-style booking number.

Example:

```text
PNR Number : FB583421
```

### Boarding Pass

After successful booking, the application displays a boarding-pass-style summary containing:

* PNR number
* Airline
* Flight number
* Source
* Destination
* Travel date
* Departure time
* Arrival time
* Number of passengers
* Baggage information
* Meal selection
* Total amount paid

---


## OOP Design

The project uses classes to separate different responsibilities.

### User

Represents an individual user and stores:

* Name
* Email ID
* Password
* Phone number

### UserManager

Responsible for user-related operations:

* Sign up
* Login
* Save users
* Load users

User information is persisted in `Data/users.csv`.

### Flight

Represents an individual flight and stores:

* Flight number
* Airline
* Source
* Destination
* Date
* Departure time
* Arrival time
* Price

### FlightManager

Responsible for:

* Loading available flights
* Searching flights
* Filtering flights based on source, destination, and date
* Displaying matching flights
* Selecting a flight

### main.cpp

Acts as the main application controller and coordinates:

* User authentication
* Flight search
* Flight selection
* Seat selection
* Baggage calculation
* Meal selection
* Fare calculation
* Payment selection
* PNR generation
* Boarding pass generation

---

## Technologies Used

| Technology                  | Purpose                              |
| --------------------------- | ------------------------------------ |
| C++                         | Core programming language            |
| Object-Oriented Programming | Application design and modularity    |
| STL Vector                  | Storing users, flights and seat data |
| File Handling               | Persistent user data storage         |
| CSV                         | Local user-data storage              |
| Git                         | Version control                      |
| GitHub                      | Project hosting                      |
| G++                         | Compilation                          |

---

## OOP Concepts Demonstrated

### Encapsulation

Class data members such as user and flight information are kept private and accessed through public member functions.

### Abstraction

Complex operations such as flight searching, user login, and data persistence are organized behind class methods.

### Classes and Objects

The project uses classes such as:

```text
User
UserManager
Flight
FlightManager
```

Objects of these classes are used to perform the required operations.

### Modular Design

Different parts of the application are separated into different directories and source/header files, making the project easier to maintain and extend.

---

## Getting Started

---


## Compile the Project

The project can be compiled using:

```bash
g++ main.cpp ./User/User.cpp ./User/UserManager.cpp ./Flight/Flight.cpp ./Flight/FlightManager.cpp
```

On Windows, you can specify an executable name:

```bash
g++ main.cpp ./User/User.cpp ./User/UserManager.cpp ./Flight/Flight.cpp ./Flight/FlightManager.cpp -o FlightBookingSystem.exe
```

---

## Run the Application

### Windows

```bash
FlightBookingSystem.exe
```

### Linux / macOS

If compiled as `FlightBookingSystem`:

```bash
./FlightBookingSystem
```

---

## Data Storage

User information is stored locally in:

```text
Data/users.csv
```

The stored information follows the structure:

```text
Name,Email,Password,Phone
```

---

## Sample Flight Data

The current application contains sample flight records such as:

| Flight | Airline   | Route             | Date       | Departure | Arrival |     Price |
| ------ | --------- | ----------------- | ---------- | --------- | ------- | --------: |
| AI101  | Air India | Delhi → Mumbai    | 2026-10-10 | 08:30     | 10:45   | Rs. 5,500 |
| 6E202  | IndiGo    | Delhi → Mumbai    | 2026-10-10 | 12:15     | 14:20   | Rs. 4,800 |
| AI303  | Air India | Delhi → Mumbai    | 2026-10-11 | 09:00     | 11:15   | Rs. 5,200 |
| UK404  | Vistara   | Delhi → Bangalore | 2026-10-10 | 15:30     | 18:15   | Rs. 6,200 |

---

## Fare Calculation Example

For example, if a user selects:

```text
Flight Fare       : Rs. 4,800
Baggage Charge    : Rs.   500
Meal Charge       : Rs.   250
--------------------------------
Total Fare        : Rs. 5,550
```

The system calculates the total fare automatically based on the selected flight, number of tickets, baggage, and meals.

---



