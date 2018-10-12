#ifndef JUEGO_H
#define JUEGO_H
#include "logica.h"
#include <math.h>
#define METEOROS_MAX 15
#define DISPAROS_MAX 5

struct Jugador {
	Vector2 posicion;
	Vector2 velocidad;
	//Triángulo
	Vector2 v1;
	Vector2 v2;
	Vector2 v3;
	//
	float aceleracion;
	float rotacion;
	float velocidad_default;
	int puntuacion;
};

struct Disparo {
	Vector2 posicion;
	Vector2 velocidad;
	float radio;
	float rotacion;
	int tiempo_de_vida;
	bool activo;
	Color color;
};

struct Meteoro {
	Vector2 posicion;
	Vector2 velocidad;
	float radio;
	bool activo;
	Color color;
};

void juego();
namespace Asteroids {};
using namespace Asteroids::personaje;
#endif