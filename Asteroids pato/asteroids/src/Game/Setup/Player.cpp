#include "Player.h"

#include <cmath>
#include "Setup\Game.h"
#include "Setup\Asteroid.h"
#include "Setup\PlayerShoot.h"

namespace Juego
{
	static int defaultRotationSpeed = 280;
	static int defaultAcceleration = 1.0f;
	static int defaultDeacceleration = 0.01f;
	static int defaultBreakSpeed = 2.0f;
	rocketShip player;
	Circle collisionCircle;
	static const int playerBaseSize = 25;
	float shipHeight = (playerBaseSize / 2) / tanf(20 * DEG2RAD);
	float shipHeightv2 = (playerBaseSize / 2) / tanf(38 * DEG2RAD);

	static Rectangle shipSource = { 0.0f,0.0f, 50,50 };
	static Rectangle shipDestination;
	static Vector2 shipOrigin = { 25,40 };
	
	namespace Gameplay_Section
	{
		void createPlayer()
		{
			player.position = { (float)screenWidth / 2, (float)screenHeight / 2};
			player.score = 0;
			player.acceleration = 0;
			player.rotation = 0;
			player.speed = { 0.0f, 0.0f };
			player.defaultSpeed = 300.0f;

		}

		void createCollisionCircle()
		{
			collisionCircle.position.x = player.position.x;
			collisionCircle.position.y = player.position.y;
			collisionCircle.radius = 15;
			collisionCircle.speed = { 0,0 };
			collisionCircle.active = true;
		}
		
		void playerInput() //rotar nave con posicion de mouse getmouseY - asteroid position x calcular con cos y sin. 
		{
			ShootInput();

			if (IsKeyDown(KEY_LEFT)) player.rotation -= defaultRotationSpeed * GetFrameTime();
			if (IsKeyDown(KEY_RIGHT)) player.rotation += defaultRotationSpeed * GetFrameTime();

			// Player logic: acceleration
			if (IsKeyDown(KEY_UP))
			{
				if (player.acceleration < 1) player.acceleration += defaultAcceleration * GetFrameTime();
			}
			else
			{
				if (player.acceleration > defaultDeacceleration) player.acceleration -= defaultDeacceleration * GetFrameTime();
				else if (player.acceleration < defaultDeacceleration) player.acceleration = defaultDeacceleration;
			}
			if (IsKeyDown(KEY_DOWN))
			{
				if (player.acceleration > 0) player.acceleration -= defaultBreakSpeed * GetFrameTime();
				else if (player.acceleration < 0) player.acceleration = 0;
			}
		}

		void playerUpdate()
		{
			// Player logic: movement
			player.position.x += (player.speed.x*player.acceleration);
			player.position.y -= (player.speed.y*player.acceleration);

			// Player logic: speed

			player.speed.x = sin(player.rotation*DEG2RAD)*player.defaultSpeed * GetFrameTime();
			player.speed.y = cos(player.rotation*DEG2RAD)*player.defaultSpeed * GetFrameTime();
		}

		void collisionCircleUpdate()
		{
			// Players Collision Circle logic: movement
			collisionCircle.position.x = player.position.x + sinf(player.rotation*DEG2RAD)*(shipHeightv2);
			collisionCircle.position.y = player.position.y - cosf(player.rotation*DEG2RAD)*(shipHeightv2);
		}

		void playerDraw()
		{
			shipDestination = { player.position.x,player.position.y, 50,50 };

			Vector2 v1 = { player.position.x + sinf(player.rotation*DEG2RAD)*(shipHeight), player.position.y - cosf(player.rotation*DEG2RAD)*(shipHeight) };
			Vector2 v2 = { player.position.x - cosf(player.rotation*DEG2RAD)*(playerBaseSize / 2), player.position.y - sinf(player.rotation*DEG2RAD)*(playerBaseSize / 2) };
			Vector2 v3 = { player.position.x + cosf(player.rotation*DEG2RAD)*(playerBaseSize / 2), player.position.y + sinf(player.rotation*DEG2RAD)*(playerBaseSize / 2) };
			
			DrawTriangle(v1, v2, v3, MAROON);
			DrawTexturePro(ship, shipSource, shipDestination, shipOrigin, player.rotation, WHITE);
			
		}

		#ifdef TESTING
				void collisionCircleDraw() // only in DEBUG mode
				{
					DrawCircleV({ player.position.x + sinf(player.rotation*DEG2RAD)*(shipHeightv2), player.position.y - cosf(player.rotation*DEG2RAD)*(shipHeightv2) }, collisionCircle.radius, { 100, 0, 0, 200 });
				}
		#endif
		#ifdef RELEASE
				void collisionCircleDraw() // only in RELEASE mode
				{
					DrawCircleV({ player.position.x + sinf(player.rotation*DEG2RAD)*(shipHeightv2), player.position.y - cosf(player.rotation*DEG2RAD)*(shipHeightv2) }, collisionCircle.radius, { 0, 0, 0, 0 });
				}
		#endif
	}
}