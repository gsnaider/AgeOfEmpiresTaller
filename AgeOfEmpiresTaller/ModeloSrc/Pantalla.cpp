/*
 * Pantalla.cpp
 *
 *  Created on: 17/9/2015
 *      Author: ger
 */

#include "Pantalla.h"

Pantalla::Pantalla() {
	this -> ancho = 1024;
	this -> alto = 700;
}
Pantalla::Pantalla(int ancho, int alto){
	this -> ancho = ancho;
	this -> alto = alto;
}

Pantalla::~Pantalla() {
}

