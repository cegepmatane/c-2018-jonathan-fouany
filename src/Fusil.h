
#ifndef FUSIL_H
#define FUSIL_H
#include <iostream>
#include "Accessoire.h"

namespace std {

    class Fusil : public Accessoire{
    private:
        int m_Portee;
    public:
        Fusil();
        Fusil(string nom, int poids, string couleur, int portee);
        virtual ~Fusil();
        void ListerDetailsAccessoire();
    };

}


#endif
