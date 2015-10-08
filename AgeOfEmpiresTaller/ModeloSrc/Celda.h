/*
 * Celda.h
 *
 *  Created on: 29 de ago. de 2015
 *      Author: andres
 */
#include <iostream>
#include "Entidad.h"
#include "Personaje.h"
typedef int dibujo_t;
#define DEFAULT 0
#define AFUERA -1
#ifndef CELDA_H_
#define CELDA_H_

class Celda {
private:
	bool ocupada;
	dibujo_t tiles;
	dibujo_t escenario;
	Entidad* entidad;
	Personaje* personaje;
public:
	Personaje* devolver_personaje();
	Celda();
	bool estaOcupada();
	void setEscenario(dibujo_t dibujo);
	void setTiles(dibujo_t dibujo);
	void actualizar();
	void ocuparCeldaPersonaje(Personaje* personaje);
	dibujo_t dibujarEscenario();
	dibujo_t dibujarTiles();
	void mostrar_contenido();
	void ocuparCelda(Entidad*entidad);
	virtual ~Celda();
};

#endif /* CELDA_H_ */
