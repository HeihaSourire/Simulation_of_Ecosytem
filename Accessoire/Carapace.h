#ifndef _CARAPACE_H_
#define _CARAPACE_H_

#include "Accessoire.h"

using namespace std;

class Carapace : public Accessoire {
    
    private :
        double coefMort; // coefficientResistante   
        double coefLent; // vitesseReduit
    public :
        Carapace();
        Carapace(double coefMort, double coefLent);

    double getCoefMort() const;

    double getCoefLent() const;

};

#endif