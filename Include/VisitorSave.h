#include "Shape.h"

using namespace std;

class VisitorSave{
    virtual const void * visit(const Shape & f) = 0;
};