#include "Shape.h"
#include "Cercle.h"
#include "ExpertCor.h"

using namespace std;

class ExpertCorCercle : public ExpertCor {
private :
    Shape * formes;
    ExpertCorCercle * next;
    public :
        ExpertCorCercle(ExpertCor* next) : ExpertCor(next) {}
        
        virtual Shape * solve(const string & s) {
            Shape * f = formes->solve(s);
            if (f == NULL) {
                return next->solve(s);
            }
            return NULL;
        }
};