
#ifndef CAVALIER_H_
#define CAVALIER_H_
#include <iostream>
#include "Soldat.h"

namespace std {

	class Cavalier : public Soldat {
		private:
			string m_NomCheval;
			int m_PointsVie;
		public:
			Cavalier();
			Cavalier(string nom, int age, string regiment, string nomCheval, Accessoire *accessoire);
			virtual ~Cavalier();
			void SeDeplace();
			void Attaque();
			string Exporter();

	};

	}

#endif
