
#include <iostream>
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

	Pilote* m_Pilote = new Pilote("Jackie", 28, "Armée de l'air", "F-16");
	m_Pilote->SeDeplace();
	m_Pilote->Attaque();
	delete m_Pilote;

    Accessoire* m_Accessoire = new Accessoire("test", 3, "noir");
    m_Accessoire->ListerDetailsAccessoire();
    delete m_Accessoire;

    Fusil* m_Fusil = new Fusil("one", 2, "noir", 300);
    m_Fusil->ListerDetailsAccessoire();
    delete(m_Fusil);

	Casque* m_Casque = new Casque("two", 1, "vert", "leger");
	m_Casque->ListerDetailsAccessoire();
	delete(m_Casque);

	Gilet* m_Gilet = new Gilet("three", 15, "marron", 8);
	m_Gilet->ListerDetailsAccessoire();
	delete(m_Gilet);


	return 0;
}
