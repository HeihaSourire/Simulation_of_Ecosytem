#ifndef _ACCESSOIRE_H_
#define _ACCESSOIRE_H_

//#include "Bestiole.h"

#include <iostream>
//#include <list>

using namespace std;

class Accessoire {

public :
    Accessoire();

    virtual double getCoefVit() const;

    virtual double getCapaciteCamouf() const;

    virtual double getCoefMort() const;

    virtual double getCoefLent() const;

};

#endif