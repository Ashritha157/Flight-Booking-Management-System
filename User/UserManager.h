#include "User.h"
#include<iostream>
#include<vector>
using namespace std;
class UserManager{
    private:
        vector<User> users;
    public:
        void signup();
        bool login();
        
        void saveusers();
        void loadusers();
};