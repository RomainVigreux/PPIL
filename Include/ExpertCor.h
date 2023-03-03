#include "Expert.h"

class ExpertCor : public Expert {
    
    private :
        Shape * formes;
        ExpertCor * next;
    public :
        //Design Pattern Chain of Responsibility
        ExpertCor(ExpertCor* next) : next(next) {}

        virtual Shape * solve(const string & s) {
            Shape * f = formes->solve(s);
            if (f == NULL) {
                return next->solve(s);
            }
            return NULL;
        }
};