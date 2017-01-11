#include <time.h>

#include "Bomberman.h"

Bomberman::Bomberman(SDL_Surface * vout_bufLibretro) {
	Sprite::Instance();
	Sound::Instance();
	Sound::Instance().startMenuMusique();

	//Init TTF feature
	TTF_Init();

	srand (time(NULL));

	//color mask
Uint32 	rmask, gmask, bmask, amask;
	rmask = 0x00ff0000;
	gmask = 0x0000ff00;
	bmask = 0x000000ff;
	amask = 0xff000000;
	refreshBuffer = true;

	vout_buf = vout_bufLibretro;

	//Load Font
	fragileBombersFont = TTF_OpenFont("./resources/font/fragile_bombers.ttf", 16); //this opens a font style and sets a size

	//init all surface
	screenBuffer = SDL_CreateRGBSurface(0, 640, 360, 32, rmask, gmask, bmask, amask);

	copySurfaceToBackRenderer(Sprite::Instance().getSplashScreen(), screenBuffer, 0, 0);

	currentStep = home;

	//init default player type
	for (int i = 0; i < 16; i++) {
		playerType[i][0] = 1;
		playerType[i][1] = (rand() % 7);
	}
	playerType[0][0] = 0;
	playerType[0][1] = 0;

	//init GameOption
	gameOption[0] = 0;
	gameOption[1] = 0;
	gameOption[2] = 1;
	gameOption[3] = 3;
	game = NULL;
}

Bomberman::~Bomberman() {

	SDL_FreeSurface(screenBuffer);

	TTF_CloseFont(fragileBombersFont);
	TTF_Quit();
	if (game) {
		if (game->isConfigured()) {
			if (game->isAlive()) {
				game->exitGame();
			}
		}
		free(game);
	}
}

void Bomberman::tick(unsigned short in_keystateLibretro[16]) {
	//fprintf(stderr, "%u\n", in_keystate[0]);
	//color mask
	for (int i = 0; i < 16; i++) {
		in_keystate[i] = in_keystateLibretro[i];
	}

	if (currentStep != gameStep) {
		keyPressed();

		int nbPlayerConfig = 0;
		//spash screen and start pressed !
		if (previousPlayerKeystate[0] & keyPadStart && keychange[0]) {
			refreshBuffer = true;
			Sound::Instance().playValidSound();
			switch (currentStep) {
				case home:
					cursorPosition = 0;
					currentStep = PlayerTypeMenu;
					break;
				case PlayerTypeMenu:
					for (int i = 0; i < 16; i++) {
						if (playerType[i][0] == 1) {
							playerType[i][1] = (rand() % 7);
						}
					}
					cursorPosition = 0;
					currentStep = PlayerSpriteMenu;
					break;
				case PlayerSpriteMenu:
					cursorPosition = 0;
					currentStep = gameOptionMenu;
					break;
				case gameOptionMenu:
					cursorPosition = 0;
					currentStep = levelSelectionMenu;
					break;
				case levelSelectionMenu:
					cursorPosition = 0;
					nbPlayerConfig = 0;
					for (int i = 0; i < 16; i++) {
						if (playerType[i][0] <= 1) {
							nbPlayerConfig++;
						}
					}
					game = new Game(levelIndex, playerType, gameOption, vout_buf, in_keystate, nbPlayerConfig);
					currentStep = gameStep;

					Sound::Instance().stopMusique();
					Sound::Instance().startBattleMusique();
					//TODO

					break;
				case gameStep:
					break;
			}
		} else if (previousPlayerKeystate[0] & keyPadSelect && keychange[0]) {
			Sound::Instance().playCancelSound();
			refreshBuffer = true;
			switch (currentStep) {
				case home:
					cursorPosition = 0;
					break;
				case PlayerTypeMenu:
					cursorPosition = 0;
					currentStep = home;
					break;
				case PlayerSpriteMenu:
					cursorPosition = 0;
					currentStep = PlayerTypeMenu;
					break;
				case gameOptionMenu:
					cursorPosition = 0;
					currentStep = PlayerSpriteMenu;
					break;
				case levelSelectionMenu:
					cursorPosition = 0;
					currentStep = gameOptionMenu;
					break;
				case gameStep:
					cursorPosition = levelIndex;
					currentStep = levelSelectionMenu;
					break;
			}
		}

		switch (currentStep) {
			case home:
				if (refreshBuffer) {
					cursor.stopAnimation();
					SDL_BlitSurface(Sprite::Instance().getSplashScreen(), NULL, vout_buf, NULL);
					refreshBuffer = false;
				}
				break;
			case PlayerTypeMenu:
				cursor.startAnimation();
				drawPlayerTypeMenu();
				break;
			case PlayerSpriteMenu:
				cursor.stopAnimation();
				drawPlayerSpriteMenu();
				break;
			case gameOptionMenu:
				cursor.startAnimation();
				drawGameOptionMenu();
				break;
			case levelSelectionMenu:
				cursor.stopAnimation();
				drawLevelSelectionMenu();
				break;
			case gameStep:
				cursor.stopAnimation();
				if (refreshBuffer && previousPlayerKeystate[0] & keyPadStart && keychange[0]) {
					refreshBuffer = false;
				}
				break;
		}
	} else {
		if (game->isRequestStopGame()) {
			game->exitGame();
			free(game);
			game = NULL;
			cursorPosition = levelIndex;
			currentStep = levelSelectionMenu;
			Sound::Instance().stopMusique();
			Sound::Instance().startMenuMusique();
		}
	}
}

