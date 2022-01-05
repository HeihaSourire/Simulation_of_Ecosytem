#ifndef _NAGEOIRES_H_
#define _NAGEOIRES_H_

#include "Accessoire.h"

using namespace std;

class Nageoires : public Accessoire {

private :
    double coefVit;
public :
    Nageoires();

    Nageoires(double coefVit);

    Nageoires(const Nageoires &n);

    double getCoefVit() const;

    Nageoires &operator =(const Nageoires &n);

};
#endif