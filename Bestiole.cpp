#include "Bestiole.h"

#include "Milieu.h"

#include <cstdlib>
#include <cmath>
#include <memory>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 5.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;

const double      Bestiole::MAX_AGE = 800.;


Bestiole::Bestiole(void) {

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par defaut" << endl;

    x = y = 0;
    cumulX = cumulY = 0.;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;

    couleur = new T[3];
    couleur[0] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );
    couleur[1] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );
    couleur[2] = static_cast<int>( static_cast<double>( rand()) / RAND_MAX * 230. );

}



Bestiole::Bestiole(shared_ptr<Comportement> comportement, bool multiple, list<shared_ptr<Capteur>> listCapteurs, map<string, shared_ptr<Accessoire>> mapAccessoires, string couleur)

{
   // Ajout de ces attributs : 
   this->listCapteurs = listCapteurs;
   this->mapAccessoires = mapAccessoires;

    this->comportement = comportement;
    this->multiple = multiple;
    // ***
//    dureeVie = (static_cast<double>(rand())/RAND_MAX) * MAX_AGE;
    dureeVie = MAX_AGE;

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par factory" << endl;

    x = y = 0;

    cumulX = cumulY = 0.;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    nextOrientation = orientation;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;


   this-> couleur = new T[ 3 ];
   if (couleur== "marron") {
       this->couleur[ 0 ] = 96;
       this->couleur[ 1 ] = 64;
       this->couleur[ 2 ] = 32;
   };
    if (couleur== "rouge") {
        this->couleur[ 0 ] = 230;
        this->couleur[ 1 ] = 20;
        this->couleur[ 2 ] = 20;
    };
    if (couleur== "bleu") {
        this->couleur[ 0 ] = 20;
        this->couleur[ 1 ] = 20;
        this->couleur[ 2 ] = 230;
    };
    if (couleur== "vert") {
        this->couleur[ 0 ] = 20;
        this->couleur[ 1 ] = 230;
        this->couleur[ 2 ] = 20;
    };
    if (couleur== "rose") {
        this->couleur[ 0 ] = 220;
        this->couleur[ 1 ] = 0;
        this->couleur[ 2 ] = 200;
    };


}

Bestiole::Bestiole(const Bestiole &b) {

    this->listCapteurs = b.listCapteurs;
    this->mapAccessoires = b.mapAccessoires;
    this->comportement = b.comportement;
    this->multiple = b.multiple;
    dureeVie = b.dureeVie;
    identite = b.identite;

    cout << "const Bestiole (" << identite << ") par copie" << endl;

    x = b.x;
    y = b.y;
    cumulX = cumulY = 0.;
    orientation = b.orientation;
    nextOrientation = b.nextOrientation;
    vitesse = b.vitesse;
    couleur = new T[3];

    memcpy(couleur, b.couleur, 3 * sizeof(T));


}


Bestiole::~Bestiole(void) {

    delete[] couleur;

    cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords(int xLim, int yLim) {

    x = rand() % xLim;
    y = rand() % yLim;

}

void Bestiole::bouge(int xLim, int yLim) {

    double coefVitesse  = mapAccessoires.at("nageoires")->getCoefVit();
    double coefLent = mapAccessoires.at("carapace")->getCoefLent();

    // Déplace la bestiole sur le graphe, suivant sa vitesse et son orientation.
    orientation = nextOrientation;

    double nx, ny;
    double dx = cos(orientation) * vitesse * coefVitesse / coefLent;
    double dy = -sin(orientation) * vitesse * coefVitesse / coefLent;
    int cx, cy;

    cx = static_cast<int>( cumulX );
    cumulX -= cx;
    cy = static_cast<int>( cumulY );
    cumulY -= cy;

    nx = x + dx + cx; // nouveau x
    ny = y + dy + cy; // nouveau y

    if ((nx < 0) || (nx > xLim - 1)) {
        // Contact avec un bord
        orientation = M_PI - orientation;
        cumulX = 0.;
    } else {
        // Déplacement sur x
        x = static_cast<int>( nx );
        cumulX += nx - x;
    }

    if ((ny < 0) || (ny > yLim - 1)) {
        // Contact avec un bord
        orientation = -orientation;
        cumulY = 0.;
    } else {
        // Déplacement sur y
        y = static_cast<int>( ny );
        cumulY += ny - y;
    }
    nextOrientation = orientation;
}


void Bestiole::action(Milieu &monMilieu) {

    bouge(monMilieu.getWidth(), monMilieu.getHeight());

}


void Bestiole::draw(UImg &support) {

    double xt = x + cos(orientation) * AFF_SIZE / 2.1;
    double yt = y - sin(orientation) * AFF_SIZE / 2.1;


    support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., couleur);
    support.draw_circle(xt, yt, AFF_SIZE / 2., couleur);

}


