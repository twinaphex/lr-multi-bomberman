#ifndef IS_OSX
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#else
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>
#endif

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <vector>
#include <algorithm>

#include "Player.h"
#include "Brain.h"
#include "BurnWall.h"
#include "SuddenDeathAnimation.h"

#ifndef __MYCLASS_GAME
#define __MYCLASS_GAME

enum keyPad {
	keyPadSelect = 1,
	keyPadL3 = 2,
	keyPadR3 = 4,
	keyPadStart = 8,
	keyPadUp = 16,
	keyPadRight = 32,
	keyPadDown = 64,
	keyPadLeft = 128,
	keyPadL2 = 256,
	keyPadR2 = 512,
	keyPadL1 = 1024,
	keyPadR1 = 2048,
	keyPadX = 4096,
	keyPadA = 8192,
	keyPadB = 16384,
	keyPadY = 32768
};

enum gameStateEnum {
	gameStart = 0, gamePause = 1, gameWait = 2, gameEnd = 3, generateResult = 4,
};

enum playerTypeEnum {
	HUMAN = 0, CPU = 1, OFF = 2
};

enum suddenDeathDirection {
	suddenDeathRight = 0, suddenDeathDown = 1, suddenDeathLeft = 2, suddenDeathUp = 3,
};

class Game {

	public:
		Game();
		Game(int levelIndexInformation, int playerInformation[16][2], int gameOption[4], SDL_Surface * vout_bufLibretro, unsigned short * in_keystateLibretro, int nbPlayerConfigGame);
		~Game();
		bool isAlive();
		bool isConfigured();
		bool isRequestStopGame();
		void tick();
		void startGame();
		void stopGame();
		void exitGame();
	private:
		//Font for Header and time remaining and pause message
		TTF_Font* fragileBombersFont;

		//sound
		Mix_Chunk *fireSound;
		Mix_Chunk *louisSound;
		Mix_Chunk *playerBurnSound;
		Mix_Chunk *playerKickSound;
		Mix_Chunk *bombeBounceSound;
		Mix_Chunk *endSound;

		//variable
		SDL_Thread * mainThread;
		SDL_Surface * screenBuffer;
		SDL_Surface * playerBombeExplode;
		SDL_Surface * overlay;
		SDL_Surface * overlayResult;

		//spite for animation
		SDL_Surface ** explosionSprite;
		SDL_Surface ** bombeSprite;
		SDL_Surface ** bonusSprite;
		SDL_Surface ** eggsSprite;
		SDL_Surface ** burnWallSprite;
		//sprite for header
		SDL_Surface ** headerPlayerSprite;

		//pointer in the libretro buffer
		SDL_Surface * vout_buf;

		//Game option variable
		int levelIndex;
		int cpuLevel;
		int nbTickForGame;
		int nbTickForGameParam;
		bool badBomber;
		int playerType[16];
		int playerIndexTexture[16];
		int playerScore[16];
		//functional variable
		int gameState;
		int nbPlayerAlive;
		int nbPlayerInGame;
		int nbPlayerConfig;
		bool isThreadAlive;
		bool requestStopGame;
		bool configured;

		//SUDDENT DEATH
		bool suddenDeath;
		bool suddenDeathCase;
		int suddenDeathMinX;
		int suddenDeathMaxX;
		int suddenDeathMinY;
		int suddenDeathMaxY;
		int suddenDeathX;
		int suddenDeathY;
		int suddenDeathDirection;

		//keystate of player
		unsigned short * in_keystate;
		unsigned short * in_keystate_cpu;

		//containers of object that can be put in the grid
		std::vector<Player *> players;
		std::vector<Bombe *> bombes;
		std::vector<Explosion *> explosions;
		std::vector<BurnWall *> burnWalls;
		std::vector<SuddenDeathAnimation *> suddenDeathAnimations;
		std::vector<Brain *> brains;

		/*
		 *	GRID PART
		 */
		//the grid generator
		Grid *grid;
		//table of free/occuped part of the grid
		int * tab;
		int * tabBonus;
		float * tabPlayerCoord;

		//function
		void copySurfaceToBackRenderer(SDL_Surface * src, SDL_Surface * dest, int x, int y);
		void mergeScreen(bool mergeResult);
		void generateHeader();
		void updateTimeDisplay();
		void drawResultOfGame();

};
#endif
