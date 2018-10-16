
#include <sstream>
#include "Pilote.h"

namespace std {

	Pilote::Pilote() {}

	Pilote::Pilote(string a_Nom, int a_Age, string a_Regiment, string a_Avion, Accessoire * a_Accessoire){
		m_Nom = a_Nom;
		m_Age = a_Age;
		m_Regiment = a_Regiment;
		m_Avion = a_Avion;
		m_Accessoire = a_Accessoire;
	}

	Pilote::~Pilote() {}


	void Pilote::SeDeplace(){
			cout << "Pilote: " + m_Nom + " : Je vole dans mon " + m_Avion << endl;
	}

	void Pilote::Attaque(){
		cout << "Pilote: " + m_Nom +  " : Je tire un missile"  << endl;
	}

	string Pilote::Exporter(){
		stringstream xml;
		xml << "<Pilote><nom>" << this->m_Nom << "</nom><age>" << this->m_Age << "</age><avion>" << this->m_Avion << "</avion></Pilote>";

		return xml.str();
	}

}
