#include "Nageoires.h"
#include "Accessoire.h"


Nageoires::Nageoires(){
    this->coefVit = 1;
};

Nageoires::Nageoires(double coefVit){
    this->coefVit =coefVit;
}

Nageoires::Nageoires(const Nageoires &n) {
    coefVit = n.coefVit;
};

double Nageoires::getCoefVit() const {
    return coefVit;
}

Nageoires &Nageoires::operator=(const Nageoires &n) {
    return *this;
}


