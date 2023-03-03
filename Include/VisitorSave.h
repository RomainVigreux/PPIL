#include "Form.h"

using namespace std;

class VisitorSave{
    virtual const void * visit(const Form & f) = 0;
};