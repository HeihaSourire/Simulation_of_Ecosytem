#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include "Comportement/Gregaire.h"
#include "Comportement/Peureuse.h"
#include "Comportement/Kamikaze.h"
#include "Comportement/Prevoyante.h"
#include "Comportement/Comportement.h"

#include "Capteur/Capteur.h"
#include "Capteur/Yeux.h"
#include "Capteur/Oreilles.h"

#include "Accessoire/Accessoire.h"
#include "Accessoire/Nageoires.h"
#include "Accessoire/Carapace.h"
#include "Accessoire/Camouflage.h"

#include <iostream>
#include <list>

#include <map>

#include <memory>


using namespace std;


class Milieu;


class Bestiole {

private :
    static const double AFF_SIZE;
    static const double MAX_VITESSE;
    static const double LIMITE_VUE;

    static int next;

    static const double MAX_AGE; // max of dureeVie

private :
    int identite;

    int dureeVie;
    //bool morte;

    int x, y;
    double cumulX, cumulY;
    double orientation;
    double vitesse;
    double camouflage;
    double nextOrientation;

    T * couleur;
    //Oreilles          oreilles;
    //Yeux              yeux;

    list<shared_ptr<Capteur>> listCapteurs;
    map<string, shared_ptr<Accessoire>> mapAccessoires;


    shared_ptr<Comportement> comportement;
    bool multiple;

private :
    void bouge(int xLim, int yLim);

public :                                           // Forme canonique :
    Bestiole(void);                               // Constructeur par defaut


//    Bestiole(Comportement comportement, bool multiple, list<Capteur> listCapteurs, list<Accessoire> listAccessoires, string couleur);

    // Constructeur donnant comportement, capteurs et accessoires


    Bestiole(const Bestiole &b);                 // Constructeur de copies
    ~Bestiole(void);                              // Destructeur
    // Operateur d'affectation binaire par defaut
    void action(Milieu &monMilieu);

    void draw(UImg &support);

    bool jeTeVois(const Bestiole &b);           // Renvoie si this détecte b

    Bestiole(shared_ptr<Comportement> c, bool multiple, list<shared_ptr<Capteur>>, map<string, shared_ptr<Accessoire>>, string couleur);

    // Constructeur donnant comportement, capteurs et accessoires

    void initCoords(int xLim, int yLim);

    void setDureeVie(int dureeVie);

    void inverseOrientation();

    bool ifDie();
    bool ifEncollision(const Bestiole & b);

//    int calculateNX() const;
//    int calculateNY() const;

    friend bool operator==(const Bestiole &b1, const Bestiole &b2);

    int getIdentite() const;

    Bestiole &operator=(const Bestiole &b);

    void shiftCoords(int x, int y);

    const map<string, shared_ptr<Accessoire>> &getMapAccessoires() const;
    //test methode
    void setIdentiteNext();

    int getX() const;

    int getY() const;

    double getOrientation() const;

    double getVitesse() const;

    void useComportement(list<double> vitessList, list<double> orientationList, int xPorch, int yProch);

    void setNextOrientation(double nextOrientation);

};

#endif