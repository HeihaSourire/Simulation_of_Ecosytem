#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Factory.h"

#include <cstdlib>

#include <iostream>

using namespace std;


int main()
{
   
   Aquarium       ecosysteme( 960, 720, 30 );


   for ( int i = 1; i <= ecosysteme.getMilieu().getConfig()->getNombreInit(); ++i ){
//       Bestiole bestiole = ecosysteme.getMilieu().getFactory()->createBestiole();
       ecosysteme.getMilieu().addMember(ecosysteme.getMilieu().getFactory()->createBestiole());
   }

   ecosysteme.run();


   cout << "Test" ;

   return 0;


}
