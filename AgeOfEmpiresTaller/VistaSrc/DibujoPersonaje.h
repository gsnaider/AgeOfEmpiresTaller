/*
 * DibujoPersonaje.h
 *
 *  Created on: 18 de set. de 2015
 *      Author: andres
 */

#ifndef DIBUJOPERSONAJE_H_
#define DIBUJOPERSONAJE_H_
#include <SDL2/SDL_mixer.h>
#include "DibujoAnimado.h"
#include "vector"
#include "memory.h"
#include <cmath>
#include "../ModeloSrc/Contador.h"

#define SDL_RECT rect
#define CANTIDAD_DE_MOVIMIENTOS 8

enum movimientos {ABAJO,DIAGONAL_IZQUIERDA_ABAJO,IZQUIERDA, DIAGONAL_IZQUIERDA_ARRIBA ,ARRIBA ,DIAGONAL_DERECHA_ABAJO,DERECHA, DIAGONAL_DERECHA_ARRIBA };

using namespace std;
class DibujoPersonaje: public Dibujo {
	vector<SDL_Rect*> spriteClips;
	vector<int> cantidad_de_imagenes;
	Contador contador_musica;
	int cant_mov;
	int movimiento_actual;
	int acumulador;
	int fps;
	Mix_Chunk *musica;


public:
	void congelar();
	void descongelar();
	void setFps(int fps);
	void setMusic(string music);
	void set_cantidad_de_movimientos(int cant_de_mov);
	void set_cantidad_de_imagenes(int n_mov,int cant_de_imagenes);
	void set_imagen(int n_mov,int n_imagen, int x, int y, int ancho, int alto);
	DibujoPersonaje();
	int get_alto(int n_mov,int n_imagen);
	int get_ancho(int n_mov, int n_imagen);
	int get_alto();
	int get_ancho();
	int getMovimientoActual(){
		return movimiento_actual;
	}
	void playMusic();
	void setMovimientoActual(int mov){
		this->movimiento_actual = mov;
	}
	void render(SDL_Renderer* renderer);
	void elegir_frame(double des_x,double des_y);
	void cambiar_frame();
	void setPixeles(int x, int y);
	~DibujoPersonaje();
};

#endif /* DIBUJOPERSONAJE_H_ */
