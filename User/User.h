#include<iostream>
using namespace std;
class User
{
    private:

        string name;
        string mailID;
        string password;
        string phone;
    public:
        User(string name,string mailID,string password,string phone);
        string getname();
        string getmail();
        string getpwd();
        string getphone();

};