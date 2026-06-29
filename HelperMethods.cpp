#include "HelperMethods.h"

string HelperMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelperMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string HelperMethods::changeFirstLetterToUpperCaseAndOthersToLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int HelperMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

char HelperMethods::loadChar()
{
    string input = "";
    char character = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 0) continue; 

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Try again." << endl;
    }
    return character;
}

int HelperMethods::loadInteger()
{
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "This is not a number. Try again." << endl;
    }
    return number;
}

void HelperMethods::deleteReadFile(string fileNameWithExtension)
{
    if (remove(fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "Failed to delete the file " << fileNameWithExtension << endl;
}

void HelperMethods::changeTemporaryFileNameToFileName(string temporaryFileNameWithExtension, string fileNameWithExtension)
{
    if (rename(temporaryFileNameWithExtension.c_str(), fileNameWithExtension.c_str()) == 0) {}
    else
        cout << "File name was not changed." << fileNameWithExtension << endl;
}