/*
 * DibujoPersonaje.h
 *
 *  Created on: 18 de set. de 2015
 *      Author: andres
 */

#ifndef DIBUJOPERSONAJE_H_
#define DIBUJOPERSONAJE_H_

#include "DibujoAnimado.h"
#include "vector"
#include "memory.h"
#define SDL_RECT rect
using namespace std;
class DibujoPersonaje: public DibujoAnimado {
	int velocidad;
	vector<SDL_Rect*> spriteClips;
	vector<size_t> cantidad_de_imagenes;
	size_t cant_mov;
	size_t movimiento_actual;

public:
	void set_cantidad_de_movimientos(size_t cant_de_mov);
	void set_cantidad_de_imagenes(size_t n_mov,size_t cant_de_imagenes);
	void set_imagen(size_t n_mov,size_t n_imagen, int x, int y, int ancho, int alto);
	void set_velocidad(int velocidad);
	DibujoPersonaje();
	void mover(int x, int y) ;
	void render( SDL_Renderer* renderer) ;
	void elegir_frame(double des_x,double des_y);
	virtual ~DibujoPersonaje();
};

#endif /* DIBUJOPERSONAJE_H_ */
