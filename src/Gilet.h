
#ifndef GILET_H
#define GILET_H
#include <iostream>
#include "Accessoire.h"

namespace std {

    class Gilet : public Accessoire{
    private:
        int m_Epaisseur;
    public:
        Gilet();
        Gilet(string nom, int poids, string couleur, int epaisseur);
        virtual ~Gilet();
        void ListerDetailsAccessoire();
    };

}


#endif
