
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <afxres.h>
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
            //cout << valeur << endl;
            positionDebut = positionFin + 1;
        }
        while((positionDebut != 0) && (ligne.length() != positionDebut));
    }
    //Fin lecture des données



	Soldat* m_Soldat = new Soldat("Dupont", 20, "infanterie", m_Accessoire1);
	Soldat* m_Cavalier = new Cavalier("Dupond", 30, "cavalerie", "toto", m_Accessoire2);
	Fantassin* m_Fantassin = new Fantassin("Dupons", 40, "infanterie", "bernadette", m_Accessoire3);
	Pilote* m_Pilote = new Pilote("Jackie", 28, "Armée de l'air", "F-16", m_Accessoire1);


    vector<Accessoire*> listeAccessoires;
    listeAccessoires.push_back(m_Accessoire1);
    listeAccessoires.push_back(m_Accessoire2);
    listeAccessoires.push_back(m_Accessoire3);

	vector<Soldat*> listeSoldats;
    //listeSoldats.push_back(m_Soldat);
    listeSoldats.push_back(m_Cavalier);
    listeSoldats.push_back(m_Fantassin);
    listeSoldats.push_back(m_Pilote);


    //BOUCLE INFINIE DE JEU
    char touche;
    bool gameIsRunning = true;
    int index = 0;

    cout << "=== DEBUT DU JEU ===" << endl;

    while(gameIsRunning){
        // PREMIER PROBLEME-SOLUTION : dormir sans occuper les ressources
        Sleep(1000/60);
        // SECOND PROBLEME-SOLUTION : lire les entrées sans bloquer la boucle
        if(_kbhit()){

            touche = getch(); // sors la premiere touche appuyée
            //cout << "touche " << touche << " " << tour << endl;

            switch(touche){

                case 'a' :
                    listeSoldats.at(index)->Attaque();
                    break;

                case 'c' :
                    if (index >= listeSoldats.size() - 1) index = -1;
                    index++;
                    listeSoldats.at(index)->Attaque();
                    break;

                case 'd' :
                    listeSoldats.at(index)->SeDeplace();
                    break;

                case 'q' :
                    // Export des données dans un fichier xml
                    ofstream fichierMonde;
                    fichierMonde.open("../data/monde.xml");
                    fichierMonde << "<Monde>" << endl;

                    fichierMonde << "<Accessoires>" << endl;
                    for (int j = 0; j < listeAccessoires.size(); ++j) {
                        fichierMonde << listeAccessoires.at(j)->Exporter() << endl;
                    }
                    fichierMonde << "</Accessoires>" << endl;

                    fichierMonde << "<Soldats>" << endl;
                    for (int j = 0; j < listeSoldats.size(); ++j) {
                        fichierMonde << listeSoldats.at(j)->Exporter() << endl;
                    }
                    fichierMonde << "</Soldats>" << endl;

                    fichierMonde << "</Monde>" << endl;
                    fichierMonde.close();

                    cout << "Sauvegarde de la partie realisee avec succes !" << endl;
                    //Fin export

                    gameIsRunning = false;
                    cout << "=== FIN DU JEU ===" << endl;
                    break;
            }
        }

        while(kbhit()) getch();
    }

    delete m_Accessoire1;
    delete m_Accessoire2;
    delete m_Accessoire3;
    delete m_Soldat;
	delete m_Cavalier;
	delete m_Fantassin;
	delete m_Pilote;

	return 0;
}
