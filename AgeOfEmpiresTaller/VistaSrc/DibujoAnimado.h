/*
 * DibujoAnimado.h
 *
 *  Created on: 18 de set. de 2015
 *      Author: andres
 */

#ifndef DIBUJOANIMADO_H_
#define DIBUJOANIMADO_H_

#include "Dibujo.h"
#include "vector"
#include "memory.h"
using namespace std;
class DibujoAnimado: public Dibujo {
	SDL_Rect* spriteClips;
public:
	DibujoAnimado();
	virtual ~DibujoAnimado();
	void set_cantidad_de_imagenes(int cant_de_imagenes);
	void set_imagen(unsigned int n_imagen, int x, int y, int h, int w);
	void render( SDL_Renderer* gRenderer);
	void set_fps(int fps);
	int get_ancho(int n_imagen);
	int get_alto(int n_imagen);
	int get_ancho();
	int get_alto();
protected:

	void cambiar_frame();
	int fps;
	int acumulador;

};

#endif /* DIBUJOANIMADO_H_ */
