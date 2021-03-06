/*
 * Escenario.h
 *
 *  Created on: 17/9/2015
 *      Author: ger
 */

#ifndef ESCENARIO_H_
#define ESCENARIO_H_
#include <string>
#include <map>
#include "Entidad.h"
#include "Personaje.h"
#include "Jugador.h"

using namespace std;
class Escenario {
public:
	Escenario();
	Escenario(string nombre, int size_x, int size_y);
	string nombre;
	Jugador* jugador;
	int size_x;
	int size_y;
	vector<Entidad*> entidades;
	Personaje* protagonista;
	Entidad* getTexturaDefault(int num);
	virtual ~Escenario();
};

#endif /* ESCENARIO_H_ */
