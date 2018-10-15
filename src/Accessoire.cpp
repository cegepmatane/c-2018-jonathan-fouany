
#include "Accessoire.h"

namespace std {

    Accessoire::Accessoire(){}

    Accessoire::Accessoire(string a_Nom, int a_Poids, string a_Couleur, int a_ValeurSupplementaire) {
        m_Nom = a_Nom;
        m_Poids = a_Poids;
        m_Couleur = a_Couleur;
        m_ValeurSupplementaire = a_ValeurSupplementaire;
    }

    Accessoire::~Accessoire(){}

    void Accessoire::ListerDetailsAccessoire(){
        cout << "Accessoire: " + m_Nom + "; poids: " << m_Poids << "; couleur: " + m_Couleur << "; valeur Supplementaire: " << m_ValeurSupplementaire << endl;
    }

}
