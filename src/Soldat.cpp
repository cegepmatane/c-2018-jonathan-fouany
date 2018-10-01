

#include "Soldat.h"

namespace std {

	Soldat::Soldat(){}

	Soldat::Soldat(string a_Nom, int a_Age, string a_Regiment, Accessoire * a_Accessoire) {
		m_Nom = a_Nom;
		m_Age = a_Age;
		m_Regiment = a_Regiment;
		m_Accessoire = a_Accessoire;
	}

	Soldat::~Soldat() {}

	void Soldat::SeDeplace(){
		cout << "Soldat: " + m_Nom + " : Je me déplace" << endl;
	}

	void Soldat::Attaque(){
		cout << "Soldat: " + m_Nom + " : A l'attaque!" << endl;
	}

    Accessoire *Soldat::getM_Accessoire() const {
        return m_Accessoire;
    }

}
