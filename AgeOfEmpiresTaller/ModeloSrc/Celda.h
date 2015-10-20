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
	Entidad * devolver_entidad();
	Celda();
	bool estaOcupada();
	void setEscenario(dibujo_t dibujo);
	void setTiles(dibujo_t dibujo);
	void actualizar();
	void ocuparCeldaPersonaje(Personaje* personaje);
	bool tieneRecurso();
	dibujo_t dibujarEscenario();
	dibujo_t dibujarTiles();
	string mostrar_contenido();
	string mostrar_entidad();
	void ocuparCelda(Entidad*entidad);
	void liberarCelda();
	virtual ~Celda();
};

#endif /* CELDA_H_ */
