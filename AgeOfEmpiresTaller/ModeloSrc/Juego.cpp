/*
 * Juego.cpp
 *
 *  Created on: 20/9/2015
 *      Author: ger
 */

#include "Juego.h"

Juego::Juego() {
	//configuracion default
	this->pantalla = new Pantalla();
	this->conf = new Configuracion();
	this->escenario = new Escenario();
	this->modo = MODO_DEFAULT;
	//cargarTiposDefault();
}
void Juego::cargarTiposDefault() {
	tipos["oro"] = new ObjetoMapa("oro", "img/oro.png");

	tipos["madera"] = new ObjetoMapa("madera", "img/madera.png");

	tipos["piedra"] = new ObjetoMapa("piedra", "img/piedra.png");

	tipos["comida"] = new ObjetoMapa("comida", "img/extras/comida.png");
}
Juego::Juego(Pantalla* pantalla, Configuracion* conf, Escenario* escenario, std::map<std::string, ObjetoMapa*> &tipos) {
	this->pantalla = pantalla;
	this->conf = conf;
	this->escenario = escenario;
	this->tipos = tipos;
	this->modo = MODO_DEFAULT;
	//cargarTiposDefault();

}

Entidad * Juego::centroCivicoDe(string raza) {
	map<string, ObjetoMapa*>::iterator it = this->tipos.begin();
	for (; it != this->tipos.end(); ++it) {
		//si el personaje es constructor y de la misma raza
		//su edificio constructor es el centro civico
		if (it->second->construccion > 0 && it->second->raza == raza) {
			Entidad * entidad = new Entidad(this->tipos[it->second->edificio_constructor]);
			return entidad;
		}
	}
	return NULL;
}
void Juego::setEscenario(string nombre, int ancho, int largo) {
	this->escenario->nombre = nombre;
	this->escenario->size_x = ancho;
	this->escenario->size_y = largo;
}
void Juego::setConfiguracion(int margenScroll, int velocidad_personaje) {
	this->conf->setMargenScroll(margenScroll);
	this->conf->setVelPersonaje(velocidad_personaje);
}
void Juego::agregarEntidad(string nombre, int x, int y) {
	Entidad* entidad;
	ObjetoMapa* objeto = this->tipos[nombre];
	if (nombre.compare("oro") == 0)
		entidad = new Oro(objeto, x, y);
	else if (nombre.compare("piedra") == 0)
		entidad = new Piedra(objeto, x, y);
	else if (nombre.compare("comida") == 0)
		entidad = new Comida(objeto, x, y);

	else if (nombre.compare("madera") == 0)
		entidad = new Madera(objeto, x, y);
	else
		entidad = new Entidad(objeto, x, y);
	this->escenario->entidades.push_back(entidad);
}

Juego::~Juego() {
	delete this->pantalla;
	delete this->conf;

	std::map<std::string, ObjetoMapa*>::iterator it;
	for (it = this->tipos.begin(); it != this->tipos.end(); it++) {
		delete it->second;
	}
	delete this->escenario;
}

