#include <string>
#include "Form.h"
#include <vector>

using namespace std;

class GroupForm : public Shape {
    private :
        vector<Form*> forms;
        string couleur;
    
    public :

        GroupForm(const string & couleur) : Form(couleur) {}
        GroupForm(vector<Form*> form, const string & couleur) : Form(couleur) {
            this->couleur = couleur;
            forms = form;
        }

        virtual ~GroupForm();
        forms *getForm(int i) const;
        void setColor(const string & couleur);
        const string & getColor() const;

        GroupForm &addForm(const Form & f);

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