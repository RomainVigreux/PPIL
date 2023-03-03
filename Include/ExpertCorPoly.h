#include "Formes.h"
#include "Polygone.h"
#include "ExpertCor.h"

using namespace std;

class ExpertCorPoly : public ExpertCor {
    public :
        ExpertCorPoly(ExpertCor* next) : ExpertCor(next) {}
        
    
        virtual Formes * solve(const string & s) {
            if (s.find("Polygone") != string::npos) {
                //On récupère les points
                vector<Vecteur2D> points;
                int pos = s.find("points : ");
                string pointsStr = s.substr(pos + 9);
                int pos2 = pointsStr.find("couleur : ");
                pointsStr = pointsStr.substr(0, pos2 - 1);
                pos = 0;
                pos2 = 0;
                while (pos2 != string::npos) {
                    pos2 = pointsStr.find(";");
                    string pointStr = pointsStr.substr(pos, pos2 - pos);
                    pos = pos2 + 1;
                    pos2 = pointsStr.find(";");
                    string xStr = pointsStr.substr(pos, pos2 - pos);
                    pos = pos2 + 1;
                    pos2 = pointsStr.find(";");
                    string yStr = pointsStr.substr(pos, pos2 - pos);
                    pos = pos2 + 1;
                    pos2 = pointsStr.find(";");
                    points.push_back(Vecteur2D(stod(xStr), stod(yStr)));
                }
                //On récupère la couleur
                pos = s.find("couleur : ");
                string couleur = s.substr(pos + 10);
                return new Polygone(points, couleur);
            }
            return NULL;
        }
}
