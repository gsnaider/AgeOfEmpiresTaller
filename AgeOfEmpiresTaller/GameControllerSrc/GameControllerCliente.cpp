/*
 dibu * GameControllerCliente.cpp
 *
 *  Created on: 21 de oct. de 2015
 *      Author: andres
 */

#include "GameControllerCliente.h"

char* GameControllerCliente::string_to_char_array(string str) {
	int str_size = str.size();
	char charArray[PARAM_STRING_LEN];
	for (int a = 0; a <= str_size; a++) {
		charArray[a] = str[a];
	}
	return charArray;
}

GameControllerCliente::GameControllerCliente() {
}

GameControllerCliente::~GameControllerCliente() {
}
string GameControllerCliente::nombreJugador() {
	return this->juego->escenario->jugador->getNombre();
}
bool GameControllerCliente::esNombre(char* nombre) {
	return (!this->juego->escenario->jugador->getNombre().compare(nombre));
}

void GameControllerCliente::cambiar_destino_personaje(Id id, double mov_x,
		double mov_y) {

	msg_t mensaje;

	mensaje.type = MOVER_PERSONAJE;
	mensaje.paramDouble1 = mov_x;
	mensaje.paramDouble2 = mov_y;
	mensaje.paramInt1 = id;
	this->agregarMensaje(mensaje);

}

void GameControllerCliente::eliminarEntidad(int id) {
	this->modelo->eliminarEntidadPorID(id);
}
void GameControllerCliente::eliminar(int id) {
	this->modelo->eliminar(id);
}
void GameControllerCliente::mover_personaje(Id id, double mov_x, double mov_y) {
	this->modelo->cambiar_destino_personaje(id, mov_x, mov_y);
}
void GameControllerCliente::cambiar_personaje(int id_personaje, string nombre,
		string raza) {
	printf("Id personaje %d\n", id_personaje);
	printf("Nombre %s\n", nombre.c_str());
	printf("Raza %s\n", nombre.c_str());
	this->modelo->cambiar_personaje(id_personaje, nombre, raza);
}

void GameControllerCliente::crearPersonajeEdificio(string tipo, int id) {
	msg_t mensaje;
	mensaje.type = CREAR_PERSONAJE_EDIFICIO;
	memcpy(mensaje.paramNombre,
			string_to_char_array(this->modelo->nombreJugador()),
			sizeof(mensaje.paramNombre));
	memcpy(mensaje.paramTipo, string_to_char_array(tipo),
			sizeof(mensaje.paramTipo));
	mensaje.paramInt1 = id;
	this->agregarMensaje(mensaje);
}

void GameControllerCliente::ataque(Id idAtacante, Id idAtacado, int danio) {
	//aca crasheaba mal
	Personaje* pAtacando = this->modelo->get_Personaje_Por_Id(idAtacante);
	Personaje* p = this->modelo->get_Personaje_Por_Id(idAtacado);
	pAtacando->atacandoCliente(true);
	if (p) {
		p->recibirDanio(danio);
		if (!p->esta_vivo()) {
			pAtacando->atacandoCliente(false);
		}
	} else {
		Entidad * entidad = this->modelo->buscarEntidad(idAtacado);
		//no chequeo q sea null porque deberia existir
		entidad->recibirDanio(danio);
		if (!entidad->esta_vivo()) {
			pAtacando->atacandoCliente(false);
		}
	}

}

void GameControllerCliente::construir(Id idAtacante, Id idConstruido,
		int construccion) {
	Personaje* pConstructor = this->modelo->get_Personaje_Por_Id(idAtacante);
	Entidad * entidad = this->modelo->buscarEntidad(idConstruido);
	//no esta atacando pero esta accionando
	pConstructor->atacandoCliente(true);
	entidad->construir(construccion);
	if (entidad->estaConstruida()) {
		pConstructor->atacandoCliente(false);
	}
}

