
#include <iostream>
#include "Soldat.h"
#include "Cavalier.h"
#include "Fantassin.h"

using namespace std;



int main() {

	Soldat* m_Soldat = new Soldat("Dupont", 20, "infanterie");
	m_Soldat->SeDeplace();
	m_Soldat->Attaque();
	delete m_Soldat;

	Soldat* m_Cavalier = new Cavalier("Dupond", 30, "cavalerie", "toto");
	m_Cavalier->SeDeplace();
	m_Cavalier->Attaque();
	delete m_Cavalier;

	Fantassin* m_Fantassin = new Fantassin("Dupons", 40, "infanterie", "bernadette");
	m_Fantassin->SeDeplace();
	m_Fantassin->Attaque();
	delete m_Fantassin;

	return 0;
}
