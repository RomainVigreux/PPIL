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
#include "ExpertCorPolygone.h"
#include "ExpertCorSeg.h"
#include "GroupForm.h"

int main (){
    Shape * f = new Segment(Vecteur2D(1, 2), Vecteur2D(3, 4), "red");
    VisitorSave * v = new VisitorSaveText();
    f->save(v);
    delete f;
    delete v;
    return 0;
}



