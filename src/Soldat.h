

#ifndef SOLDAT_H_
#define SOLDAT_H_

#include <iostream>
#include "Accessoire.h"

namespace std {

	class Soldat {

    protected:
			string m_Nom;
			int m_Age;
			string m_Regiment;
			int m_PointsVie;
            Accessoire * m_Accessoire;
	public:
			Soldat();
			Soldat(string nom, int age, string regiment, Accessoire *accessoire);
			virtual ~Soldat();
			virtual void SeDeplace();
			virtual void Attaque();
			virtual bool EstVivant();
            virtual string Exporter();

		int getM_PointsVie() const;

		void setM_PointsVie(int m_PointsVie);

		const string &getM_Nom() const;

		Accessoire *getM_Accessoire() const;

		void setM_Accessoire(Accessoire *m_Accessoire);
	};

}

#endif
