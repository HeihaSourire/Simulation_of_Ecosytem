#ifndef _GREGAIRE_H_
#define _GREGAIRE_H_

#include "Comportement.h"
#include "../Bestiole.h"

using namespace std;

class Gregaire : public Comportement {
    
    public :
    void change(list<double> vitessList, list<double> orientationList, int xPorch, int yProch, Bestiole& bestiole) override;


};

#endif