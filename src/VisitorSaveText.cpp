#include "VisitorSaveText.h"
#include <iostream>

using namespace std;

const void * VisitorSaveText::visit(const Form & f) const {
    ofstream file;
    file.open("save.txt", ios::app);
    file << f;
    file.close();
    return NULL;
}

