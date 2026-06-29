#ifndef FILEWITHRECIPIENTS_H
#define FILEWITHRECIPIENTS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "HelperMethods.h"
#include "Recipient.h"
#include "TextFile.h"

class FileWithRecipients : public TextFile
{
    string FILE_NAME_WITH_RECIPIENTS;
    int idOfLastRecipient;
    string convertRecipientDataToLineWithDataSeparatedByVerticalDashes(Recipient recipient);

public:
    FileWithRecipients(string fileNameWithRecipients);
    bool appendRecipientToFile(Recipient recipient);
    vector<Recipient> loadRecipientsOfLoggedInUserFromFile(int loggedInUserId);
    int getUserIdFromDataSeparatedByVerticalDashes(string singleRecipientDataSeparatedByVerticalDashes);
    Recipient getRecipientData(string singleRecipientDataSeparatedByVerticalDashes);
    int getRecipientIdFromDataSeparatedByVerticalDashes(string singleRecipientDataSeparatedByVerticalDashes);
    string getNumber(string text, int characterPosition);
    int loadIdOfLastRecipient();
    void loadIdOfLastRecipient(int id);
    void removeRecipientFromFile(int recipientId);
    void editRecipientInFile(Recipient recipient);
};

#endif