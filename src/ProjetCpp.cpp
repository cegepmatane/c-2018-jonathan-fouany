
#include <iostream>
#include "Soldat.h"
#include "Cavalier.h"
using namespace std;



int main() {

	Soldat* m_Soldat = new Soldat("Dupont", 20, "cavalerie");
	m_Soldat->SeDeplace();
	m_Soldat->Attaque();
	delete m_Soldat;

	Soldat* m_Cavalier = new Cavalier("Dupond", 30, "cavalerie", "toto");
	m_Cavalier->SeDeplace();
	m_Cavalier->Attaque();
	delete m_Cavalier;

	return 0;
}
