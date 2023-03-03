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

}

/*Cette fonction prend un coefficient d'homothétie k et effectue une homothétie de tous les points du polygone par rapport à son centre de gravité selon ce coefficient.*/
void Polygone::homothetie(const double & k) {

}

/*Cette fonction renvoie le vecteur le plus petit (en termes de coordonnées x et y) parmi tous les points du polygone.*/
Vecteur2D Polygone::getMinXMinY() const {
    double minX = points[0].x , minY = points[0].y;

    for(int i = 0 ; i < points.size() ; i++){
        if ( points[i].x < minX ) minX = points[i].x;
        if ( points[i].y < minY ) minY = points[i].y;
    }

    return Vecteur2D(minX,minY);
}

/*Cette fonction renvoie le vecteur le plus grand (en termes de coordonnées x et y) parmi tous les points du polygone.*/
Vecteur2D Polygone::getMaxXMaxY() const {
    double maxX = points[0].x , maxY = points[0].y;

    for(int i = 0 ; i < points.size() ; i++){
        if ( points[i].x < maxX ) maxX = points[i].x;
        if ( points[i].y < maxY ) maxY = points[i].y;
    }

    return Vecteur2D(maxX,maxY);
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

}

/*Cette fonction crée une copie exacte du polygone courant et renvoie un pointeur vers cette copie.*/
Polygone * Polygone::clone() const {
    return new Polygone(*this);
}

const void *Polygone::save(const VisitorSave *v) const {
    return v->save(this);
}
