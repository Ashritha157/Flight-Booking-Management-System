#include "UserManager.h"
#include <iostream>

using namespace std;

bool UserManager::login() {

    string mailID;
    string password;

    cout << "\n========== LOGIN ==========\n";

    cout << "Enter email: ";
    cin >> mailID;

    cout << "Enter password: ";
    cin >> password;

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

    cout << "\nAccount created successfully!\n";
}