#include "Shape.h"
#include "Vecteur2D.h"
#include <string>

using namespace std;

class Cercle : public Shape {
    private :
        Vecteur2D centre;
        double rayon;
        constexpr const static double PI = 3.14159265358979323846;

    public :
        Cercle();
        Cercle(const Vecteur2D & centre, const double & rayon, const string & couleur) : Shape(couleur), centre(centre), rayon(rayon) {}
        Cercle(const Cercle & c) : Shape(c.couleur), centre(c.centre), rayon(c.rayon) {}

        virtual void translation(const Vecteur2D & u);
        virtual void rotation(const double & angle);
        virtual void homothetie(const double & k);

        virtual Vecteur2D getMinXMinY() const;
        virtual Vecteur2D getMaxXMaxY() const;

        virtual double getPerimetre() const;
        virtual double getAire() const;
        virtual Cercle * clone() const;

        virtual ~Cercle() {}

        friend ostream & operator << (ostream & os, const Cercle & c);

         const void *save(const VisitorSave *v) const;

};

ostream & operator << (ostream & os, const Cercle & c) {
    os << "Cercle : " << endl;
    os << "centre : " << c.centre << endl;
    os << "rayon : " << c.rayon << endl;
    os << "couleur : " << c.couleur << endl;
    return os;
}