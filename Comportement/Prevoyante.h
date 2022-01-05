#ifndef _PREVOYANTE_H_
#define _PREVOYANTE_H_

#include "Comportement.h"
#include "../Bestiole.h"

using namespace std;

class Prevoyante : public Comportement {
    
    public :
    void change(list<double> vitessList, list<double> orientationList, int xPorch, int yProch, Bestiole& bestiole) override;


};

#endif