

#include <sstream>
#include "Soldat.h"

namespace std {

	Soldat::Soldat(){}

	Soldat::Soldat(string a_Nom, int a_Age, string a_Regiment, Accessoire * a_Accessoire) {
		m_Nom = a_Nom;
		m_Age = a_Age;
		m_Regiment = a_Regiment;
		m_PointsVie = 50;
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

    string Soldat::Exporter(){
        //export en xml
        stringstream xml;
        xml << "<Soldat><nom>" << this->m_Nom << "</nom></Soldat>";

        return xml.str();
    }

    void Soldat::operator--() {
		m_PointsVie = -100;
	}

	int Soldat::getM_PointsVie() const {
		return m_PointsVie;
	}

	void Soldat::setM_PointsVie(int m_PointsVie) {
		Soldat::m_PointsVie = m_PointsVie;
	}

	bool Soldat::EstVivant() {
		if (m_PointsVie <= 0) return false;
		else return true;
	}

	const string &Soldat::getM_Nom() const {
		return m_Nom;
	}

}
