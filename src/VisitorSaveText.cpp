#include "VisitorSaveText.h"
#include <iostream>

using namespace std;

const void * VisitorSaveText::visit(const Shape & f) const {
    ofstream file;
    file.open("save.txt", fstream::app);
    file << f << "\n";
    file.close();
    return NULL;
}

