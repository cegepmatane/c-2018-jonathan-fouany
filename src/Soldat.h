

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
            Accessoire * m_Accessoire;
	public:
			Soldat();
			Soldat(string nom, int age, string regiment, Accessoire *accessoire);
			virtual ~Soldat();
			virtual void SeDeplace();
			virtual void Attaque();
		};

}

#endif
