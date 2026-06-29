#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"
#include "RecipientManager.h"

class AddressBook
{
    UserManager userManager;
    RecipientManager *recipientManager;
    const string FILE_NAME_WITH_RECIPIENTS;

public:
    AddressBook(string fileNameWithUsers, string fileNameWithRecipients)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_RECIPIENTS(fileNameWithRecipients)
    {
        recipientManager = NULL;
    }
    ~AddressBook()
    {
        delete recipientManager;
        recipientManager = NULL;
    }
    void userRegistration();
    void displayAllUsers();
    void userLogin();
    void changePasswordOfLoggedInUser();
    void userLogout();
    void addRecipient();
    void displayAllRecipients();
    void loadRecipientsFromFile();
    bool isUserLoggedIn();
    void searchRecipientsByFirstName();
    void searchRecipientsByLastName();
    void editRecipient();
    int removeRecipient();
};

#endif