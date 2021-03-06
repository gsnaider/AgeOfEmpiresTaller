/*
 * Jugador.cpp
 *
 *  Created on: 25 de oct. de 2015
 *      Author: andres
 */

#include "Jugador.h"

Jugador::Jugador(string nombre,string raza) {
	// TODO Auto-generated constructor stub
	this->gane = false;
	this->perdi = false;
	this->raza=raza;
	this->nombre=nombre;
	this->recursos = new RecursosJugador(1200,1200,1200,1200);
	this->factory.setRaza(raza);

}
void Jugador::cargarEdificios(map<string,ObjetoMapa*> tipos){
	this->factory.cargarEdificios(tipos);
}

map<string,ObjetoMapa*> Jugador::devolverEdificiosCreables(){
	return this->factory.devolverTipos();
}
void Jugador::actualizarRecursos(int oro, int madera, int piedra, int comida){
	this->recursos->colectarOro(oro);
	this->recursos->colectarMadera(madera);
	this->recursos->colectarPiedra(piedra);
	this->recursos->colectarComida(comida);
}
void Jugador::pagar(Costo costo){
	this->recursos->pagar(costo);
}
bool Jugador::puedePagar(Costo costo){
	return this->recursos->puedePagar(costo);
}

Jugador::~Jugador() {
	delete this->recursos;
}

