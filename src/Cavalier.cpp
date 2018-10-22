
#include <sstream>
#include "Cavalier.h"
namespace std {

	Cavalier::Cavalier(){}

	Cavalier::Cavalier(string a_Nom, int a_Age, string a_Regiment, string a_NomCheval, Accessoire *a_Accessoire) {
		m_Nom = a_Nom;
		m_Age = a_Age;
		m_Regiment = a_Regiment;
		m_NomCheval = a_NomCheval;
		m_PointsVie = 150;
		m_Accessoire = a_Accessoire;
	}

	Cavalier::~Cavalier() {}

	void Cavalier::SeDeplace(){
		cout << "Cavalier: " + m_Nom + " : Je galope sur " + m_NomCheval << endl;
	}

	void Cavalier::Attaque(){
		cout << "Cavalier: " + m_Nom +  " : J'attaque !" << endl;
	}

    string Cavalier::Exporter(){
        stringstream xml;
        xml << "<Cavalier><nom>" << this->m_Nom << "</nom><age>" << this->m_Age << "</age><regiment>" << this->m_Regiment << "</regiment></Cavalier>";

        return xml.str();
    }



}
