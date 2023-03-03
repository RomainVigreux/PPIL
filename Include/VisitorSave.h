#include "Shape.h"
#include "Cercle.h"

using namespace std;

class VisitorSave{

public:

    virtual const void * save(const Shape *f) const = 0;
};