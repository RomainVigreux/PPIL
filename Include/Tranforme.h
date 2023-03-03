#include "Vecteur2D.h"

class Transforme
{
    // classe abstraite
    
    virtual void translation(const Vecteur2D & u) = 0; // déplacement d'un vecteur u   
    virtual void rotation(const double & angle) = 0; // rotation d'un angle en degrés
    virtual void homothetie(const double & k) = 0; // homothétie d'un facteur k
};