#include "Segment.h"

void Segment::translation(const Vecteur2D & u) {
    p1 = p1 + u;
    p2 = p2 + u;
}

void Segment::rotation(const double & angle) {

}

void Segment::homothetie(const double & k) {

}

Vecteur2D Segment::getMinXMinY() const {
    double minX = p1.x < p2.x ? p1.x : p2.x;
    double minY = p1.y < p2.y ? p1.y : p2.y;
    return Vecteur2D(minX, minY);

}
Vecteur2D Segment::getMaxXMaxY() const {

    double maxX = p1.x > p2.x ? p1.x : p2.x;
    double maxY = p1.y > p2.y ? p1.y : p2.y;

    return Vecteur2D(maxX,maxY);
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
