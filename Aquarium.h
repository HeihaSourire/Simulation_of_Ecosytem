#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include "CImg.h"
#include "Factory.h"
#include "Configuration.h"

using namespace std;
using namespace cimg_library;


class Milieu;


class Aquarium : public CImgDisplay
{

private :
   Milieu       * flotte;

   int            delay;

public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );
//   Configuration & getConfiguration(void)  { return *config; }
//   Factory & getFactory(void) { return *factory; };
   Milieu & getMilieu( void ) { return *flotte; }

   void run( void );

};


#endif
