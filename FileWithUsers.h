#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "HelperMethods.h"
#include "TextFile.h"

class FileWithUsers : public TextFile
{
    const string FILE_NAME_WITH_USERS;
    string convertUserDataToLineWithDataSeparatedByVerticalDashes(User user);
    User getUserData(string singleUserDataSeparatedByVerticalDashes);

public:
    FileWithUsers(string fileNameWithUsers) : FILE_NAME_WITH_USERS(fileNameWithUsers) {}
    void appendUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif