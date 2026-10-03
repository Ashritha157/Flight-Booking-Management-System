#include<iostream>
using namespace std;

int main(){
        int choice;
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
                cout<<"signed up"<<endl;
            case 2:
                //log in function
                cout<<"\nNow log in!"<<endl;
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