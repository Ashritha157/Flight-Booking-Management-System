#include<iostream>
#include "User/UserManager.h"
#include "Flight/FlightManager.h"
using namespace std;

int main(){
    UserManager manager;
    manager.loadusers();

    FlightManager flightManager;
    flightManager.loadFlights();

    string source;
    string destination;
    string date;
        int choice;
        bool loggedin=false;
        cout << "\n";
        cout << "==============================" << endl;
        cout << "    FLIGHT BOOKING SYSTEM" << endl;
        cout << "==============================" << endl;
        cout<<endl;
        cout<<"1. Sign Up"<<endl;
        cout<<"2. Log in"<<endl;
        cout<<"3. Exit Application";
        cout<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
    do{
            
        
        cout<<endl;
        switch(choice){
            case 1:
                // sign up function
                manager.signup();
                cout<<"signed up"<<endl;
            case 2:
                //log in function
                
                while(loggedin==false){
                    loggedin=manager.login();
                }

                 if(loggedin){
                        cout << "\nEnter source: ";
                        cin >> source;

                        cout << "Enter destination: ";
                        cin >> destination;

                        cout << "Enter date (YYYY-MM-DD): ";
                        cin >> date;

                        flightManager.searchFlights(source, destination, date);
                 }

                return 0;
                break;
            case 3:
                cout << "\nExiting application..." << endl;
                return 0;
            default:
                cout<<"\nChoose again! NOT a valid choice"<<endl;


        };

        if(choice>3){
          
            cout<<endl;
            cout<<"1. Sign Up"<<endl;
            cout<<"2. Log in"<<endl;
            cout<<"3. Exit Application";
            cout<<endl;
            cout<<"\nEnter your choice: ";
            cin>>choice;
        }

    }while(choice!=3 || choice>3);
    return 0;
}