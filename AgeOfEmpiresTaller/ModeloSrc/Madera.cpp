/*
 * Madera.cpp
 *
 *  Created on: Sep 30, 2015
 *      Author: tobias
 */

#include "Madera.h"

void Madera::recolectar(RecursosJugador * recursos){
	recursos->colectarMadera(this->obtenerRecurso());
}

Madera::~Madera() {
	// TODO Auto-generated destructor stub
}
