
#include <sstream>
#include "Fantassin.h"

namespace std {

	Fantassin::Fantassin(){}

	Fantassin::Fantassin(string a_Nom, int a_Age, string a_Regiment, string a_Grenade, Accessoire *a_Accessoire){
		m_Nom = a_Nom;
		m_Age = a_Age;
		m_Regiment = a_Regiment;
		m_Grenade = a_Grenade;
		m_Accessoire = a_Accessoire;
	}

	Fantassin::~Fantassin() {}

	void Fantassin::SeDeplace(){
			cout << "Fantassin: " + m_Nom + " : Je me déplace à pied " << endl;
	}

	void Fantassin::Attaque(){
		cout << "Fantassin: " + m_Nom +  " : Grenade " + m_Grenade + "!"  << endl;
	}

	string Fantassin::Exporter(){
		stringstream xml;
		xml << "<Fantassin><nom>" << this->m_Nom << "</nom><age>" << this->m_Age << "</age><grenade>" << this->m_Grenade << "</grenade></Fantassin>";

		return xml.str();
	}

}
