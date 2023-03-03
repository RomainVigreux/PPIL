#include <string>

using namespace std;

class Expert {
    public :
        virtual Formes * solve(const string & s) = 0;
}