#include "RecipientManager.h"
#include "HelperMethods.h"

void RecipientManager::addRecipient()
{
    Recipient recipient;

    system("cls");
    cout << " >>> ADDING A NEW RECIPIENT <<<" << endl << endl;
    recipient = enterNewRecipientData();

    recipients.push_back(recipient);
    if (fileWithRecipients.appendRecipientToFile(recipient))
        cout << "New recipient has been added " << endl;
    else
        cout << "Error. Failed to add the new recipient to the file." << endl;
}

Recipient RecipientManager::enterNewRecipientData()
{
    Recipient recipient;
    recipient.setId(fileWithRecipients.loadIdOfLastRecipient() + 1);
    recipient.setUserId(LOGGED_IN_USER_ID);
    fileWithRecipients.loadIdOfLastRecipient(recipient.loadId());

    cout << "Enter first name: ";
    recipient.setFirstName(HelperMethods::readLine());
    recipient.setFirstName(HelperMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(recipient.loadFirstName()));

    cout << "Enter last name: ";
    recipient.setLastName(HelperMethods::readLine());
    recipient.setLastName(HelperMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(recipient.loadLastName()));

    cout << "Enter phone number: ";
    recipient.setPhoneNumber(HelperMethods::readLine());

    cout << "Enter email: ";
    recipient.setEmail(HelperMethods::readLine());

    cout << "Enter address: ";
    recipient.setAddress(HelperMethods::readLine());

    return recipient;
}

void RecipientManager::displayAllRecipients()
{
    system("cls");
    if (!recipients.empty())
    {
        cout << "             >>> RECIPIENTS <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector<Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            displayRecipientData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "The address book is empty." << endl << endl;
    }
    system("pause");
}

void RecipientManager::displayRecipientData(Recipient recipient)
{
    cout << endl << "Id:                 " << recipient.loadId() << endl;
    cout << "First Name:         " << recipient.loadFirstName() << endl;
    cout << "Last Name:          " << recipient.loadLastName() << endl;
    cout << "Phone Number:       " << recipient.loadPhoneNumber() << endl;
    cout << "Email:              " << recipient.loadEmail() << endl;
    cout << "Address:            " << recipient.loadAddress() << endl;
}

void RecipientManager::loadRecipientsFromFile(int loggedInUserId)
{
    recipients = fileWithRecipients.loadRecipientsOfLoggedInUserFromFile(loggedInUserId);
}

void RecipientManager::searchRecipientsByFirstName()
{
    string firstNameToSearch = "";
    int recipientsCount = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> SEARCHING FOR RECIPIENTS BY FIRST NAME <<<" << endl << endl;

        cout << "Search for recipients with the first name: ";
        firstNameToSearch = HelperMethods::readLine();
        firstNameToSearch = HelperMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(firstNameToSearch);

        for (vector<Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr->loadFirstName() == firstNameToSearch)
            {
                displayRecipientData(*itr);
                recipientsCount++;
            }
        }
        displayNumberOfFoundRecipients(recipientsCount);
    }
    else
    {
        cout << endl << "The address book is empty" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager::displayNumberOfFoundRecipients(int recipientsCount)
{
    if (recipientsCount == 0)
        cout << endl << "There are no recipients with these details in the address book." << endl;
    else
        cout << endl << "The number of recipients in the address book is: " << recipientsCount << endl << endl;
}

void RecipientManager::searchRecipientsByLastName()
{
    string lastNameToSearch;
    int recipientsCount = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> SEARCHING FOR RECIPIENTS BY LAST NAME <<<" << endl << endl;

        cout << "Search for recipients with the last name: ";
        lastNameToSearch = HelperMethods::readLine();
        lastNameToSearch = HelperMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(lastNameToSearch);

        for (vector<Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr->loadLastName() == lastNameToSearch)
            {
                displayRecipientData(*itr);
                recipientsCount++;
            }
        }
        displayNumberOfFoundRecipients(recipientsCount);
    }
    else
    {
        cout << endl << "The address book is empty." << endl << endl;
    }
    cout << endl;
    system("pause");
}

