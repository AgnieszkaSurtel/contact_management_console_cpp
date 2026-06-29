#ifndef RECIPIENT_H
#define RECIPIENT_H

#include <string>
#include <iostream>

using namespace std;

class Recipient
{
    int id;
    int userId;
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    string address;

public:
    Recipient(int id=0, int userId=0, string firstName="", string lastName="", string phoneNumber="", string email="", string address="")
    {
        this->id = id;
        this->userId = userId;
        this->firstName = firstName;
        this->lastName = lastName;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->address = address;
    }

    void setUserId(int newUserId);
    void setId(int newId);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setPhoneNumber(string newPhoneNumber);
    void setEmail(string newEmail);
    void setAddress(string newAddress);

    int loadUserId();
    int loadId();
    string loadFirstName();
    string loadLastName();
    string loadPhoneNumber();
    string loadEmail();
    string loadAddress();
};

#endif