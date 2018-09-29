
#include "Casque.h"

namespace std {

    Casque::Casque(){}

    Casque::Casque(string a_Nom, int a_Poids, string a_Couleur, string a_Type){
        m_Nom = a_Nom;
        m_Poids = a_Poids;
        m_Couleur = a_Couleur;
        m_Type = a_Type;
    }

    Casque::~Casque() {}

    void Casque::ListerDetailsAccessoire(){
        cout << "Casque: Poids: " << m_Poids << + "; Couleur : " + m_Couleur + "; Type : " << m_Type << endl;
    }

}
