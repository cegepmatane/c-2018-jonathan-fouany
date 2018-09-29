#include "Gilet.h"

namespace std {

    Gilet::Gilet(){}

    Gilet::Gilet(string a_Nom, int a_Poids, string a_Couleur, int a_Epaisseur){
        m_Nom = a_Nom;
        m_Poids = a_Poids;
        m_Couleur = a_Couleur;
        m_Epaisseur = a_Epaisseur;
    }

    Gilet::~Gilet() {}

    void Gilet::ListerDetailsAccessoire(){
        cout << "Gilet: Poids: " << m_Poids << + "; Couleur : " + m_Couleur + "; Epaisseur : " << m_Epaisseur << endl;
    }

}