bool operator==(const Bestiole &b1, const Bestiole &b2) {

    return (b1.identite == b2.identite);

}


bool Bestiole::jeTeVois(const Bestiole &b) {
    // Antoine la réécrit, en utilisant listCapteurs
    bool vue = false;
//<<<<<<< HEAD
//    for (list<Capteur>::iterator it = listCapteurs.begin(); it != listCapteurs.end(); it++) {
//        vue = vue || it->jeTeVois(x, y, b.x, b.y, orientation, b.mapAccessoires.at("camouflage")->getCapaciteCamouf()); // C'est b.camouflage plutôt ?
//    }
//=======
    for (list<shared_ptr<Capteur>>::iterator it = listCapteurs.begin(); it != listCapteurs.end(); it++) {
        vue = vue || (*it)->jeTeVois(x, y, b.x, b.y, orientation, b.mapAccessoires.at("camouflage")->getCapaciteCamouf()); // C'est b.camouflage plutôt ?
    }

    /*
    bool vu =yeux.jeTeVois(x,y,b.x,b.y,orientation,camouflage);
    bool entendu = oreilles.jeTeVois(x,y,b.x,b.y,orientation,camouflage);

    return ( vu||entendu );
    */
    if (vue) {
        cout<<identite<<" a vu "<<b.identite<<endl;
//        this->bestiolesDetectees.push_back(b);
    }


    return vue;
}

bool Bestiole::ifDie() {
    if (dureeVie == 0) {
        return true;
    } else {
        dureeVie--;
        return false;
    }
}

int Bestiole::getIdentite() const {
    return identite;
}

Bestiole &Bestiole::operator=(const Bestiole & b) {
    if(!(b == *this)){
        this->listCapteurs = b.listCapteurs;
        this->mapAccessoires = b.mapAccessoires;

        this->comportement = b.comportement;
        this->multiple = b.multiple;
        dureeVie = b.dureeVie;
        identite = b.identite;

        cout << "const Bestiole (" << identite << ") par copie" << endl;

        x = b.x;
        y = b.y;
        cumulX = b.cumulX;
        cumulY = b.cumulY;
        orientation = b.orientation;
        nextOrientation = b.nextOrientation;
        vitesse = b.vitesse;

        memcpy( this->couleur, b.couleur, 3*sizeof(T) );
    }

    return *this;
}

bool Bestiole::ifEncollision(const Bestiole &b) {


    double difX = x - b.x;
    double difY = y - b.y;
//    if(fabs(difX) <= 2 && fabs(difY) <= 2)
    if(sqrt(difX*difX+difY*difY) < 5){
        cout<<"collision!!!!!!!!!"<<endl;
        return true;
    }

    return false;
}

void Bestiole::setDureeVie(int dureeVie) {
    Bestiole::dureeVie = dureeVie;
}

void Bestiole::inverseOrientation() {
    nextOrientation = orientation + M_PI;
}


void Bestiole::shiftCoords(int x, int y) {
    this->x += x;
    this->y +=y;
}

const map<string, shared_ptr<Accessoire>> &Bestiole::getMapAccessoires() const {
    return mapAccessoires;
}

void Bestiole::setIdentiteNext() {
    Bestiole::identite = ++next;
}

int Bestiole::getX() const {
    return x;
}

int Bestiole::getY() const {
    return y;
}

double Bestiole::getOrientation() const {
    return orientation;
}

double Bestiole::getVitesse() const {
    return vitesse;
}

void Bestiole::useComportement(list<double> vitessList, list<double> orientationList, int xPorch, int yProch) {
    if(this->multiple) {
        double alea = static_cast<double>(rand()) / RAND_MAX;
        if (alea < 0.25) {
            shared_ptr<Gregaire> gregairePtr(new Gregaire());
            this->comportement = gregairePtr;
        } else if (alea < 0.5) {
            shared_ptr<Peureuse> peureusePtr(new Peureuse());
            this->comportement = peureusePtr;
        } else if (alea < 0.75) {
            shared_ptr<Kamikaze> kamikazePtr(new Kamikaze());
            this->comportement = kamikazePtr;
        } else if (alea < 1) {
            shared_ptr<Prevoyante> prevoyantePtr(new Prevoyante());
            this->comportement = prevoyantePtr;
        }
    }
    comportement->change(vitessList, orientationList, xPorch, yProch, *this);
}

void Bestiole::setNextOrientation(double nextOrientation) {
    Bestiole::nextOrientation = nextOrientation;
}

