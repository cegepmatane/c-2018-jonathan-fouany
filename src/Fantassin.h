
#ifndef FANTASSIN_H_
#define FANTASSIN_H_
#include <iostream>
#include "Soldat.h"

namespace std {

	class Fantassin : public Soldat{
		private:
			string m_Grenade;
		public:
			Fantassin();
			Fantassin(string nom, int age, string regiment, string grenade);
			virtual ~Fantassin();
			void SeDeplace();
			void Attaque();
		};

	}

#endif
