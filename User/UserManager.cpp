#include "UserManager.h"
#include <iostream>
#include<fstream>

using namespace std;

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif



// Helper function to capture password securely with '*' masking
string getMaskedPassword() {
    string password = "";
    char ch;

#ifdef _WIN32
    while ((ch = _getch()) != '\r') { // '\r' is Enter on Windows
        if (ch == '\b') { // Handle Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else if (ch != 0 && ch != -32) { // Ignore special/arrow keys
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
#else
    // Disable echo in Linux/macOS terminal
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch == 127 || ch == 8) { // Handle Backspace
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;

    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif

    return password;
}

bool UserManager::login() {

    string mailID;
    string password;

    cout << "\n========== LOGIN ==========\n";

    cout << "Enter email: ";
    cin >> mailID;

    cout << "Enter password: ";
    password = getMaskedPassword();

    for ( User& user : users) {

        if (user.getmail() == mailID &&
            user.getpwd() == password) {

            cout << "\nLogin successful!";
            cout << "\nWelcome, " << user.getname() << "!\n";

            return true;
        }
    }

    cout << "\nInvalid email or password!\n";

    return false;
}

void UserManager::signup() {

    string name;
    string mailID;
    string password;
    string phone;

    cout << "\n========== SIGN UP ==========\n";

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter email: ";
    cin >> mailID;

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter phone number: ";
    cin >> phone;


   
    for (User& user : users) {

        if (user.getmail() == mailID) {
            cout << "\nEmail already registered!\n";
            
            return;
        }
    }

    User newUser(name, mailID, password, phone);


    users.push_back(newUser);
    saveusers();

    cout << "\nAccount created successfully!\n";
}

void UserManager::saveusers() {

    ofstream file("data/users.csv");

    if (!file) {
        cout << "Error opening users file!\n";
        return;
    }

    for ( User& user : users) {

        file << user.getname() << ","
             << user.getmail() << ","
             << user.getpwd() << ","
             << user.getphone() << "\n";
    }

    file.close();
}
void UserManager::loadusers() {

    ifstream file("data/users.csv");

    if (!file) {
        cout << "No existing user data found.\n";
        return;
    }

    string name;
    string mailID;
    string password;
    string phone;

    while (getline(file, name, ',') &&
           getline(file, mailID, ',') &&
           getline(file, password, ',') &&
           getline(file, phone)) {

        User user(name, mailID, password, phone);

        users.push_back(user);
    }

    file.close();
}