#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

#include "Accessoire.h"

using namespace std;

class Camouflage : public Accessoire {

private:
    double capaciteCamouf; // camouflage

public :
    Camouflage();

    Camouflage(double capaciteCamouf);

    double getCapaciteCamouf() const;

};

#endif