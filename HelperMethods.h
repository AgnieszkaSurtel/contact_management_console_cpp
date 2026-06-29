#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class HelperMethods
{
public:
    HelperMethods();
    static string convertIntToString(int number);
    static string readLine();
    static string changeFirstLetterToUpperCaseAndOthersToLowerCase(string text);
    static int convertStringToInt(string number);
    static char loadChar();
    static int loadInteger();
    static void deleteReadFile(string fileNameWithExtension);
    static void changeTemporaryFileNameToFileName(string temporaryFileNameWithExtension, string fileNameWithExtension);
};

#endif