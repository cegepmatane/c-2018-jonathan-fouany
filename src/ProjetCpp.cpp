
#include <iostream>
#include <vector>
#include <fstream>
#include "Soldat.h"
#include "Cavalier.h"
#include "Fantassin.h"
#include "Pilote.h"
#include "Accessoire.h"
#include "Fusil.h"
#include "Casque.h"
#include "Gilet.h"

using namespace std;


int main() {


    // Lecture des données dans le fichier d'initialisation
    ifstream source;
    source.open("../data/init.csv");

    string ligne;

    while(!source.eof()) {
        getline(source, ligne);

        unsigned int positionDebut = 0;
        unsigned int positionFin = 0;
        
        do {
            positionFin = ligne.find(";", positionDebut);

            string valeur = ligne.substr(positionDebut, positionFin - positionDebut);
            cout << valeur << endl;

            positionDebut = positionFin + 1;
        }
        while((positionDebut != 0) && (ligne.length() != positionDebut));
    }




	Fusil* m_Fusil = new Fusil("one", 2, "noir", 300);
    Casque* m_Casque = new Casque("two", 1, "vert", "leger");

	Soldat* m_Soldat = new Soldat("Dupont", 20, "infanterie", m_Fusil);
	Soldat* m_Cavalier = new Cavalier("Dupond", 30, "cavalerie", "toto", m_Casque);
	Fantassin* m_Fantassin = new Fantassin("Dupons", 40, "infanterie", "bernadette", m_Casque);
	Pilote* m_Pilote = new Pilote("Jackie", 28, "Armée de l'air", "F-16", m_Casque);


	vector<Soldat*> listeSoldats;
    listeSoldats.push_back(m_Soldat);
    listeSoldats.push_back(m_Cavalier);
    listeSoldats.push_back(m_Fantassin);
    listeSoldats.push_back(m_Pilote);


    /*for (int i = 0; i < listeSoldats.size(); ++i) {
        cout << "========" << endl;
        listeSoldats.at(i)->Attaque();
        listeSoldats.at(i)->getM_Accessoire()->ListerDetailsAccessoire();
        listeSoldats.at(i)->SeDeplace();
    }*/


	delete m_Casque;
	delete m_Fusil;
	delete m_Soldat;
	delete m_Cavalier;
	delete m_Fantassin;
	delete m_Pilote;

	return 0;
}
