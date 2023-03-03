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

GroupForm & GroupForm::addShape(const Shape & f) {
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
    return Vecteur2D();
}

GroupForm::operator string() const {
   ostringstream os;

    os << "groupe : [ ";
    for (int i = 0; i < forms.size(); ++i)
    {
        os << forms[i] << " ; ";
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
    double minX = forms[0]->getMinXMinY().x;
    double minY = forms[0]->getMinXMinY().y;
    for (int i = 1; i < forms.size(); i++) {
        if(forms[i]->getMaxXMaxY().x < minX) minX = forms[i]->getMaxXMaxY().x;
        if(forms[i]->getMaxXMaxY().y < minX) minX = forms[i]->getMaxXMaxY().y;
    }
    return Vecteur2D(minX, minY);
}

Vecteur2D GroupForm::getMaxXMaxY() const {
    double maxX = forms[0]->getMaxXMaxY().x;
    double maxY = forms[0]->getMaxXMaxY().y;
    for (int i = 1; i < forms.size(); i++) {
       if(forms[i]->getMaxXMaxY().x < maxX) maxX = forms[i]->getMaxXMaxY().x;
       if(forms[i]->getMaxXMaxY().y < maxX) maxX = forms[i]->getMaxXMaxY().y;
    }
    return Vecteur2D(maxX, maxY);
}



