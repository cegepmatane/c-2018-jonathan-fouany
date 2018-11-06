
#ifndef CASQUE_H
#define CASQUE_H
#include <iostream>
#include "Accessoire.h"

namespace std {

    class Casque : public Accessoire{
    private:
        string m_Taille;
    public:
        Casque();
        Casque(string nom, int poids, string couleur, int taille);
        virtual ~Casque();
        void ListerDetailsAccessoire();
        string Exporter();

    };

}



#endif
