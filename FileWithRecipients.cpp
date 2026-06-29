#include "FileWithRecipients.h"

FileWithRecipients::FileWithRecipients(string fileNameWithRecipients) : FILE_NAME_WITH_RECIPIENTS(fileNameWithRecipients)
{
    idOfLastRecipient = 0;
}

bool FileWithRecipients::appendRecipientToFile(Recipient recipient)
{
    string lineWithRecipientData = "";
    textFile.open(FILE_NAME_WITH_RECIPIENTS.c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithRecipientData = convertRecipientDataToLineWithDataSeparatedByVerticalDashes(recipient);

        if (isFileEmpty(textFile) == true)
        {
            textFile << lineWithRecipientData;
        }
        else
        {
            textFile << endl << lineWithRecipientData;
        }
        textFile.close();
        return true;
    }
    else
        return false;
}

string FileWithRecipients::convertRecipientDataToLineWithDataSeparatedByVerticalDashes(Recipient recipient)
{
    string lineWithRecipientData = "";

    lineWithRecipientData += HelperMethods::convertIntToString(recipient.loadId()) + '|';
    lineWithRecipientData += HelperMethods::convertIntToString(recipient.loadUserId()) + '|';
    lineWithRecipientData += recipient.loadFirstName() + '|';
    lineWithRecipientData += recipient.loadLastName() + '|';
    lineWithRecipientData += recipient.loadPhoneNumber() + '|';
    lineWithRecipientData += recipient.loadEmail() + '|';
    lineWithRecipientData += recipient.loadAddress() + '|';

    return lineWithRecipientData;
}

vector<Recipient> FileWithRecipients::loadRecipientsOfLoggedInUserFromFile(int loggedInUserId)
{
    Recipient recipient;
    vector<Recipient> recipients;
    string singleRecipientDataSeparatedByVerticalDashes = "";
    string lastRecipientDataInFile = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_RECIPIENTS.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, singleRecipientDataSeparatedByVerticalDashes))
        {
            if(loggedInUserId == getUserIdFromDataSeparatedByVerticalDashes(singleRecipientDataSeparatedByVerticalDashes))
            {
                recipient = getRecipientData(singleRecipientDataSeparatedByVerticalDashes);
                recipients.push_back(recipient);
            }
        }
        lastRecipientDataInFile = singleRecipientDataSeparatedByVerticalDashes;
        textFile.close();
    }
    else
        cout << "Failed to open the file and load the data." << endl;

    if (lastRecipientDataInFile != "")
    {
        idOfLastRecipient = getRecipientIdFromDataSeparatedByVerticalDashes(lastRecipientDataInFile);
        return recipients;
    }
    else
        return recipients;
}

int FileWithRecipients::getUserIdFromDataSeparatedByVerticalDashes(string singleRecipientDataSeparatedByVerticalDashes)
{
    int startPositionUserId = singleRecipientDataSeparatedByVerticalDashes.find_first_of('|') + 1;
    int userId = HelperMethods::convertStringToInt(getNumber(singleRecipientDataSeparatedByVerticalDashes, startPositionUserId));
    return userId;
}

Recipient FileWithRecipients::getRecipientData(string singleRecipientDataSeparatedByVerticalDashes)
{
    Recipient recipient;
    string singleData = "";
    int singleRecipientDataNumber = 1;

    for (int characterPosition = 0; characterPosition < singleRecipientDataSeparatedByVerticalDashes.length(); characterPosition++)
    {
        if (singleRecipientDataSeparatedByVerticalDashes[characterPosition] != '|')
        {
            singleData += singleRecipientDataSeparatedByVerticalDashes[characterPosition];
        }
        else
        {
            switch(singleRecipientDataNumber)
            {
            case 1:
                recipient.setId(atoi(singleData.c_str()));
                break;
            case 2:
                recipient.setUserId(atoi(singleData.c_str()));
                break;
            case 3:
                recipient.setFirstName(singleData);
                break;
            case 4:
                recipient.setLastName(singleData);
                break;
            case 5:
                recipient.setPhoneNumber(singleData);
                break;
            case 6:
                recipient.setEmail(singleData);
                break;
            case 7:
                recipient.setAddress(singleData);
                break;
            }
            singleData = "";
            singleRecipientDataNumber++;
        }
    }
    return recipient;
}

