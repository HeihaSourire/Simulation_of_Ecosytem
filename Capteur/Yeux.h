#ifndef _YEUX_H_
#define _YEUX_H_

#include "Capteur.h"



class Yeux : public Capteur {

    private :
        double champAngulaire;
        double distance;
        double capaciteDetection;
    public :
        Yeux();
        Yeux(double champAngulaire, double distance, double capaciteDetection);
        bool jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2,double orientation, double camouflage);
};

#endif