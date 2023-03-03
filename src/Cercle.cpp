#include "Cercle.h"
#include <math.h>

void Cercle::translation(const Vecteur2D & u) {
    centre = centre + u;
}

void Cercle::rotation(const double & angle) {
    Vecteur2D p(rayon, 0);
    p.rotation(angle);
    centre.rotation(angle);
}

void Cercle::homothetie(const double & k) {
    rayon *= k;
    centre.homothetie(k);
}

Vecteur2D Cercle::getMinXMinY() const {
    return Vecteur2D(centre.getX() - rayon, centre.getY() - rayon);
}

Vecteur2D Cercle::getMaxXMaxY() const {
    return Vecteur2D(centre.getX() + rayon, centre.getY() + rayon);
}

double Cercle::getPerimetre() const {
    return 2 * PI * rayon;
}

double Cercle::getAire() const {
    return PI * pow(rayon, 2);
}