int RecipientManager::enterSelectedRecipientId()
{
    int selectedRecipientId = 0;
    cout << "Enter Recipient ID number: ";
    selectedRecipientId = HelperMethods::loadInteger();
    return selectedRecipientId;
}

int RecipientManager::removeRecipient()
{
    int idToRemove = 0;

    system("cls");
    cout << ">>> REMOVING SELECTED RECIPIENT <<<" << endl << endl;
    idToRemove = enterSelectedRecipientId();

    char sign;
    bool doesRecipientExist = false;

    for (vector<Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
    {
        if (itr->loadId() == idToRemove)
        {
            doesRecipientExist = true;
            cout << endl << "Confirm by pressing 't' key: ";
            sign = HelperMethods::loadChar();
            if (sign == 't')
            {
                fileWithRecipients.removeRecipientFromFile(idToRemove);
                recipients.erase(itr);
                cout << endl << endl << "The searched recipient has been REMOVED" << endl << endl;
                system("pause");
                return idToRemove;
            }
            else
            {
                cout << endl << endl << "The selected recipient has NOT been removed" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (doesRecipientExist == false)
    {
        cout << endl << "There is no such recipient in the address book" << endl << endl;
        system("pause");
    }
    return 0;
}

void RecipientManager::editRecipient()
{
    system("cls");
    int idToEdit = 0;

    cout << ">>> EDITING SELECTED RECIPIENT <<<" << endl << endl;
    idToEdit = enterSelectedRecipientId();

    char choice;
    bool doesRecipientExist = false;

    for (vector<Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
    {
        if (itr->loadId() == idToEdit)
        {
            doesRecipientExist = true;
            choice = selectOptionFromEditMenu();

            switch (choice)
            {
            case '1':
                cout << "Enter new first name: ";
                itr->setFirstName(HelperMethods::readLine());
                itr->setFirstName(HelperMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(itr->loadFirstName()));
                updateDataOfEditedRecipient(*itr);
                break;
            case '2':
                cout << "Enter new last name: ";
                itr->setLastName(HelperMethods::readLine());
                itr->setLastName(HelperMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(itr->loadLastName()));
                updateDataOfEditedRecipient(*itr);
                break;
            case '3':
                cout << "Enter new phone number: ";
                itr->setPhoneNumber(HelperMethods::readLine());
                updateDataOfEditedRecipient(*itr);
                break;
            case '4':
                cout << "Enter new email: ";
                itr->setEmail(HelperMethods::readLine());
                updateDataOfEditedRecipient(*itr);
                break;
            case '5':
                cout << "Enter new home address: ";
                itr->setAddress(HelperMethods::readLine());
                updateDataOfEditedRecipient(*itr);
                break;
            case '6':
                cout << endl << "Returning to user menu" << endl << endl;
                break;
            default:
                cout << endl << "No such option in menu! Returning to user menu." << endl << endl;
                break;
            }
        }
    }
    if (doesRecipientExist == false)
    {
        cout << endl << "No such recipient." << endl << endl;
    }
    system("pause");
}

char RecipientManager::selectOptionFromEditMenu()
{
    char choice;

    cout << endl << "   >>> EDIT MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Which data to update: " << endl;
    cout << "1 - First name" << endl;
    cout << "2 - Last name" << endl;
    cout << "3 - Phone number" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Address" << endl;
    cout << "6 - Return " << endl;
    cout << endl << "Your choice: ";
    choice = HelperMethods::loadChar();

    return choice;
}

void RecipientManager::updateDataOfEditedRecipient(Recipient recipient)
{
    fileWithRecipients.editRecipientInFile(recipient);
    cout << endl << "Data has been updated." << endl << endl;
}