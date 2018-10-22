
#ifndef PILOTE_H_
#define PILOTE_H_
#include <iostream>
#include "Soldat.h"

namespace std {

	class Pilote : public Soldat{
		private:
			string m_Avion;
		public:
			Pilote();
			Pilote(string nom, int age, string regiment, string nomAvion, Accessoire *accessoire);
			virtual ~Pilote();
			void SeDeplace();
			void Attaque();
			string Exporter();

	};

	}

#endif