void Bomberman::copySurfaceToBackRenderer(SDL_Surface * src, SDL_Surface * dest, int x, int y) {
	SDL_Rect dstRect;
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = src->w;
	dstRect.h = src->h;
	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = src->w;
	srcRect.h = src->h;
	SDL_BlitSurface(src, &srcRect, dest, &dstRect);
}

/*
 * Select the type of player
 *
 *
 *
 *
 */
void Bomberman::drawPlayerTypeMenu() {
	Uint32 rmask, gmask, bmask, amask;
	rmask = 0x00ff0000;
	gmask = 0x0000ff00;
	bmask = 0x000000ff;
	amask = 0xff000000;

	//fprintf(stderr, "%d %d\n", refreshBuffer , keychange[0]);
	if (refreshBuffer || keychange[0]) {
		SDL_BlitSurface(Sprite::Instance().getMenuBackground(), NULL, screenBuffer, NULL);
		SDL_Surface* menu;

		menu = SDL_CreateRGBSurface(0, 574, 27, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(menu, NULL, SDL_MapRGBA(menu->format, 0, 0, 0, 120));
		copySurfaceToBackRenderer(menu, screenBuffer, 33, 150);
		SDL_FreeSurface(menu);

		menu = SDL_CreateRGBSurface(0, 574, 100, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(menu, NULL, SDL_MapRGBA(menu->format, 0, 0, 0, 120));
		copySurfaceToBackRenderer(menu, screenBuffer, 33, 183);
		SDL_FreeSurface(menu);

		SDL_Color red = { 255, 0, 0 };
		SDL_Color green = { 0, 255, 0 };
		SDL_Color blue = { 0, 140, 255 };

		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, "Configuration joueur", green);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, ((640 / 2) - (surfaceMessage->w / 2)), 154);
		SDL_FreeSurface(surfaceMessage);

		if (previousPlayerKeystate[0] & keyPadRight && keychange[0]) {
			cursorPosition += 4;
			Sound::Instance().playBipSound();
			if (cursorPosition > 15) {
				cursorPosition = cursorPosition % 4;
			}
		}
		if (previousPlayerKeystate[0] & keyPadLeft && keychange[0]) {
			cursorPosition -= 4;
			Sound::Instance().playBipSound();
			if (cursorPosition < 0) {
				cursorPosition += 16;
			}
		}
		if (previousPlayerKeystate[0] & keyPadDown && keychange[0]) {
			cursorPosition++;
			Sound::Instance().playBipSound();
			if (cursorPosition > 15) {
				cursorPosition = 0;
			}
		}
		if (previousPlayerKeystate[0] & keyPadUp && keychange[0]) {
			cursorPosition--;
			Sound::Instance().playBipSound();
			if (cursorPosition < 0) {
				cursorPosition = 15;
			}
		}
		if (previousPlayerKeystate[0] & keyPadA && keychange[0]) {
			playerType[cursorPosition][0]++;
			Sound::Instance().playBipSound();
			if (playerType[cursorPosition][0] > 2) {
				playerType[cursorPosition][0] = 0;
			}
		}
		if (previousPlayerKeystate[0] & keyPadB && keychange[0]) {
			playerType[cursorPosition][0]--;
			Sound::Instance().playBipSound();
			if (playerType[cursorPosition][0] < 0) {
				playerType[cursorPosition][0] = 2;
			}
		}

		//player 0 always Human
		playerType[0][0] = 0;

		SDL_Surface* surfaceMessage1;
		SDL_Surface* surfaceMessage2;
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				char playerName[15] = "Joueur ";
				char playerTypeName[6];
				sprintf(playerName, "Joueur %2i : ", (j * 4 + i) + 1);

				SDL_Color playerColor = blue;
				switch (playerType[j * 4 + i][0]) {
					case HUMAN:
						sprintf(playerTypeName, "HUMAN");
						playerColor = blue;
						break;
					case CPU:
						sprintf(playerTypeName, "CPU");
						playerColor = green;
						break;
					case OFF:
						sprintf(playerTypeName, "OFF");
						playerColor = red;
						break;
				}
				surfaceMessage1 = TTF_RenderText_Solid(fragileBombersFont, playerTypeName, playerColor);
				surfaceMessage2 = TTF_RenderText_Solid(fragileBombersFont, playerName, green);
				copySurfaceToBackRenderer(surfaceMessage1, screenBuffer, 123 + (j * 133), 187 + (i * 20));
				copySurfaceToBackRenderer(surfaceMessage2, screenBuffer, 56 + (j * 133), 187 + (i * 20));
				SDL_FreeSurface(surfaceMessage1);
				SDL_FreeSurface(surfaceMessage2);
			}
		}
		refreshBuffer = false;
	}
	int cursorPosX = 36 + (((cursorPosition - (cursorPosition % 4)) / 4) * 133);
	int cursorposY = 187 + ((cursorPosition % 4) * 20);
	copySurfaceToBackRenderer(screenBuffer, vout_buf, 0, 0);
	copySurfaceToBackRenderer(cursor.getCurrentFrame(), vout_buf, cursorPosX, cursorposY);
}

