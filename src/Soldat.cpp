

#include "Soldat.h"

namespace std {

Soldat::Soldat(){}

	Soldat::Soldat(string a_Nom, int a_Age, string a_Regiment) {
		m_Nom = a_Nom;
		m_Age = a_Age;
		m_Regiment = a_Regiment;
	}

	Soldat::~Soldat() {}

	void Soldat::SeDeplace(){
		cout << "Soldat: " + m_Nom + " : Je me d�place" << endl;
	}

	void Soldat::Attaque(){
		cout << "Soldat: " + m_Nom + " : A l'attaque!" << endl;
	}

}