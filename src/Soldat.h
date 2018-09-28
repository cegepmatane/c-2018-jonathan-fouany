

#ifndef SOLDAT_H_
#define SOLDAT_H_

#include <iostream>

namespace std {

	class Soldat {

		public:
			string m_Nom;
			int m_Age;
			string m_Regiment;
			Soldat();
			Soldat(string nom, int age, string regiment);
			virtual ~Soldat();
			virtual void SeDeplace();
			virtual void Attaque();
		};

}

#endif
