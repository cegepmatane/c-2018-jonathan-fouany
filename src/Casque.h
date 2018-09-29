
#ifndef CASQUE_H
#define CASQUE_H
#include <iostream>
#include "Accessoire.h"

namespace std {

    class Casque : public Accessoire{
    private:
        string m_Type;
    public:
        Casque();
        Casque(string nom, int poids, string couleur, string type);
        virtual ~Casque();
        void ListerDetailsAccessoire();
    };

}



#endif
