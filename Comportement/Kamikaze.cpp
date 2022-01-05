#include "Kamikaze.h"

void
Kamikaze::change(list<double> vitessList, list<double> orientationList, int xPorch, int yProch, Bestiole &bestiole) {
    if(xPorch == -1 || yProch == -1){
        return;
    }
    double ecartDistance = sqrt((xPorch-bestiole.getX())*(xPorch-bestiole.getX())+(yProch-bestiole.getY())*(yProch-bestiole.getY()));
    double alpha = acos((xPorch-bestiole.getX())/ecartDistance);
    double Beta = asin((yProch-bestiole.getY())/ecartDistance);
    if (Beta>0){
        alpha = -alpha;
    }
    bestiole.setNextOrientation(alpha);
}
