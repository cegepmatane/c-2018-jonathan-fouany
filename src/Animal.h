/*
 * Animal.h
 *
 *  Created on: 26 sept. 2018
 *      Author: 1832527
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

namespace std {

class Animal {
public:
	Animal();
	virtual ~Animal();
	virtual void SeDeplace();
};

} /* namespace std */

#endif /* ANIMAL_H_ */
