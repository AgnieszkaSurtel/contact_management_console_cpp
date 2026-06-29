#ifndef RECIPIENTMANAGER_H
#define RECIPIENTMANAGER_H

#include <vector>

#include "Recipient.h"
#include "FileWithRecipients.h"

class RecipientManager
{
    const int LOGGED_IN_USER_ID;
    vector<Recipient> recipients;
    FileWithRecipients fileWithRecipients;

public:
    RecipientManager(string fileNameWithRecipients, int loggedInUserId)
        : fileWithRecipients(fileNameWithRecipients), LOGGED_IN_USER_ID(loggedInUserId)
    {
        recipients = fileWithRecipients.loadRecipientsOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    }

    void addRecipient();
    Recipient enterNewRecipientData();
    void displayAllRecipients();
    void displayRecipientData(Recipient recipient);
    void loadRecipientsFromFile(int loggedInUserId);
    void searchRecipientsByFirstName();
    void displayNumberOfFoundRecipients(int recipientsCount);
    void searchRecipientsByLastName();
    int removeRecipient();
    int enterSelectedRecipientId();
    void editRecipient();
    char selectOptionFromEditMenu();
    void updateDataOfEditedRecipient(Recipient recipient);
};

#endif