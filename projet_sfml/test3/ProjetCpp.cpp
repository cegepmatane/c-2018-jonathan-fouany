
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
//#include <afxres.h>
#include <thread>
#include <chrono>
#include "Soldat.h"
#include "Cavalier.h"
#include "Fantassin.h"
#include "Pilote.h"
#include "Accessoire.h"
#include "Fusil.h"
#include "Casque.h"
#include "Gilet.h"
#include <SFML/Graphics.hpp>

using namespace std;


int main() {


    // Lecture des donn�es pour les accessoires dans le fichier d'initialisation
    ifstream source;
    source.open("../data/init.csv");

    string ligne;

    string nom;
	int valeur1 = 0;
    string couleur;
    int valeur2 = 0;

    Accessoire* m_Accessoire1 = new Accessoire();
    Accessoire* m_Accessoire2 = new Accessoire();
    Accessoire* m_Accessoire3 = new Accessoire();
	delete m_Accessoire1;
	delete m_Accessoire2;
	delete m_Accessoire3;

	
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
    //Fin lecture des donn�es



	Soldat* m_Soldat = new Soldat("Dupont", 20, "infanterie", m_Accessoire1);
	Soldat* m_Cavalier = new Cavalier("Dupond", 30, "cavalerie", "toto", m_Accessoire2);
	Fantassin* m_Fantassin = new Fantassin("Francois", 40, "infanterie", "bernadette", m_Accessoire3);
	Pilote* m_Pilote = new Pilote("Jackie", 28, "Arm�e de l'air", "F-16", m_Accessoire1);


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
    cout << " Touche a : attaquer " << endl;
    cout << " Touche c : changer de personnage" << endl;
    cout << " Touche d : se deplacer en bas" << endl;
	cout << " Touche e : se deplacer en haut" << endl;
	cout << " Touche s : se deplacer a gauche" << endl;
	cout << " Touche f : se deplacer a droite" << endl;
    cout << " Touche t : tuer" << endl;
    cout << " Touche q : quitter" << endl;
    cout << " " << endl;
    cout << " Le jeu t'attend !" << endl;


	// ======= PARTIE GRAPHIQUE =======

	sf::RenderWindow window(sf::VideoMode(1300, 800), "Projet SFML");
	sf::Texture BackgroundTexture;
	sf::Sprite background;
	sf::Vector2u TextureSize;  //Added to store texture size.
	sf::Vector2u WindowSize;   //Added to store window size.

	if (!BackgroundTexture.loadFromFile("../data/fond.png")){
		return -1;
	}
	else{
		TextureSize = BackgroundTexture.getSize(); //Get size of texture.
		WindowSize = window.getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

		background.setTexture(BackgroundTexture);
		background.setScale(ScaleX, ScaleY);
	}

	int positionImageX = 825; int positionImageY = 530;

	sf::Texture textureCavalier;
	if (!textureCavalier.loadFromFile("../data/cavalier.png"))
	{
		return -1;
	}
	sf::Sprite imageCavalier(textureCavalier);
	imageCavalier.setScale(0.1f, 0.1f);
	imageCavalier.setPosition(positionImageX, positionImageY);

	sf::Texture texturePilote;
	if (!texturePilote.loadFromFile("../data/pilote.png"))
	{
		return -1;
	}
	sf::Sprite imagePilote(texturePilote);

	sf::Texture textureFantassin;
	if (!textureFantassin.loadFromFile("../data/fantassin.png"))
	{
		return -1;
	}
	sf::Sprite imageFantassin(textureFantassin);

	vector<sf::Sprite> listeImages;
	listeImages.push_back(imageCavalier);
	listeImages.push_back(imageFantassin);
	listeImages.push_back(imagePilote);

	int indexPourListeImage = 0;
    
    while(gameIsRunning || window.isOpen()){
        // PREMIER PROBLEME-SOLUTION : dormir sans occuper les ressources
        this_thread::sleep_for(chrono::milliseconds(1000/60));
        // SECOND PROBLEME-SOLUTION : lire les entr�es sans bloquer la boucle

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


        if(_kbhit()){

            touche = _getch(); // sors la premiere touche appuy�e
            //cout << "touche " << touche << " " << tour << endl;

            switch(touche){

                case 'a' :
                    // L'attaque enleve des 50 points au soldat suivant
                    if (listeSoldats.size() == 1){
                        cout << "Vous ne pouvez plus attaquer, car vous etes tout seul." << endl;
                        break;
                    }

                    listeSoldats.at(index)->Attaque();
                    cout << "Points de vie: "  << listeSoldats.at(index)->getM_PointsVie() << endl;
					cout << "" << endl;


                    if (index + 1 >= listeSoldats.size()) index = -1;
                    index++;

                    if (listeSoldats.at(index)->EstVivant()) {
                        listeSoldats.at(index)->setM_PointsVie(listeSoldats.at(index)->getM_PointsVie() - 50);
                        cout << listeSoldats.at(index)->getM_Nom() << " a plus que "
                             << listeSoldats.at(index)->getM_PointsVie() << " points de vie." << endl;
						cout << "" << endl;

                    }
                    else{
                        cout << listeSoldats.at(index)->getM_Nom() << " est mort ! " << endl;
                        listeSoldats.erase(listeSoldats.begin() + index);
                    }

                    index--;

                    break;


                case 'c' :
                    if (index >= listeSoldats.size() - 1) index = -1;
                    index++;
					indexPourListeImage++;
                    cout << listeSoldats.at(index)->getM_Nom() << ", points de vie : " << listeSoldats.at(index)->getM_PointsVie() << endl;
					cout << "" << endl;
                    break;

                case 's' : // � gauche
                    listeSoldats.at(index)->SeDeplace();
					positionImageX -= 10;
                    break;

				case 'f': // � droite
					listeSoldats.at(index)->SeDeplace();
					positionImageX += 10;
					break;

				case 'e': // en bas
					listeSoldats.at(index)->SeDeplace();
					positionImageY -= 10;
					break;

				case 'd': // en haut
					listeSoldats.at(index)->SeDeplace();
					positionImageY += 10;
					break;

                case 't' :
                    // Cette attaque tue directement le joueur suivant
                    if (listeSoldats.size() == 1){
                        cout << "Vous ne pouvez pas tuer, car vous etes tout seul." << endl;
                        break;
                    }

                    cout << listeSoldats.at(index)->getM_Nom() << ": J'attaque et je tue" << endl;
                    cout << "Points de vie: "  << listeSoldats.at(index)->getM_PointsVie() << endl;

                    if (index + 1 >= listeSoldats.size()) index = -1;

                    index++;
                    -- * listeSoldats.at(index);
                    cout << listeSoldats.at(index)->getM_Nom() << " est mort ! " << endl;
                    listeSoldats.erase(listeSoldats.begin() + index);
					listeImages.erase(listeImages.begin() + index);

                    index--;

                    break;

                case 'q' :
                    // Export des donn�es dans un fichier xml
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
                    cout << "" << endl;
                    //Fin export

                    gameIsRunning = false;
                    cout << "=== FIN DU JEU ===" << endl;
					window.close();
                    break;
            }
        }

        while(_kbhit()) _getch();

		window.clear();
		window.draw(background);
		listeImages.at(indexPourListeImage % listeImages.size()).setPosition(positionImageX, positionImageY);
		window.draw(listeImages.at(indexPourListeImage % listeImages.size()));
		window.display();

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
