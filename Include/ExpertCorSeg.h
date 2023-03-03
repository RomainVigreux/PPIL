#include "Shape.h"
#include "Segment.h"
#include "ExpertCor.h"

using namespace std;

class ExpertCorSegment : public ExpertCor {
    public :
        ExpertCorSegment(ExpertCor* next) : ExpertCor(next) {}
        
        virtual Shape * solve(const string & s) {
            if (s.find("Segment") != string::npos) {
                //On récupère le premier point
                int pos = s.find("p1 : ");
                string p1Str = s.substr(pos + 5);
                pos = p1Str.find(";");
                string xStr = p1Str.substr(0, pos);
                pos = p1Str.find(";");
                string yStr = p1Str.substr(pos + 1);
                Vecteur2D p1(stod(xStr), stod(yStr));
                //On récupère le deuxième point
                pos = s.find("p2 : ");
                string p2Str = s.substr(pos + 5);
                pos = p2Str.find(";");
                xStr = p2Str.substr(0, pos);
                pos = p2Str.find(";");
                yStr = p2Str.substr(pos + 1);
                Vecteur2D p2(stod(xStr), stod(yStr));
                //On récupère la couleur
                pos = s.find("couleur : ");
                string couleur = s.substr(pos + 10);
                return new Segment(p1, p2, couleur);
            }
            return NULL;
        }
}