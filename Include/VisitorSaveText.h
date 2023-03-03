#include "VisitorSave.h"
#include <string>
#include <iostream>
#include <fstream>

class VisitorSaveText : public VisitorSave {
    public :
        const void *visit (const Shape &f) const;
};