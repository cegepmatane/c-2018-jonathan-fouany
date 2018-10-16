
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


    // Lecture des données pour les accessoires dans le fichier d'initialisation
    ifstream source;
    source.open("../data/init.csv");

    string ligne;

    string nom;
    int valeur1;
    string couleur;
    int valeur2;

    Accessoire* m_Accessoire1;
    Accessoire* m_Accessoire2;
    Accessoire* m_Accessoire3;

    int compteurLigne = -1;

    while(!source.eof()) {
        getline(source, ligne);

        unsigned int positionDebut = 0;
        unsigned int positionFin = 0;

        int compteur = 0;
        compteurLigne++;

        do {
            positionFin = ligne.find(";", positionDebut);

            string valeur = ligne.substr(positionDebut, positionFin - positionDebut);

            switch (compteur){
                case 0:
                    nom = valeur;
                    break;
                case 1:
                    valeur1 = stoi(valeur);
                    break;
                case 2:
                    couleur = valeur;
                    break;
                case 3:
                    valeur2 = stoi(valeur);
                    break;
            }

            if (compteur % 3 == 0 && compteurLigne == 0)
                m_Accessoire1 = new Gilet(nom, valeur1, couleur, valeur2);
            else if (compteur % 3 == 0 && compteurLigne == 1)
                m_Accessoire2 = new Casque(nom, valeur1, couleur, valeur2);
            else if (compteur % 3 == 0 && compteurLigne == 2)
                m_Accessoire3 = new Fusil(nom, valeur1, couleur, valeur2);


            compteur++;
            cout << valeur << endl;
            positionDebut = positionFin + 1;
        }
        while((positionDebut != 0) && (ligne.length() != positionDebut));
    }


    /*m_Accessoire1->ListerDetailsAccessoire();
    m_Accessoire2->ListerDetailsAccessoire();
    m_Accessoire3->ListerDetailsAccessoire();*/


    /*Fusil* m_Fusil = new Fusil("one", 2, "noir", 300);
    Casque* m_Casque = new Casque("two", 1, "vert", 50);
    Gilet* m_Gilet = new Gilet("gilet", 18, "marron", 10);*/

	Soldat* m_Soldat = new Soldat("Dupont", 20, "infanterie", m_Accessoire1);
	Soldat* m_Cavalier = new Cavalier("Dupond", 30, "cavalerie", "toto", m_Accessoire2);
	Fantassin* m_Fantassin = new Fantassin("Dupons", 40, "infanterie", "bernadette", m_Accessoire3);
	Pilote* m_Pilote = new Pilote("Jackie", 28, "Armée de l'air", "F-16", m_Accessoire1);


	vector<Soldat*> listeSoldats;
    listeSoldats.push_back(m_Soldat);
    listeSoldats.push_back(m_Cavalier);
    listeSoldats.push_back(m_Fantassin);
    listeSoldats.push_back(m_Pilote);


    for (int i = 0; i < listeSoldats.size(); ++i) {
        cout << "========" << endl;
        listeSoldats.at(i)->Attaque();
        listeSoldats.at(i)->getM_Accessoire()->ListerDetailsAccessoire();
        listeSoldats.at(i)->SeDeplace();
    }

    ofstream fichierMonde;
    fichierMonde.open("../data/monde.xml");
    fichierMonde << "<Monde>" << endl;
    fichierMonde << "<Accessoires>" << endl;
    fichierMonde << m_Accessoire1->Exporter() <<endl;
    fichierMonde << m_Accessoire2->Exporter() <<endl;
    fichierMonde << m_Accessoire3->Exporter() <<endl;
    fichierMonde << "</Accessoires>" << endl;
    fichierMonde << "</Monde>" << endl;
    fichierMonde.close();


	/*delete m_Casque;
	delete m_Fusil;
	delete m_Gilet;*/
	delete m_Soldat;
	delete m_Cavalier;
	delete m_Fantassin;
	delete m_Pilote;

	return 0;
}
