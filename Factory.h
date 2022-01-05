#ifndef _FACTORY_H_
#define _FACTORY_H_


#include "Configuration.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;

class Factory {
    private : 
        Configuration& configuration;

    public :
        Factory(Configuration& c);

        Bestiole  createBestiole() ;

        


};

#endif