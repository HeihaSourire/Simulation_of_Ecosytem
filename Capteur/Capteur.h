#ifndef _CAPTEUR_H_
#define _CAPTEUR_H_


#include <iostream>



class Capteur {

    public:
        virtual bool jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2,double orientation, double camouflage);
};

#endif