/*
 * Menu for selecting the sprite of a player
 *
 *
 *
 *
 */
void Bomberman::drawPlayerSpriteMenu() {

	if (refreshBuffer || anyPlayerkeychange) {
		Uint32 rmask, gmask, bmask, amask;
		rmask = 0x00ff0000;
		gmask = 0x0000ff00;
		bmask = 0x000000ff;
		amask = 0xff000000;

		SDL_BlitSurface(Sprite::Instance().getMenuBackground(), NULL, screenBuffer, NULL);
		SDL_Surface* menu;
		menu = SDL_CreateRGBSurface(0, 574, 27, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(menu, NULL, SDL_MapRGBA(menu->format, 0, 0, 0, 120));
		copySurfaceToBackRenderer(menu, screenBuffer, 33, 150);
		SDL_FreeSurface(menu);

		menu = SDL_CreateRGBSurface(0, 574, 150, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(menu, NULL, SDL_MapRGBA(menu->format, 0, 0, 0, 120));
		copySurfaceToBackRenderer(menu, screenBuffer, 33, 183);
		SDL_FreeSurface(menu);

		SDL_Color green = { 0, 255, 0 };
		SDL_Color blue = { 0, 140, 255 };

		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, "SELECT COSTUME", green);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, ((640 / 2) - (surfaceMessage->w / 2)), 154);

		//add player sprite
		for (int i = 0; i < 8; i++) {
			copySurfaceToBackRenderer(Sprite::Instance().playerDrawNormal(i,0,0,0), screenBuffer, 54 + (i * 72), 174);
		}

		for (int i = 0; i < 16; i++) {
			if (previousPlayerKeystate[i] & keyPadRight && keychange[i]) {
				playerType[i][1] = playerType[i][1] + 1;
				Sound::Instance().playBipSound();
				if (playerType[i][1] > 7) {
					playerType[i][1] = 0;
				}
			}
			if (previousPlayerKeystate[i] & keyPadLeft && keychange[i]) {
				playerType[i][1] = playerType[i][1] - 1;
				Sound::Instance().playBipSound();
				if (playerType[i][1] < 0) {
					playerType[i][1] = 7;
				}
			}
		}

		int list[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		for (int i = 0; i < 16; i++) {
			if (playerType[i][0] != OFF) {
				int index = playerType[i][1];
				char playerName[10];
				SDL_Color playerColor = blue;
				switch (playerType[i][0]) {
					case HUMAN:
						sprintf(playerName, "HUMAN %i", i + 1);
						playerColor = blue;
						break;
					case CPU:
						sprintf(playerName, "CPU %i", i + 1);
						playerColor = green;
						break;
					case OFF:
						break;
				}
				SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, playerName, playerColor);
				copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 70 + (playerType[i][1] * 72) - (surfaceMessage->w / 2), 216 + (15 * list[index]));
				list[index] = list[index] + 1;
				SDL_FreeSurface(surfaceMessage);
			}
		}
		refreshBuffer = false;
		copySurfaceToBackRenderer(screenBuffer, vout_buf, 0, 0);
	}
}