void GameControllerCliente::interactuar(Personaje* personaje, Posicion p) {
	//si no esta en rango no puede hacer nada
	if (this->modelo->afueraDelMapa(p.getX(), p.getY())) {
		return;
	}
	Personaje* otro_personaje = this->modelo->devolverPersonaje(p.getX(),
			p.getY());
	Entidad * otra_entidad = this->modelo->mapa->entidad_celda(p.getX(),
			p.getY());
	if (otro_personaje != NULL) {
		msg_t mensaje = personaje->interactuar(otro_personaje);
		this->agregarMensaje(mensaje);
		return;
	}

	if (otra_entidad != NULL) {
		msg_t msg = personaje->interactuar(otra_entidad);
		this->agregarMensaje(msg);
		return;
	}

}
void GameControllerCliente::eliminar_personaje(Id id) {
	this->modelo->eliminar_personaje_por_Id(id);
}
void GameControllerCliente::eliminarTodosPorNombre(string nombre_perdedor) {

	vector<Personaje*> personajes = this->modelo->devolverTodosLosPersonajes();
	vector<Personaje*>::iterator iter = personajes.begin();
	string razaPerdedora;
	for (; iter != personajes.end(); iter++) {
		Personaje* personaje = (*iter);
		if (personaje->getNombreJugador() == nombre_perdedor) {
			this->eliminar_personaje(personaje->getId());
			razaPerdedora = personaje->get_raza();
		}
	}

	this->meFijoSiPerdi(razaPerdedora);
}
void GameControllerCliente::eliminarTodos(string razaPerdedora) {

	vector<Personaje*> personajes = this->modelo->devolverTodosLosPersonajes();
	vector<Personaje*>::iterator iter = personajes.begin();
	string nombre_perdedor;

	for (; iter != personajes.end(); iter++) {
		Personaje* personaje = (*iter);
		if (personaje->get_raza() == razaPerdedora) {
			this->eliminar_personaje(personaje->getId());
			nombre_perdedor = personaje->getNombreJugador();
		}
	}

	this->meFijoSiPerdi(razaPerdedora);
}
void GameControllerCliente::meFijoSiPerdi(string razaPerdedora) {
	if (this->modelo->getJugador()->raza == razaPerdedora) {
		this->modelo->getJugador()->perdi = true;
		printf("Perdi\n");
		return;
		//mando mensaje
	}
	vector<Personaje*> personajes = this->modelo->devolverTodosLosPersonajes();
	vector<Personaje*>::iterator iter = personajes.begin();

	for (; iter != personajes.end(); iter++) {
		Personaje* personaje = (*iter);
		if (personaje->get_raza() != this->modelo->getJugador()->raza) {
			return;
		}
	}
	this->modelo->getJugador()->gane = true;
	printf("Gane\n");

}
void GameControllerCliente::setMapa(int ancho, int largo) {
	this->modelo->setMapa(largo, ancho);
}

void GameControllerCliente::setId(double x, double y, int id) {
	Entidad* entidad = this->modelo->mapa->entidad_celda(floor(x), floor(y));
	if (entidad != NULL) {
		entidad->setId(id);
	}
}

Personaje* GameControllerCliente::conectarCliente(string name, string tipo,
		int x, int y, int id) {
	printf("Entro\n");

	ObjetoMapa* obj = this->juego->tipos[tipo];
	Personaje* personaje = new Personaje(obj, x, y);
	personaje->setNombreJugador(name);
	personaje->setId(id);

	this->modelo->agregarPersonajeCliente(personaje);
	printf("Salio\n");
	return personaje;

}

void GameControllerCliente::agregarEntidad(string nombre, int x, int y,
		int cant) {
	this->modelo->agregarEntidad(nombre, x, y, cant);
}
void GameControllerCliente::acutalizarRecursos(string jugador, int id_personaje,
		int cant, int id_recurso) {
	this->modelo->actualizarRecursos(jugador, id_personaje, cant, id_recurso);
}
void GameControllerCliente::desconectar(string nombre) {
	//this->eliminarTodos(id);
	this->eliminarTodosPorNombre(nombre);
}

void GameControllerCliente::reconectar(string id) {
	this->modelo->descongelarPersonaje(id);
}
void GameControllerCliente::crearEdificio(string nombre, int id_constructor,
		int x, int y) {
	//manda al server a crear la entidad
	msg_t mensaje;
	mensaje.type = CREAR_ENTIDAD;
	memcpy(mensaje.paramNombre, string_to_char_array(nombre),
			sizeof(mensaje.paramNombre));
	mensaje.paramInt1 = id_constructor;
	mensaje.paramDouble1 = x;
	mensaje.paramDouble2 = y;
	this->agregarMensaje(mensaje);
}

void GameControllerCliente::empezarAccion(int id,Posicion donde_mira) {
	Personaje* personaje=this->modelo->get_Personaje_Por_Id(id);
	if(personaje!=NULL){
		personaje->atacandoCliente(true);
		personaje->setDondeMira(donde_mira);
	}
}

void GameControllerCliente::terminarAccion(int id) {
	if(this->modelo->get_Personaje_Por_Id(id)!=NULL)this->modelo->get_Personaje_Por_Id(id)->atacandoCliente(false);
}
void GameControllerCliente::finalizarConstruccion(int id) {
	Entidad * entidad = this->modelo->buscarEntidad(id);
	entidad->finalizarConstruccion();
}

bool GameControllerCliente::hayEventos() {
	return (!this->cola.empty());
}
msg_t GameControllerCliente::sacarMensaje() {
	msg_t mensaje = this->cola.front();
	this->cola.pop();
	return mensaje;
}
void GameControllerCliente::agregarMensaje(msg_t mensaje) {
	this->cola.push(mensaje);
}
