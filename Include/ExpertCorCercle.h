#include "Shape.h"
#include "Cercle.h"
#include "ExpertCor.h"

using namespace std;

class ExpertCorCercle : public ExpertCor {
    public :
        ExpertCorCercle(ExpertCor* next) : ExpertCor(next) {}
        
        virtual Shape * solve(const string & s) {
            if (s.find("Cercle") != string::npos) {
                //On récupère le centre
                int pos = s.find("centre : ");
                string centreStr = s.substr(pos + 9);
                pos = centreStr.find(";");
                string xStr = centreStr.substr(0, pos);
                pos = centreStr.find(";");
                string yStr = centreStr.substr(pos + 1);
                Vecteur2D centre(stod(xStr), stod(yStr));
                //On récupère le rayon
                pos = s.find("rayon : ");
                string rayonStr = s.substr(pos + 8);
                pos = rayonStr.find("couleur : ");
                rayonStr = rayonStr.substr(0, pos - 1);
                //On récupère la couleur
                pos = s.find("couleur : ");
                string couleur = s.substr(pos + 10);
                return new Cercle(centre, stod(rayonStr), couleur);
            }
            return NULL;
        }
}