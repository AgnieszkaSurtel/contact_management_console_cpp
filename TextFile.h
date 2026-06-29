#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "HelperMethods.h"
#include "Recipient.h"

class TextFile
{
    const string FILE_NAME;
protected:
    fstream textFile;
    bool isFileEmpty(fstream &textFile);
};
#endif