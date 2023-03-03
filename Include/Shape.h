#include <string>
#include "Tranforme.h"
#include "Vecteur2D.h"

using namespace std;

class Shape : public Transforme{
    private :
        string couleur;
    
    public :

        Shape();
        Shape(const string & couleur) : couleur(couleur) {}

        virtual void translation(const Vecteur2D & u) = 0; // déplacement d'un vecteur u
        virtual void rotation(const double & angle) = 0; // rotation d'un angle en degrés
        virtual void homothetie(const double & k) = 0; // homothétie d'un facteur k

        virtual Vecteur2D getMinXMinY() const = 0;
        virtual Vecteur2D getMaxXMaxY() const = 0;

        void setCouleur(const string & couleur) { this->couleur = couleur; }
        virtual double getPerimetre() const = 0;
        virtual double getAire() const = 0;
        virtual Shape * clone() const = 0;

        virtual ~Shape() {}

        friend ostream & operator << (ostream & os, const Shape & s);

        virtual const void * save(const VisitorSave * v) const = 0;


};

ostream & operator << (ostream & os, const Shape & s) {
    os << "couleur : " << s.couleur << endl;
    return os;
}




