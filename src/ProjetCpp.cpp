//============================================================================
// Name        : ProjetCpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Animal.h"
#include "Chien.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


	Animal m_Animal;
	m_Animal.SeDeplace();

	Chien m_Chien;
	m_Chien.SeDeplace();

	return 0;
}