/*
 * Menu for gameStep option
 *
 *
 *
 *
 */
void Bomberman::drawGameOptionMenu() {
	if (refreshBuffer || keychange[0]) {
		Uint32 rmask, gmask, bmask, amask;
		rmask = 0x00ff0000;
		gmask = 0x0000ff00;
		bmask = 0x000000ff;
		amask = 0xff000000;

		if (previousPlayerKeystate[0] & keyPadRight && keychange[0]) {
			Sound::Instance().playBipSound();
			switch (cursorPosition) {
				case suddenDeathOption:
				case badBomberOption:
					if (gameOption[cursorPosition] == 0) {
						gameOption[cursorPosition] = 1;
					} else {
						gameOption[cursorPosition] = 0;
					}
					break;
				case cpuLevelOption:
					gameOption[cursorPosition] = gameOption[cursorPosition] + 1;
					if (gameOption[cursorPosition] < 1) {
						gameOption[cursorPosition] = 5;
					} else if (gameOption[cursorPosition] > 5) {
						gameOption[cursorPosition] = 1;
					}
					break;
				case timeLevelOption:
					gameOption[cursorPosition] = gameOption[cursorPosition] + 1;
					if (gameOption[cursorPosition] > 6) {
						gameOption[cursorPosition] = -1;
					} else if (gameOption[cursorPosition] == 0) {
						gameOption[cursorPosition] = 2;
					}
					break;
			}
		}
		if (previousPlayerKeystate[0] & keyPadLeft && keychange[0]) {
			Sound::Instance().playBipSound();
			switch (cursorPosition) {
				case suddenDeathOption:
				case badBomberOption:
					if (gameOption[cursorPosition] == 0) {
						gameOption[cursorPosition] = 1;
					} else {
						gameOption[cursorPosition] = 0;
					}
					break;
				case cpuLevelOption:
					gameOption[cursorPosition] = gameOption[cursorPosition] - 1;
					if (gameOption[cursorPosition] < 1) {
						gameOption[cursorPosition] = 5;
					} else if (gameOption[cursorPosition] > 5) {
						gameOption[cursorPosition] = 1;
					}
					break;
				case timeLevelOption:
					gameOption[cursorPosition] = gameOption[cursorPosition] - 1;
					if (gameOption[cursorPosition] == 1) {
						gameOption[cursorPosition] = -1;
					} else if (gameOption[cursorPosition] == -2) {
						gameOption[cursorPosition] = 6;
					}
					break;

			}
		}
		if (previousPlayerKeystate[0] & keyPadDown && keychange[0]) {
			Sound::Instance().playBipSound();
			cursorPosition++;
			if (cursorPosition > 3) {
				cursorPosition = 0;
			}
		}
		if (previousPlayerKeystate[0] & keyPadUp && keychange[0]) {
			Sound::Instance().playBipSound();
			cursorPosition--;
			if (cursorPosition < 0) {
				cursorPosition = 3;
			}
		}

		SDL_BlitSurface(Sprite::Instance().getMenuBackground(), NULL, screenBuffer, NULL);
		SDL_Surface* menu;
		menu = SDL_CreateRGBSurface(0, 574, 27, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(menu, NULL, SDL_MapRGBA(menu->format, 0, 0, 0, 120));
		copySurfaceToBackRenderer(menu, screenBuffer, 33, 150);
		SDL_FreeSurface(menu);

		menu = SDL_CreateRGBSurface(0, 574, 100, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(menu, NULL, SDL_MapRGBA(menu->format, 0, 0, 0, 120));
		copySurfaceToBackRenderer(menu, screenBuffer, 33, 183);
		SDL_FreeSurface(menu);

		SDL_Color red = { 255, 0, 0 };
		SDL_Color green = { 0, 255, 0 };
		SDL_Color blue = { 0, 140, 255 };

		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, "GAME OPTION", green);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, ((640 / 2) - (surfaceMessage->w / 2)), 154);
		SDL_FreeSurface(surfaceMessage);

		surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, "Sudden Death", green);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 200, 187);
		SDL_FreeSurface(surfaceMessage);
		surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, "Bad Bomber", green);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 200, 207);
		SDL_FreeSurface(surfaceMessage);
		surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, "CPU Level", green);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 200, 227);
		SDL_FreeSurface(surfaceMessage);
		surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, "Time", green);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 200, 247);
		SDL_FreeSurface(surfaceMessage);

		surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, gameOption[0] == 1 ? "ON" : "OFF", gameOption[0] == 1 ? green : red);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 400, 187);
		SDL_FreeSurface(surfaceMessage);
		surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, gameOption[1] == 1 ? "ON" : "OFF", gameOption[1] == 1 ? green : red);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 400, 207);
		SDL_FreeSurface(surfaceMessage);

		char CPULevel[2];
		sprintf(CPULevel, "%i", gameOption[2]);
		surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, CPULevel, blue);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 400, 227);
		SDL_FreeSurface(surfaceMessage);

		char timeOfLevel[7];
		if (gameOption[3] != -1) {
			sprintf(timeOfLevel, "%i", gameOption[3]);
		} else {
			sprintf(timeOfLevel, "infini");
		}
		surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, timeOfLevel, blue);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, 400, 247);
		SDL_FreeSurface(surfaceMessage);
		refreshBuffer = false;
	}
	int cursorPosX = 183;
	int cursorposY = 187 + (cursorPosition * 20);
	copySurfaceToBackRenderer(screenBuffer, vout_buf, 0, 0);
	copySurfaceToBackRenderer(cursor.getCurrentFrame(), vout_buf, cursorPosX, cursorposY);
}

