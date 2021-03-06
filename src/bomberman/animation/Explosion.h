#ifndef IS_OSX
#include <SDL2/SDL_image.h>
#else
#include <SDL2_image/SDL_image.h>
#endif

#include <stdio.h>
#include "../Grid.h"
#include "../utils/Sprite.h"
#include "../utils/network/BomberNetServer.h"

#ifndef __MYCLASS_EXPLOSION
#define __MYCLASS_EXPLOSION

#define sizeX 35
#define sizeY 21

class Explosion {

	public:
		Explosion(int posX, int posY, int index, int tab[sizeX * sizeY]);
		Explosion(int posX, int posY, int index);
		~Explosion();
		void tick(SDL_Surface * surfaceToDraw);
		bool canBeDelete();

	private:
		int * tab;
		int posX;
		int posY;
		int idx;
		int indexExplosion;
		bool deleteAnimation;

		//for animation
		int frameCounter;
		int offsetSprite;
		int nbFrameForAnimation;
};
#endif
