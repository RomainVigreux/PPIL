#include <string>
#include "Shape.h"
#include <vector>
#include <iostream>

using namespace std;

class GroupForm : public Shape {
    private :
        vector<Shape*> forms;
        string couleur;
    
    public :

        GroupForm(const string & couleur) : Shape(couleur) {}
        GroupForm(vector<Shape*> form, const string & couleur) : Shape(couleur) {
            this->couleur = couleur;
            forms = form;
        }

        virtual ~GroupForm();
        Shape *getForm(int i) const;
        void setColor(const string & couleur);
        const string & getColor() const;

        GroupForm &addForm(const Shape & f);

        virtual void translation(const Vecteur2D & u);
        virtual void rotation(const double & angle);
        virtual void homothetie(const double & k);

        virtual Vecteur2D getMinXMinY() const;
        virtual Vecteur2D getMaxXMaxY() const;

        void applyTranslation(const Vecteur2D & u);
        void applyRotation(const double & angle);
        void applyHomothetie(const double & k);

        double calculAir() const;
        Vecteur2D calculCentreGravite() const;
        operator string() const;

        virtual GroupForm * clone() const;

        friend ostream & operator << (ostream & os, const GroupForm & g);

};

ostream & operator << (ostream & os, const GroupForm & g) {
    os << "GroupForm : " << endl;
    os << "couleur : " << g.couleur << endl;
    os << "forms : " << endl;
    for (int i = 0; i < g.forms.size(); i++) {
        os << *g.forms[i] << endl;
    }
    return os;
}