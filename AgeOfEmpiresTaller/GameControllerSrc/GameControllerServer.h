/*
 * GameControllerServer.h
 *
 *  Created on: 21 de oct. de 2015
 *      Author: andres
 */
#include "../GameControllerSrc/GameController.h"

#ifndef GAMECONTROLLERSRC_GAMECONTROLLERSERVER_H_
#define GAMECONTROLLERSRC_GAMECONTROLLERSERVER_H_

class GameControllerServer:public GameController{
public:
	GameControllerServer();
	 ~GameControllerServer();
	void insertarModelo(Modelo* modelo);
	void setMapa(int ancho, int largo);
	void setDibujoMapa(vector<vector<dibujo_t>> escenario,
			vector<vector<dibujo_t>> tiles);
	void conectar();
	void cambiar_destino_personaje(string id, double mov_x, double mov_y);
	void eliminarEntidad(int id);
	void agregarEntidad(string nombre,int x, int y, int cant);
	void inicializacion();
	//server
	void reconectar(std::string id);
	void desconectar(std::string id);
	//void reconectar(int id);
	void agregarCliente(string name,string tipo);
	void generarRecursoRandom();
	//void desconectar(int id);
	void actualizar();
	char* string_to_char_array(string str);
	bool hayEventosInicializacion();
	msg_t nextEventoInicializacion();
	void agregarEventoInicializacion(msg_t mensaje);

private:
	queue <msg_t> colaInicializacion;
};

#endif /* GAMECONTROLLERSRC_GAMECONTROLLERSERVER_H_ */
