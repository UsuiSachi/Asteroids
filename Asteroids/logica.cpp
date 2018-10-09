#include "logica.h"

namespace Asteroids {
	namespace logica {
	enum pantallas { JUEGO, MENU, CREDITOS, GAME_OVER } pantalla_actual;
	bool juego_corriendo = true;
}
}

void inicio() {
	//instancia de la pantallaç
	int largo_pantalla = 800;
	int ancho_pantalla = 450;

	InitWindow(largo_pantalla, ancho_pantalla, "Asteroids-Godziela");

	while (juego_corriendo)
	{
		BeginDrawing();
		switch (pantalla_actual)
		{
		case JUEGO:
		{
			//Llamar a la pantalla juego
		}break;
		case MENU:
		{
			//Pantalla Menu
		}break;
		case CREDITOS:
		{
			//Pantalla Creditos
		}break;
		case GAME_OVER:
		{
			//Pantalla GAME OVER
		}break;
		}
		EndDrawing();
	}
}