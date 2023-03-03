#include "Vecteur2D.h"
#include <string>
#include <math.h>
#include "Shape.h"

using namespace std;

class Segment : public Shape {
    private :
        Vecteur2D p1;
        Vecteur2D p2;

    public :
        Segment();
        Segment(const Vecteur2D & p1, const Vecteur2D & p2, const string & couleur) : Shape(couleur), p1(p1), p2(p2) {}
        Segment(const Segment & s) : Shape(s.couleur), p1(s.p1), p2(s.p2) {}

        virtual void translation(const Vecteur2D & u);
        virtual void rotation(const double & angle);
        virtual void homothetie(const double & k);

        virtual Vecteur2D getMinXMinY() const;
        virtual Vecteur2D getMaxXMaxY() const;

        virtual double getPerimetre() const;
        virtual double getAire() const;
        virtual Segment * clone() const;

        virtual ~Segment() {}

        friend ostream & operator << (ostream & os, const Segment & s);

        const void *save(const VisitorSave *v) const;

};

ostream & operator << (ostream & os, const Segment & s) {
    os << "Segment : " << endl;
    os << "p1 : " << s.p1 << endl;
    os << "p2 : " << s.p2 << endl;
    os << "couleur : " << s.couleur << endl;
    return os;
}