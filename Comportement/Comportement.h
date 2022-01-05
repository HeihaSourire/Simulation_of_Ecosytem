#ifndef _COMPORTEMENT_H_
#define _COMPORTEMENT_H_

#include <iostream>
#include <list>

using namespace std;

class Bestiole;

class Comportement {

public :


        virtual void change(list<double> vitessList, list<double> orientationList, int xPorch, int yProch, Bestiole& bestiole);


};

#endif