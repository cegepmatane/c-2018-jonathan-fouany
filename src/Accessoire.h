
#ifndef ACCESSOIRE_H
#define ACCESSOIRE_H
#include <iostream>

namespace std {

    class Accessoire {

    protected:
        string m_Nom;
        int m_Poids;
        string m_Couleur;
        int m_ValeurSupplementaire;
    public:
        Accessoire();
        Accessoire(string nom, int poids, string couleur, int valeurSupplementaire);
        virtual ~Accessoire();
        virtual void ListerDetailsAccessoire();
    };

}


#endif
