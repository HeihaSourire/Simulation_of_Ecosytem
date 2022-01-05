#ifndef _OREILLES_H_
#define _OREILLES_H_

#include "Capteur.h"


class Oreilles : public Capteur {

    private :
        double distance;
        double capaciteDetection;
    public :
        Oreilles();
        Oreilles(double distance, double capaciteDetection);
        bool jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2, double orientation, double camouflage);
};

#endif