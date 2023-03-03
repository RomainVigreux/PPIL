#include "Vecteur2D.h"
#include <string>
#include <math.h>
#include "Shape.h"

using namespace std;

class Polygone : public Shape {
    private :
        vector<Vecteur2D> points;
        int nbPoints;
    public :
        Polygone();
        Polygone(const vector<Vecteur2D> & points, const string & couleur) : Shape(couleur), points(points), nbPoints(points.size()) {}
        Polygone(const Polygone & p) : Shape(p.couleur), points(p.points), nbPoints(p.nbPoints) {}

        virtual void translation(const Vecteur2D & u);
        virtual void rotation(const double & angle);
        virtual void homothetie(const double & k);

        Polygone& addPoint(const Vecteur2D & p) {}
        virtual Vecteur2D getMinXMinY() const;
        virtual Vecteur2D getMaxXMaxY() const;

        virtual double getPerimetre() const;
        virtual double getAire() const;
        virtual Polygone * clone() const;

        virtual ~Polygone() {}

        friend ostream & operator << (ostream & os, const Polygone & p);

         const void *save(const VisitorSave *v) const;
};

ostream & operator << (ostream & os, const Polygone & p) {
    os << "Polygone : " << endl;
    os << "points : " << endl;
    for (int i = 0; i < p.nbPoints; i++) {
        os << p.points[i] << endl;
    }
    os << "couleur : " << p.couleur << endl;
    return os;
}