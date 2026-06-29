#include "UserManager.h"

UserManager::UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers)
{
    users = fileWithUsers.loadUsersFromFile();
    idOfLoggedUser = 0;
}

void UserManager::registerUser()
{
    User user = getNewUserData();

    users.push_back(user);
    fileWithUsers.appendUserToFile(user);

    cout << endl << "Account created successfully" << endl << endl;
    system("pause");
}

User UserManager::getNewUserData()
{
    User user;

    user.setId(getNewUserId());

    string login;
    do
    {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExisting(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExisting(string login)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login) {
            cout << endl << "User with this login already exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::printAllUsers()
{
    for(int i = 0; i < users.size(); i++)
    {
       cout << users[i].getId() << endl;
       cout << users[i].getLogin() << endl;
       cout << users[i].getPassword() << endl;
    }
}

void UserManager::logInUser()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    cin >> login;

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Enter password. Remaining attempts: " << attempts << ": ";
                cin >> password;

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    idOfLoggedUser = itr -> getId();
                    return; 
                }
            }
            cout << "Incorrect password entered 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with such login" << endl << endl;
    system("pause");
}

void UserManager::changePasswordOfLoggedUser()
{
    string newPassword = "";
    cout << "Enter new password: ";
    cin >> newPassword;

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idOfLoggedUser)
        {
            itr -> setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);
}

void UserManager::logOutUser()
{
    if (idOfLoggedUser == 0)
        cout << "Nobody is logged in" << endl;
    else {
        vector <User>::iterator itr = users.begin();
        while (itr != users.end())
        {
            if (itr -> getId() == idOfLoggedUser)
                break;
            itr++;
        }
        cout << "User: " << itr -> getLogin() << ", logged out." << endl;
        idOfLoggedUser = 0;
    }
}

int UserManager::getIdOfLoggedUser()
{
    return idOfLoggedUser;
}

bool UserManager::isUserLoggedIn()
{
    if (idOfLoggedUser > 0)
        return true;
    else {
        return false;
    }
}
