#include "FileWithUsers.h"

void FileWithUsers::appendUserToFile(User user)
{
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_USERS.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = convertUserDataToLineWithDataSeparatedByVerticalDashes(user);

        if (isFileEmpty(textFile) == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData;
        }
        textFile.close();
    }
    else
        cout << "Failed to open file " << FILE_NAME_WITH_USERS << " and save data in it." << endl;
}

string FileWithUsers::convertUserDataToLineWithDataSeparatedByVerticalDashes(User user)
{
    string lineWithUserData = "";
    lineWithUserData += HelperMethods::convertIntToString(user.getId()) + '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector<User> users;
    string singleUserDataSeparatedByVerticalDashes = "";
    fstream textFile;

    textFile.open(FILE_NAME_WITH_USERS.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, singleUserDataSeparatedByVerticalDashes))
        {
            user = getUserData(singleUserDataSeparatedByVerticalDashes);
            users.push_back(user);
        }
        textFile.close();
    }
    return users;
}

User FileWithUsers::getUserData(string singleUserDataSeparatedByVerticalDashes)
{
    User user;
    string singleData = "";
    int singleUserDataNumber = 1;

    for (int characterPosition = 0; characterPosition < singleUserDataSeparatedByVerticalDashes.length(); characterPosition++)
    {
        if (singleUserDataSeparatedByVerticalDashes[characterPosition] != '|')
        {
            singleData += singleUserDataSeparatedByVerticalDashes[characterPosition];
        }
        else
        {
            switch(singleUserDataNumber)
            {
            case 1:
                user.setId(atoi(singleData.c_str()));
                break;
            case 2:
                user.setLogin(singleData);
                break;
            case 3:
                user.setPassword(singleData);
                break;
            }
            singleData = "";
            singleUserDataNumber++;
        }
    }
    return user;
}

void FileWithUsers::saveAllUsersToFile(vector <User> &users)
{
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(FILE_NAME_WITH_USERS.c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
{
            lineWithUserData = convertUserDataToLineWithDataSeparatedByVerticalDashes(*itr);

            if (itr == itrEnd)
            {
               textFile << lineWithUserData;
            }
            else
            {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
        textFile.close();
    }
    else
    {
        cout << "Cannot open file " << FILE_NAME_WITH_USERS << endl;
    }
}