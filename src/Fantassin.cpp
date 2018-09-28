
#include "Fantassin.h"

namespace std {

	Fantassin::Fantassin(){}

	Fantassin::Fantassin(string a_Nom, int a_Age, string a_Regiment, string a_Grenade){
		m_Nom = a_Nom;
		m_Age = a_Age;
		m_Regiment = a_Regiment;
		m_Grenade = a_Grenade;
	}

	Fantassin::~Fantassin() {}

	void Fantassin::SeDeplace(){
			cout << "Fantassin: " + m_Nom + " : Je me déplace à pied " << endl;
	}

	void Fantassin::Attaque(){
		cout << "Fantassin: " + m_Nom +  " : Grenade " + m_Grenade + "!"  << endl;
	}

}
