#include "Accessoire.h"
#include "Camouflage.h" 

Camouflage::Camouflage(){
    this ->capaciteCamouf = 0;
}

Camouflage::Camouflage(double capaciteCamouf){
    this-> capaciteCamouf = capaciteCamouf;
}

double Camouflage::getCapaciteCamouf() const {
    return capaciteCamouf;
};

