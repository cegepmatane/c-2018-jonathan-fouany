
#include <iostream>
#include <list>
#include "Soldat.h"
#include "Cavalier.h"
#include "Fantassin.h"
#include "Pilote.h"
#include "Accessoire.h"
#include "Fusil.h"
#include "Casque.h"
#include "Gilet.h"

using namespace std;



int main() {

	Fusil* m_Fusil = new Fusil("one", 2, "noir", 300);
    Casque* m_Casque = new Casque("two", 1, "vert", "leger");

	Soldat* m_Soldat = new Soldat("Dupont", 20, "infanterie", m_Fusil);
	m_Fusil->ListerDetailsAccessoire();
	m_Soldat->SeDeplace();
	m_Soldat->Attaque();

	delete m_Soldat;

	Soldat* m_Cavalier = new Cavalier("Dupond", 30, "cavalerie", "toto", m_Casque);
    m_Casque->ListerDetailsAccessoire();
    m_Cavalier->SeDeplace();
	m_Cavalier->Attaque();
	delete m_Cavalier;

	Fantassin* m_Fantassin = new Fantassin("Dupons", 40, "infanterie", "bernadette");
	m_Fantassin->SeDeplace();
	m_Fantassin->Attaque();
	delete m_Fantassin;

	Pilote* m_Pilote = new Pilote("Jackie", 28, "Armée de l'air", "F-16");
	m_Pilote->SeDeplace();
	m_Pilote->Attaque();
	delete m_Pilote;


	return 0;
}