int FileWithRecipients::getRecipientIdFromDataSeparatedByVerticalDashes(string singleRecipientDataSeparatedByVerticalDashes)
{
    int startPositionRecipientId = 0;
    int recipientId = HelperMethods::convertStringToInt(getNumber(singleRecipientDataSeparatedByVerticalDashes, startPositionRecipientId));
    return recipientId;
}

string FileWithRecipients::getNumber(string text, int characterPosition)
{
    string number = "";
    while(isdigit(text[characterPosition]) == true)
    {
        number += text[characterPosition];
        characterPosition++;
    }
    return number;
}

int FileWithRecipients::loadIdOfLastRecipient()
{
    return idOfLastRecipient;
}

void FileWithRecipients::loadIdOfLastRecipient(int id)
{
    idOfLastRecipient = id;
}

void FileWithRecipients::removeRecipientFromFile(int recipientId)
{
    int lineNumberInTextFile = 1;
    int numberOfDeletedLine = 0;
    string singleRecipientDataSeparatedByVerticalDashes = "";
    fstream textFile, temporaryTextFile;
    string temporaryFileNameWithRecipients = "temp.txt";
    textFile.open(FILE_NAME_WITH_RECIPIENTS.c_str(), ios::in);
    temporaryTextFile.open(temporaryFileNameWithRecipients.c_str(), ios::out | ios::app);

    if (textFile.good() == true && recipientId != 0)
    {
        while(getline(textFile, singleRecipientDataSeparatedByVerticalDashes))
        {
            if(recipientId == getRecipientIdFromDataSeparatedByVerticalDashes(singleRecipientDataSeparatedByVerticalDashes))
            {
                temporaryTextFile << "";
                numberOfDeletedLine = lineNumberInTextFile;
            }
            else if(lineNumberInTextFile == 1)
                temporaryTextFile << singleRecipientDataSeparatedByVerticalDashes;
            else if (numberOfDeletedLine == lineNumberInTextFile && lineNumberInTextFile == 2)
                temporaryTextFile << singleRecipientDataSeparatedByVerticalDashes;
            else
                temporaryTextFile << endl << singleRecipientDataSeparatedByVerticalDashes;

            lineNumberInTextFile++;
            numberOfDeletedLine++;
        }

        textFile.close();
        temporaryTextFile.close();
        HelperMethods::deleteReadFile(FILE_NAME_WITH_RECIPIENTS);
        HelperMethods::changeTemporaryFileNameToFileName(temporaryFileNameWithRecipients, FILE_NAME_WITH_RECIPIENTS);
    }
}

void FileWithRecipients::editRecipientInFile(Recipient recipient)
{
    bool doesRecipientExist = false;
    int lineNumberInTextFile = 1;
    string singleRecipientDataSeparatedByVerticalDashes = "";
    fstream textFile, temporaryTextFile;
    string temporaryFileNameWithRecipients = "temp.txt";

    textFile.open(FILE_NAME_WITH_RECIPIENTS.c_str(), ios::in);
    temporaryTextFile.open(temporaryFileNameWithRecipients.c_str(), ios::out | ios::app);

    if (textFile.good() == true && recipient.loadId() != 0)
    {
        while(getline(textFile, singleRecipientDataSeparatedByVerticalDashes))
        {
            if(recipient.loadId() == getRecipientIdFromDataSeparatedByVerticalDashes(singleRecipientDataSeparatedByVerticalDashes) && lineNumberInTextFile == 1)
            {
                doesRecipientExist = true;
                temporaryTextFile << convertRecipientDataToLineWithDataSeparatedByVerticalDashes(recipient);
            }
            else if(recipient.loadId() == getRecipientIdFromDataSeparatedByVerticalDashes(singleRecipientDataSeparatedByVerticalDashes) && lineNumberInTextFile > 1)
            {
                doesRecipientExist = true;
                temporaryTextFile << endl << convertRecipientDataToLineWithDataSeparatedByVerticalDashes(recipient);
            }
            else if(lineNumberInTextFile == 1)
                temporaryTextFile << singleRecipientDataSeparatedByVerticalDashes;
            else if(lineNumberInTextFile > 1)
                temporaryTextFile << endl << singleRecipientDataSeparatedByVerticalDashes;

            lineNumberInTextFile++;
        }
        if (doesRecipientExist = false)
        {
            textFile.close();
        }
        textFile.close();
        temporaryTextFile.close();

        HelperMethods::deleteReadFile(FILE_NAME_WITH_RECIPIENTS);
        HelperMethods::changeTemporaryFileNameToFileName(temporaryFileNameWithRecipients, FILE_NAME_WITH_RECIPIENTS);
    }
}