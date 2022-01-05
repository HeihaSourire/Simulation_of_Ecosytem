#include "Accessoire.h"
#include "Carapace.h"

Carapace::Carapace(){
    this->coefMort = 1;
    this->coefLent = 1;

};
Carapace::Carapace(double coefMort, double coefLent){
    this-> coefMort = coefMort;
    this ->coefLent = coefLent;
}

double Carapace::getCoefMort() const {
    return coefMort;
}

double Carapace::getCoefLent() const {
    return coefLent;
};
