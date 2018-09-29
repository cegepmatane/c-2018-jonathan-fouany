
#ifndef ACCESSOIRE_H
#define ACCESSOIRE_H
#include <iostream>

namespace std {

    class Accessoire {

    public:
        string m_Nom;
        int m_Poids;
        string m_Couleur;
        Accessoire();
        Accessoire(string nom, int poids, string couleur);
        virtual ~Accessoire();
        virtual void ListerDetailsAccessoire();
    };

}


#endif