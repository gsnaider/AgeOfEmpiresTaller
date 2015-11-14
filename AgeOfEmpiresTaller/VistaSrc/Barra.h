/*
 * BarraStatus.h
 *
 *  Created on: Oct 8, 2015
 *      Author: tobias
 */
#include <plog/Log.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <math.h>
#include "Dibujo.h"
#include "Minimapa.h"
#include "CambioDeCoordendas.h"
#include "RecursoVista.h"
#include "../ModeloSrc/Jugador.h"
#include <memory>
#include <sstream>
#ifndef BARRA_H_
#define BARRA_H_




class Barra: public Dibujo {
public:
	Barra(Modelo * modelo, double *x,double *y);
	void render(SDL_Renderer * renderer);
	void load(SDL_Renderer * renderer,string path, int ancho_por_celda, int alto_por_celda);
	void setDisplay(string display);
	void  actualizar(Jugador * jugador,vector<Personaje *> personajes,Entidad* entidad);
	void closeFont();
	void setListaCreables(map<string,ObjetoMapa*> tipos);
	string seleccionar(int pixel_x,int pixel_y);
	void imprimirLista(SDL_Renderer * renderer);
	int obtenerYDondeSeDibuja();
	virtual ~Barra();
private:
	void dibujarDondeMiro(SDL_Renderer* renderer);
	int imprimirNumeroDeRecurso(SDL_Renderer* renderer,shared_ptr<RecursoVista> recurso, int x_ref);
	void dimensionRectanguloDeMiniMapa(int ancho, int alto);
	void renderFondo(SDL_Renderer*renderer);
	void renderTexto(SDL_Renderer*renderer);
	bool cargarTexto(SDL_Renderer* renderer,SDL_Color color,shared_ptr<Textura> textura, string display);
	void imprimirTexto(int x, int y,SDL_Renderer* renderer,shared_ptr<Textura> textura);
	shared_ptr<Minimapa> mapa;
	shared_ptr<Textura> texto;
	shared_ptr<Textura> nombreJugador;
	shared_ptr<RecursoVista> oro;
	shared_ptr<RecursoVista> madera;
	shared_ptr<RecursoVista> piedra;
	shared_ptr<RecursoVista> comida;
	string nombre;
	double desfasaje;
	TTF_Font* font;
	string display;
	shared_ptr<CambioDeCoordendas> transformador;
	double *x_ref;
	double*y_ref;
	int celda_mini;
	int referencia_y;
	int tamFont;
	int ancho_por_celda;
	int alto_por_celda;
	int x_comienzo_recurso;
	map<string,ObjetoMapa*> listaCreables;
	bool seleccionable;
};

#endif /* BARRA_H_ */
