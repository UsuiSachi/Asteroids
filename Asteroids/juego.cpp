#include "juego.h"

namespace Asteroids {
	namespace personaje {
	//Variables para Jugador
	bool primer_juego = true;
	float aceleracion = 0.0f;
	Vector2 posicion = {0,0};
	int puntuacion = 0;
	float rotacion = 0.0f;
	Vector2 velocidad = {0,0};
	float velocidad_default = 0;
	
}
}

Jugador* crear_jugador(float aceleracion, Vector2 posicion,
	int puntuacion, float rotacion, Vector2 velocidad, float velocidad_default) {
	Jugador* p = new Jugador();
	p->set_aceleracion(aceleracion);
	p->set_posicion(posicion);
	p->set_puntuacion(puntuacion); 
	p->set_rotacion(rotacion);
	p->set_velocidad(velocidad);
	p->set_velocidad_default(velocidad_default);

	return p;
}
//https://gamemechanicexplorer.com/#thrust-1 esto es para ver el movimiento


void juego() {
	if (primer_juego) {
		crear_jugador(aceleracion,posicion,puntuacion,
			rotacion,velocidad,velocidad_default);
		primer_juego = false;
	}
	



}