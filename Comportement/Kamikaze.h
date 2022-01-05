#ifndef _KAMIKAZE_H_
#define _KAMIKAZE_H_

#include "Comportement.h"
#include "../Bestiole.h"

using namespace std;

class Kamikaze : public Comportement {
    
    public :
    virtual void change(list<double> vitessList, list<double> orientationList, int xPorch, int yProch, Bestiole& bestiole);


};

#endif