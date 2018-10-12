#include "juego.h"

namespace Asteroids {
	namespace personaje {
		//Variables para Jugador
		bool primer_juego = true;
		float aceleracion = 0.0f;
		Vector2 posicion_base = { 0,0 };
		int puntuacion = 0;
		float rotacion = 0.0f;
		Vector2 velocidad = { 0,0 };
		float velocidad_default = 0;
		float radio = 0.0f;
		int tiempo_de_vida;
	}
}

//https://gamemechanicexplorer.com/#thrust-1 esto es para ver el movimiento


Jugador crear_jugador() {
	Jugador p;
	p.aceleracion = aceleracion;
	p.posicion = posicion_base;
	p.puntuacion = puntuacion;
	p.rotacion = rotacion;
	p.velocidad = velocidad;
	p.velocidad_default = velocidad_default;

	return p;
}

Meteoro crear_meteoro() {
	Meteoro roca;
	roca.activo = false;
	roca.color = BROWN;
	roca.posicion = posicion_base;
	roca.radio = radio;
	roca.velocidad = velocidad;

	return roca;
}

Disparo crear_disparo() {
	Disparo pow;
	pow.activo = false;
	pow.color = BLACK;
	pow.tiempo_de_vida = tiempo_de_vida;
	pow.posicion = posicion_base;
	pow.radio = radio;
	pow.rotacion = rotacion;
	pow.velocidad = velocidad;

	return pow;
}

void juego() {
	if (primer_juego) {
		Jugador jugador = crear_jugador();
		for (int i = 0; i < METEOROS_MAX; i++) {
			//Inicialización de los meteoros
			Meteoro meteoros[METEOROS_MAX];
			meteoros[i] = crear_meteoro();
		}
		for (int i = 0; i < DISPAROS_MAX; i++) {
			//Inicialización de las balas
			Disparo balas[DISPAROS_MAX];
			balas[i] = crear_disparo();
		}
		primer_juego = false;
	}




}