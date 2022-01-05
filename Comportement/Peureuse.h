#ifndef _PEUREUSE_H_
#define _PEUREUSE_H_

#include "Comportement.h"
#include "../Bestiole.h"

using namespace std;

class Peureuse : public Comportement {
    
    public :

    void change(list<double> vitessList, list<double> orientationList, int xPorch, int yProch, Bestiole& bestiole) override;


};

#endif