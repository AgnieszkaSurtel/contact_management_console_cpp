#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

#include "User.h"
#include "FileWithUsers.h"

class UserManager
{
    int idOfLoggedUser;
    vector<User> users;
    FileWithUsers fileWithUsers;

    User getNewUserData();
    int getNewUserId();
    bool isLoginExisting(string login);

public:
    UserManager(string fileNameWithUsers);

    void registerUser();
    void printAllUsers();
    void logInUser();
    void changePasswordOfLoggedUser();
    void logOutUser();
    int getIdOfLoggedUser();
    bool isUserLoggedIn();
};

#endif