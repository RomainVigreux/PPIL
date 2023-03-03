#include "Cercle.h"
#include <math.h>
#include "VisitorSave.h"

void Cercle::translation(const Vecteur2D & u) {
    centre = centre + u;
}

void Cercle::rotation(const double & angle) {

}

void Cercle::homothetie(const double & k) {
    rayon *= k;

}

Vecteur2D Cercle::getMinXMinY() const {
    return Vecteur2D(centre.x-rayon, centre.y-rayon);
}

Vecteur2D Cercle::getMaxXMaxY() const {
    return Vecteur2D(centre.x+rayon, centre.y+rayon);
}

double Cercle::getPerimetre() const {
    return 2 * PI * rayon;
}

double Cercle::getAire() const {
    return PI * pow(rayon, 2);
}

const void *Cercle::save(const VisitorSave *v) const {
    return v->save(this);
}


