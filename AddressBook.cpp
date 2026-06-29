#include "AddressBook.h"

void AddressBook::userRegistration()
{
    userManager.registerUser(); 
}

void AddressBook::displayAllUsers()
{
    userManager.printAllUsers(); 
}

void AddressBook::userLogin()
{
    userManager.logInUser();
    if(userManager.isUserLoggedIn())
    {
        recipientManager = new RecipientManager(FILE_NAME_WITH_RECIPIENTS, userManager.getIdOfLoggedUser());
    }
}

void AddressBook::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedUser();
}

void AddressBook::userLogout()
{
    userManager.logOutUser(); 
    delete recipientManager;    
    recipientManager = NULL;
}

void AddressBook::addRecipient()
{
    if (userManager.isUserLoggedIn())
    {
        recipientManager->addRecipient();
    }
    else
    {
        cout << "To add a recipient, you must first log in" << endl;
        system("pause");
    }
}

void AddressBook::displayAllRecipients()
{
    if (userManager.isUserLoggedIn())
    {
        recipientManager->displayAllRecipients();
    }
}

void AddressBook::loadRecipientsFromFile()
{
    recipientManager->loadRecipientsFromFile(userManager.getIdOfLoggedUser());
}

bool AddressBook::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void AddressBook::searchRecipientsByFirstName()
{
    recipientManager->searchRecipientsByFirstName();
}

void AddressBook::searchRecipientsByLastName()
{
    recipientManager->searchRecipientsByLastName();
}

int AddressBook::removeRecipient()
{
    return recipientManager->removeRecipient();
}

void AddressBook::editRecipient()
{
    recipientManager->editRecipient();
}