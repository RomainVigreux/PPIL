#include <string>

using namespace std;

class Expert {
    public :
        virtual Shape * solve(const string & s) = 0;
};