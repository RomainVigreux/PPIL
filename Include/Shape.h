#include <string>
#include <iostream>
#include "Tranforme.h"
#include "Vecteur2D.h"
#include "VisitorSave.h"

using namespace std;

class Shape : public Transforme{

protected:
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
        double getPerimetre() const;
        double getAire() const;
        virtual Shape * clone() const = 0;

        virtual ~Shape() {}

        friend ostream & operator << (ostream & os, const Shape & s);

         const void * save(const VisitorSave * v) const;


    Shape *solve(const string &basicString);
};

ostream & operator << (ostream & os, const Shape & s) {
    os << "couleur : " << s.couleur << endl;
    return os;
}






