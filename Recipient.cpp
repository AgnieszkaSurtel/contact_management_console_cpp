#include "Recipient.h"

void Recipient::setUserId(int newUserId)
{
    userId = newUserId;
}
void Recipient::setId(int newId)
{
    id = newId;
}
void Recipient::setFirstName(string newFirstName)
{
    firstName = newFirstName;
}
void Recipient::setLastName(string newLastName)
{
    lastName = newLastName;
}
void Recipient::setPhoneNumber(string newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}
void Recipient::setEmail(string newEmail)
{
    email = newEmail;
}
void Recipient::setAddress(string newAddress)
{
    address = newAddress;
}
int Recipient::loadUserId()
{
    return userId;
}
int Recipient::loadId()
{
    return id;
}
string Recipient::loadFirstName()
{
    return firstName;
}
string Recipient::loadLastName()
{
    return lastName;
}
string Recipient::loadPhoneNumber()
{
    return phoneNumber;
}
string Recipient::loadEmail()
{
    return email;
}
string Recipient::loadAddress()
{
    return address;
}