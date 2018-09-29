
#include "Fusil.h"

namespace std {

    Fusil::Fusil(){}

    Fusil::Fusil(string a_Nom, int a_Poids, string a_Couleur, int a_Portee){
        m_Nom = a_Nom;
        m_Poids = a_Poids;
        m_Couleur = a_Couleur;
        m_Portee = a_Portee;
    }

    Fusil::~Fusil() {}

    void Fusil::ListerDetailsAccessoire(){
        cout << "Fusil: " + m_Nom + "; Poids: " << m_Poids << + "; Couleur : " + m_Couleur + "; Portee : " << m_Portee << endl;
    }

}
