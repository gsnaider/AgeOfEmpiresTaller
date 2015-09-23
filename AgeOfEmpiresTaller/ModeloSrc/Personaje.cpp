/*
 * Personaje.cpp
 *
 *  Created on: 21 de set. de 2015
 *      Author: andres
 */

#include "Personaje.h"



Personaje::Personaje(){
	this->objetoMapa = new ObjetoMapa("protagonistaDefault", "img/protagonista/spartan.png");
	this->referencia_mapa_x=1;
	this->referencia_mapa_y=1;
	this->objetoMapa->fps = 20; //FPS DEFAULT
	this->velocidad=1;
	this->objetoMapa->delay = 0; //delay default
	this->dibujo = 0;
}
Personaje::Personaje(ObjetoMapa* objetoMapa){
	this->referencia_mapa_x=1;
	this->referencia_mapa_y=1;
	this->velocidad=1;
	this->objetoMapa = objetoMapa;
	this->dibujo = 0;
}
Personaje::Personaje(ObjetoMapa* objetoMapa, int x, int y){
	this->referencia_mapa_x=x;
	this->referencia_mapa_y=y;
	this->velocidad=1;
	this->objetoMapa = objetoMapa;
	this->dibujo = 0;
}
dibujo_t Personaje::dibujar(){
	return dibujo;
}
void Personaje::mover(int x,int y){
	double delta_x = (double) (x - referencia_mapa_x);
	double delta_y = (double) (y - referencia_mapa_y);
	double distancia = sqrt(delta_x * delta_x + delta_y * delta_y);
	if (distancia != 0) {
		if (distancia < velocidad) {
			distancia = velocidad;
		}
		double des_x = (velocidad * delta_x) / distancia;
		double des_y = (velocidad * delta_y) / distancia;
		if ((sqrt(des_x * des_x) > distancia)
				&& (sqrt(des_y * des_y) < distancia)) {
			this->referencia_mapa_x = x;
		}
		if ((sqrt(des_y * des_y) > distancia)
				&& ((sqrt(des_x * des_x) < distancia))) {
			this->referencia_mapa_y = y;
		}
		this->referencia_mapa_x += des_x;
		this->referencia_mapa_y += des_y;
	}

}

Personaje::~Personaje() {
	delete this->objetoMapa;
}
