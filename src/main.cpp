#include <iostream>

using namespace std;
#include "Shape.h"
#include "VisitorSave.h"
#include "VisitorSaveText.h"
#include "Vecteur2D.h"
#include "Segment.h"
#include "Cercle.h"
#include "Polygone.h"
#include "Expert.h"
#include "ExpertCor.h"
#include "ExpertCorCercle.h"
#include "ExpertCorPoly.h"
#include "ExpertCorSeg.h"
#include "GroupForm.h"

int main (){
    Shape * f = new Segment(Vecteur2D(1, 2), Vecteur2D(3, 4), "red");
    Shape * f2 = new Cercle(Vecteur2D(1, 2), 3, "blue");
    Shape * f3 = new Polygone(Vecteur2D(1, 2), Vecteur2D(3, 4), Vecteur2D(5, 6), "green");

    GroupForm * g = new GroupForm();
    g->add(f);
    g->add(f2);
    g->add(f3);

    cout << "Cercle : " << f2 << endl;
    f2->translation(Vecteur2D(1, 1));
    cout << "Cercle : " << f2 << endl;

    
}



