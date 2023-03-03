#include "Segment.h"

void Segment::translation(const Vecteur2D & u) {
    p1 = p1 + u;
    p2 = p2 + u;
}

void Segment::rotation(const double & angle) {
     // Calcul du nouveau point p1 après rotation autour de l'origine (0, 0)
    double x1 = cos(angle) * p1.getX() - sin(angle) * p1.getY();
    double y1 = sin(angle) * p1.getX() + cos(angle) * p1.getY();
    Vecteur2D new_p1(x1, y1);

    // Calcul du nouveau point p2 après rotation autour de l'origine (0, 0)
    double x2 = cos(angle) * p2.getX() - sin(angle) * p2.getY();
    double y2 = sin(angle) * p2.getX() + cos(angle) * p2.getY();
    Vecteur2D new_p2(x2, y2);

    // Création d'un nouveau Segment avec les points tournés
    Segment* new_segment = new Segment(new_p1, new_p2, couleur);

    // Copie des attributs de la classe Shape dans le nouveau Segment tourné
    new_segment->setCouleur(couleur);

    *this = *new_segment;

    delete new_segment;
}

void Segment::homothetie(const double & k) {

      // Calcul du nouveau point p1 après homothétie par rapport à l'origine (0, 0)
    double x1 = k * p1.getX();
    double y1 = k * p1.getY();
    Vecteur2D new_p1(x1, y1);

    // Calcul du nouveau point p2 après homothétie par rapport à l'origine (0, 0)
    double x2 = k * p2.getX();
    double y2 = k * p2.getY();
    Vecteur2D new_p2(x2, y2);

    // Création d'un nouveau Segment avec les points homothétiques
    Segment* new_segment = new Segment(new_p1, new_p2, couleur);

    // Copie des attributs de la classe Shape dans le nouveau Segment homothétique
    new_segment->setCouleur(couleur);

    *this = *new_segment;

    // Nettoyage de la mémoire
    delete new_segment;

}

Vecteur2D Segment::getMinXMinY() const {
    Vecteur2D minXMinY = p1;
    if (p2.getX() < minXMinY.getX()) {
        minXMinY.setX(p2.getX());
    }
    if (p2.getY() < minXMinY.getY()) {
        minXMinY.setY(p2.getY());
    }
    return minXMinY;
}

Vecteur2D Segment::getMaxXMaxY() const {
    Vecteur2D maxXMaxY = p1;
    if (p2.getX() > maxXMaxY.getX()) {
        maxXMaxY.setX(p2.getX());
    }
    if (p2.getY() > maxXMaxY.getY()) {
        maxXMaxY.setY(p2.getY());
    }
    return maxXMaxY;
}

double Segment::getPerimetre() const {
    return p1.distance(p2);
}

double Segment::getAire() const {
    return 0;
}

const void * Segment::save(const VisitorSave * v) const {
    return v->save(this);
}
