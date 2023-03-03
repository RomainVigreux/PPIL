#include "GroupForm.h"
#include "Shape.h"

using namespace std;

GroupForm::~GroupForm() {
    for (int i = 0; i < forms.size(); i++) {
        delete forms[i];
    }
}

Shape * GroupForm::getForm(int i) const {
    return forms[i];
}

void GroupForm::setColor(const string & couleur) {
    this->couleur = couleur;
}

const string & GroupForm::getColor() const {
    return couleur;
}

GroupForm & GroupForm::addForm(const Form & f) {
    forms.push_back(f.clone());
    return *this;
}

void GroupForm::applyTranslation(const Vecteur2D & u) {
    for (int i = 0; i < forms.size(); i++) {
        forms[i]->translation(u);
    }
}

void GroupForm::applyRotation(const double & angle) {
    for (int i = 0; i < forms.size(); i++) {
        forms[i]->rotation(angle);
    }
}

void GroupForm::applyHomothetie(const double & k) {
    for (int i = 0; i < forms.size(); i++) {
        forms[i]->homothetie(k);
    }
}

double GroupForm::calculAir() const {
    double aire = 0;
    for (int i = 0; i < forms.size(); i++) {
        aire += forms[i]->getAire();
    }
    return aire;
}

Vecteur2D GroupForm::calculCentreGravite() const {
    Vecteur2D centreGravite;
    for (int i = 0; i < forms.size(); i++) {
        centreGravite += forms[i]->getAire() * forms[i]->getCentreGravite();
    }
    return centreGravite / calculAir();
}

GroupForm::operator string() const {
   ostringstream os;

    os << "groupe : [ ";
    for (int i = 0; i < formes.size(); ++i)
    {
        os << formes[i] << " ; ";
    }
    os << " ] " << this->couleur << " I " << this->getMinXMinY() << " I " << this->getMaxXMaxY();
    return os.str();
}

void GroupForm::translation(const Vecteur2D & u) {
    applyTranslation(u);
}

void GroupForm::rotation(const double & angle) {
    applyRotation(angle);
}

void GroupForm::homothetie(const double & k) {
    applyHomothetie(k);
}

Vecteur2D GroupForm::getMinXMinY() const {
    Vecteur2D minXMinY = forms[0]->getMinXMinY();
    for (int i = 1; i < forms.size(); i++) {
        if (forms[i]->getMinXMinY().getX() < minXMinY.getX()) {
            minXMinY.setX(forms[i]->getMinXMinY().getX());
        }
        if (forms[i]->getMinXMinY().getY() < minXMinY.getY()) {
            minXMinY.setY(forms[i]->getMinXMinY().getY());
        }
    }
    return minXMinY;
}

Vecteur2D GroupForm::getMaxXMaxY() const {
    Vecteur2D maxXMaxY = forms[0]->getMaxXMaxY();
    for (int i = 1; i < forms.size(); i++) {
        if (forms[i]->getMaxXMaxY().getX() > maxXMaxY.getX()) {
            maxXMaxY.setX(forms[i]->getMaxXMaxY().getX());
        }
        if (forms[i]->getMaxXMaxY().getY() > maxXMaxY.getY()) {
            maxXMaxY.setY(forms[i]->getMaxXMaxY().getY());
        }
    }
    return maxXMaxY;
}



