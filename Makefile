simu : main.cpp Aquarium.o Bestiole.o Milieu.o Factory.o Configuration.o Capteur.o Yeux.o Oreilles.o Accessoire.o Camouflage.o Carapace.o Nageoires.o Comportement.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Factory.o Configuration.o Capteur.o Yeux.o Oreilles.o Accessoire.o Camouflage.o Carapace.o Nageoires.o Comportement.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Factory.o : Factory.h Factory.cpp
	g++ -Wall -std=c++11  -c Factory.cpp -I .

Configuration.o : Configuration.h Configuration.cpp
	g++ -Wall -std=c++11  -c Configuration.cpp -I .

Capteur.o : Capteur/Capteur.h Capteur/Capteur.cpp
	g++ -Wall -std=c++11  -c Capteur/Capteur.cpp -I .

Yeux.o : Capteur/Yeux.h Capteur/Yeux.cpp
	g++ -Wall -std=c++11  -c Capteur/Yeux.cpp -I .

Oreilles.o : Capteur/Oreilles.h Capteur/Oreilles.cpp
	g++ -Wall -std=c++11  -c Capteur/Oreilles.cpp -I .

Accessoire.o : Accessoire/Accessoire.h Accessoire/Accessoire.cpp
	g++ -Wall -std=c++11  -c Accessoire/Accessoire.cpp -I .

Camouflage.o : Accessoire/Camouflage.h Accessoire/Camouflage.cpp
	g++ -Wall -std=c++11  -c Accessoire/Camouflage.cpp -I .

Carapace.o : Accessoire/Carapace.h Accessoire/Carapace.cpp
	g++ -Wall -std=c++11  -c Accessoire/Carapace.cpp -I .

Nageoires.o : Accessoire/Nageoires.h Accessoire/Nageoires.cpp
	g++ -Wall -std=c++11  -c Accessoire/Nageoires.cpp -I .

Comportement.o : Comportement/Comportement.h Comportement/Comportement.cpp
	g++ -Wall -std=c++11  -c Comportement/Comportement.cpp -I .

Gregaire.o : Comportement/Gregaire.h Comportement/Gregaire.cpp
	g++ -Wall -std=c++11  -c Comportement/Gregaire.cpp -I .

Kamikaze.o : Comportement/Kamikaze.h Comportement/Kamikaze.cpp
	g++ -Wall -std=c++11  -c Comportement/Kamikaze.cpp -I .

Peureuse.o : Comportement/Peureuse.h Comportement/Peureuse.cpp
	g++ -Wall -std=c++11  -c Comportement/Peureuse.cpp -I .

Prevoyante.o : Comportement/Prevoyante.h Comportement/Prevoyante.cpp
	g++ -Wall -std=c++11  -c Comportement/Prevoyante.cpp -I .


