
#include "Casque.h"

namespace std {

    Casque::Casque(){}

    Casque::Casque(string a_Nom, int a_Poids, string a_Couleur, int a_Taille){
        m_Nom = a_Nom;
        m_Poids = a_Poids;
        m_Couleur = a_Couleur;
        m_Taille = a_Taille;
    }

    Casque::~Casque() {}

    void Casque::ListerDetailsAccessoire(){
        cout << "Casque: Poids: " << m_Poids << + "; Couleur : " + m_Couleur + "; Type : " << m_Taille << endl;
    }

}
