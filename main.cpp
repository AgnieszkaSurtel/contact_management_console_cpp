#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

    AddressBook addressBook("Users.txt", "Recipients.txt");
    char choice;

    while(true)
    {
        if (!addressBook.isUserLoggedIn())
        {
            choice = selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                addressBook.userRegistration();
                break;
            case '2':
                addressBook.userLogin();
                break;
            case '9':
                exit(0);
            default:
                cout << endl << "No such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else 
        {
            choice = selectOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                addressBook.addRecipient();
                break;
            case '2':
                addressBook.searchRecipientsByFirstName();
                break;
            case '3':
                addressBook.searchRecipientsByLastName();
                break;
            case '4':
                addressBook.displayAllRecipients();
                break;
            case '5':
                addressBook.removeRecipient();
                break;
            case '6':
                addressBook.editRecipient();
                break;
            case '7':
                addressBook.changePasswordOfLoggedInUser();
                break;
            case '8':
                addressBook.userLogout();
                break;
            }
        }
    }
    return 0;
}

char selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Log in" << endl;
    cout << "9. End program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelperMethods::loadChar();

    return choice;
}

char selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add recipient" << endl;
    cout << "2. Search by first name" << endl;
    cout << "3. Search by last name" << endl;
    cout << "4. Display recipients" << endl;
    cout << "5. Remove recipient" << endl;
    cout << "6. Edit recipient" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Change password" << endl;
    cout << "8. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = HelperMethods::loadChar();

    return choice;
}