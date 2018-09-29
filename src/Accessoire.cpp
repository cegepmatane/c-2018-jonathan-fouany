
#include "Accessoire.h"

namespace std {

    Accessoire::Accessoire(){}

    Accessoire::Accessoire(string a_Nom, int a_Poids, string a_Couleur) {
        m_Nom = a_Nom;
        m_Poids = a_Poids;
        m_Couleur = a_Couleur;
    }

    Accessoire::~Accessoire(){}

    void Accessoire::ListerDetailsAccessoire(){
        cout << "Accessoire: " + m_Nom + "; poids: " << m_Poids << "; couleur: " + m_Couleur << endl;
    }

}
