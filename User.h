#ifndef USER_H
#define USER_H
#include <iostream>
#include "string"

using namespace std;

class User
{
private:
    string name;
    string password;
public:
    string getName();
    string getPassword();
    void setName(string n);
    void setPassword(string pwd);
};



#endif // USER_H
