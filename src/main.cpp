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
    Shape *rond, *Segment;
    rond = new Cercle(10,10,15,"bleu");

    GroupForm * g = new GroupForm("Red");
    g->addShape(rond);


    cout << "Cercle : " << rond << endl;


    
}



