#ifndef JUEGO_H
#define JUEGO_H
#include "logica.h"

class Jugador{
private:
	Vector2 _posicion;
	Vector2 _velocidad;
	float _aceleracion;
	float _rotacion;
	float _velocidad_default;
	int _puntuacion;
public:
	void set_posicion(Vector2 posicion);
	Vector2 get_posicion();
	void set_velocidad(Vector2 velocidad);
	Vector2 get_velocidad();
	void set_aceleracion(float aceleracion);
	float get_aceleracion();
	void set_rotacion(float rotacion);
	float get_rotacion();
	void set_velocidad_default(float velocidad_default);
	float get_velocidad_default();
	void set_puntuacion(int puntuacion);
	int get_puntuacion();
};

void juego();
namespace Asteroids {};
using namespace Asteroids::personaje;
#endif