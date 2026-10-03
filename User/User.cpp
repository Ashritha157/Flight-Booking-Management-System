#include "User.h"
User::User(string name,string mailID,string password,string phone){
    this->name=name;
    this->mailID=mailID;
    this->password=password;
    this->phone=phone;

}
string  User::getname()
{
    return name;
}
string  User::getmail()
{
    return mailID;
}
string  User::getpwd()
{
    return password;
}
string  User::getphone()
{
    return phone;
}
