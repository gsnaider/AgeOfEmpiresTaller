/*
 * Dibujo.cpp
 *
 *  Created on: 6 de set. de 2015
 *      Author: andres
 */
/*
 * Dibujo.cpp
 *
 *  Created on: 6 de set. de 2015
 *      Author: andres
 */

#include "../VistaSrc/Dibujo.h"
#define ILUMINAR 150
#define RESET 255

Dibujo::Dibujo() {
	// TODO Auto-generated constructor stub
	shared_ptr <Textura> text(new Textura());
	this->textura = text;

}
void Dibujo::iluminar(){
	Uint8 alpha=127;
	this->textura->setAlpha(alpha);
}

void Dibujo::resetear(){
	this->textura->setAlpha(RESET);
}

void Dibujo::oscurecer(){
	this->textura->oscurecer();
}

void Dibujo::reiniciar(){
	this->textura->reiniciar();
}

void Dibujo::set_posicion_default(int x, int y){
	this->x_imagen=x;
	this->y_imagen=y;
}

bool Dibujo::cargar_archivo(std::string path, SDL_Renderer* renderer) {
	bool loadBool =  this->textura->loadFromFile(path, renderer);

	//this->spriteClips.h = this->textura->getHeight();
	//this->spriteClips.w = this->textura->getWidth();
	return loadBool;
}
int Dibujo::getHeight() {
	return this->textura->getHeight();
}
int Dibujo::getWidth() {
	return this->textura->getWidth();
}
Dibujo::~Dibujo() {
	// TODO Auto-generated destructor stub
}

int Dibujo::get_x() {
	return this->x_imagen;
}
int Dibujo::get_y() {
	return this->y_imagen;
}

int Dibujo::get_alto(){
	return spriteClips.h;
}

int Dibujo::get_ancho(){
	return spriteClips.w;
}







