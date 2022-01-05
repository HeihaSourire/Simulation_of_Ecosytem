#include "Peureuse.h"


void
Peureuse::change(list<double> vitessList, list<double> orientationList, int xPorch, int yProch, Bestiole &bestiole) {
    if(orientationList.size() > 4){
        bestiole.setNextOrientation(bestiole.getOrientation() + M_PI);
    }
}
