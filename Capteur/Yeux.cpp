#include "Yeux.h"
#include "Capteur.h"

#include <cmath>
#include <math.h>
#include <cstdlib>
#include <iostream>

Yeux::Yeux(){
    champAngulaire = 0;
    distance = 0;
    capaciteDetection = 0;
}
Yeux::Yeux(double champAngulaire, double distance, double capaciteDetection){
    this ->champAngulaire = champAngulaire;
    this ->distance = distance;
    this ->capaciteDetection = capaciteDetection;
} 
bool Yeux::jeTeVois(int xposb1, int yposb1, int xposb2, int yposb2,double orientation, double camouflage){

    double ecartDistance = sqrt((xposb1-xposb2)*(xposb1-xposb2)+(yposb1-yposb2)*(yposb1-yposb2));
    double alpha = acos((xposb2-xposb1)/ecartDistance);
    double Beta = asin((yposb2-yposb1)/ecartDistance);
    if (Beta<0){
        alpha = -alpha;
    }
    double moduleOrientation = acos(cos(orientation));
    double signe = asin(sin(orientation));
    if (signe<0){
        moduleOrientation = -moduleOrientation;
    }
    double ecartAngle = std::min(abs(alpha-moduleOrientation),abs(moduleOrientation-alpha));
    return((capaciteDetection>camouflage)&&(ecartDistance<distance)&&(ecartAngle<champAngulaire/2));

};