/*
 * Menu for level selection
 * 
 * 
 * 
 * 
 */
void Bomberman::drawLevelSelectionMenu() {
	if (refreshBuffer || keychange[0]) {
		Uint32 rmask, gmask, bmask, amask;
		rmask = 0x00ff0000;
		gmask = 0x0000ff00;
		bmask = 0x000000ff;
		amask = 0xff000000;
		SDL_BlitSurface(Sprite::Instance().getMenuBackground(), NULL, screenBuffer, NULL);
		SDL_Surface* menu;
		menu = SDL_CreateRGBSurface(0, 574, 27, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(menu, NULL, SDL_MapRGBA(menu->format, 0, 0, 0, 120));
		copySurfaceToBackRenderer(menu, screenBuffer, 33, 150);
		SDL_FreeSurface(menu);

		menu = SDL_CreateRGBSurface(0, 574, 150, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(menu, NULL, SDL_MapRGBA(menu->format, 0, 0, 0, 120));
		copySurfaceToBackRenderer(menu, screenBuffer, 33, 183);

		//SDL_Color red = {255, 0, 0};
		SDL_Color green = { 0, 255, 0 };
		//SDL_Color blue = {0, 140, 255};

		//menuLevelSprite

		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(fragileBombersFont, "SELECT THE LEVEL", green);
		copySurfaceToBackRenderer(surfaceMessage, screenBuffer, ((640 / 2) - (surfaceMessage->w / 2)), 154);

		if (previousPlayerKeystate[0] & keyPadRight && keychange[0]) {
			Sound::Instance().playBipSound();
			cursorPosition++;
			if (cursorPosition > nbLevel - 1) {
				cursorPosition = 0;
			}

		}
		if (previousPlayerKeystate[0] & keyPadLeft && keychange[0]) {
			Sound::Instance().playBipSound();
			cursorPosition--;
			if (cursorPosition < 0) {
				cursorPosition = nbLevel - 1;
			}
		}

		copySurfaceToBackRenderer(Sprite::Instance().getLevelPreview(cursorPosition), screenBuffer, ((640 / 2) - (levelPreviewSizeWidth / 2)), 200);

		refreshBuffer = false;
		SDL_FreeSurface(menu);
		SDL_FreeSurface(surfaceMessage);
		levelIndex = cursorPosition;
	}
	copySurfaceToBackRenderer(screenBuffer, vout_buf, 0, 0);
}

void Bomberman::keyPressed() {
	int index = 0;
	anyPlayerkeychange = false;
	for (int i = 0; i < 16; i++) {
		if (playerType[i][0] == 0) {
			if (previousPlayerKeystate[i] != in_keystate[index]) {
				keychange[i] = true;
				anyPlayerkeychange = true;
				previousPlayerKeystate[i] = in_keystate[index];
			} else {
				keychange[i] = false;
			}
			index++;
		} else {
			keychange[i] = false;
		}
	}
}
