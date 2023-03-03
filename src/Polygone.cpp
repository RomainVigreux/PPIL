#include "Polygone.h"
#include "Vecteur2D.h"


/* Cette fonction prend un vecteur u et effectue une translation de tous les points du polygone par ce vecteur.*/
void Polygone::translation(const Vecteur2D & u) {
    for (int i = 0; i < nbPoints; i++) {
        points[i] = points[i] + u;
    }
}
/* Cette fonction prend un angle angle en radians et effectue une rotation de tous les points du polygone autour de son centre de gravité selon cet angle. */
void Polygone::rotation(const double & angle) {
    Vecteur2D centre = getCentre();
    for (int i = 0; i < nbPoints; i++) {
        points[i] -= centre;
        points[i].rotation(angle);
        points[i] += centre;
    }
}

/*Cette fonction prend un coefficient d'homothétie k et effectue une homothétie de tous les points du polygone par rapport à son centre de gravité selon ce coefficient.*/
void Polygone::homothetie(const double & k) {
    Vecteur2D centre = getCentre();
    for (int i = 0; i < nbPoints; i++) {
        points[i] -= centre;
        points[i] *= k;
        points[i] += centre;
    }
}

/*Cette fonction renvoie le vecteur le plus petit (en termes de coordonnées x et y) parmi tous les points du polygone.*/
Vecteur2D Polygone::getMinXMinY() const {
    Vecteur2D min = points[0];
    for (int i = 1; i < nbPoints; i++) {
        if (points[i].getX() < min.getX()) {
            min.setX(points[i].getX());
        }
        if (points[i].getY() < min.getY()) {
            min.setY(points[i].getY());
        }
    }
    return min;
}

/*Cette fonction renvoie le vecteur le plus grand (en termes de coordonnées x et y) parmi tous les points du polygone.*/
Vecteur2D Polygone::getMaxXMaxY() const {
    Vecteur2D max = points[0];
    for (int i = 1; i < nbPoints; i++) {
        if (points[i].getX() > max.getX()) {
            max.setX(points[i].getX());
        }
        if (points[i].getY() > max.getY()) {
            max.setY(points[i].getY());
        }
    }
    return max;
}

/*Cette fonction calcule et renvoie le périmètre du polygone, qui est la somme des distances entre chaque paire de points consécutifs.*/
double Polygone::getPerimetre() const {
    double perimetre = 0;
    for (int i = 0; i < nbPoints - 1; i++) {
        perimetre += points[i].distance(points[i + 1]);
    }
    perimetre += points[nbPoints - 1].distance(points[0]);
    return perimetre;
}

/*Cette fonction calcule et renvoie l'aire du polygone, qui est la moitié de la somme des déterminants formés par chaque paire de points consécutifs.*/
double Polygone::getAire() const {
    double aire = 0;
    for (int i = 0; i < nbPoints - 1; i++) {
        aire += points[i].getX() * points[i + 1].getY() - points[i + 1].getX() * points[i].getY();
    }
    aire += points[nbPoints - 1].getX() * points[0].getY() - points[0].getX() * points[nbPoints - 1].getY();
    return aire / 2;
}

/*Cette fonction crée une copie exacte du polygone courant et renvoie un pointeur vers cette copie.*/
Polygone * Polygone::clone() const {
    return new Polygone(*this);
}

/*Cette fonction ajoute un point p à la fin du vecteur points et incrémente le nombre de points nbPoints. 
Elle renvoie une référence vers le polygone courant pour permettre une utilisation en cascade de la méthode.*/
Polygone& Polygone::addPoint(const Vecteur2D & p) {
    points.push_back(p);
    nbPoints++;
    return *this;
}
