#include "Expert.h"

class ExpertCor : public Expert {
    
    private :
        Formes * formes;
        ExpertCor * next;
    public :
        //Design Pattern Chain of Responsibility
        ExpertCor(ExpertCor* next) : next(next) {}

        virtual Formes * solve(const string & s) {
            Formes * f = formes->solve(s);
            if (f == NULL) {
                return next->solve(s);
            }
            return NULL;
        }
}