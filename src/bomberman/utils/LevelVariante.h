#ifndef IS_OSX
#include <SDL2/SDL_mixer.h>
#else
#include <SDL2_mixer/SDL_mixer.h>
#endif

#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include "RailSwitch.h"

#define nbTypeBonus 15

#ifndef __MYCLASS_LevelVariante
#define __MYCLASS_LevelVariante

class LevelVariante {
	public:
		LevelVariante(int number, const char * descriptionLine1, const char * descriptionLine2, bool fillWithBrick, int definition[735], int bonus[13], int fireStrenght, int nbBombe);
		~LevelVariante();

		char getDefinition(int index);
		int getBonus(int index);
		bool isFillWithBricks();
		int getNumber();
		char * getDescriptionLine1();
		char * getDescriptionLine2();
		bool isReserved(int idx);
		int getStart(int idx);
		int getNbBombe();
		int getFireStrenght();
		void textureIsAWall(int idx);
		void textureIsAWall(int startIdx, int stopIdx);
		void texturedrawInsky(int idx);
		bool isAWall(int idx);
		bool isDrawInSky(int idx);
		void addRail(int index, RailSwitch * rail);
		void addRail(int index);
		void initRails();
		std::map<int, RailSwitch *> getRailsIndex();
		void addButton(int index);
		std::vector<int> getButtonsIndex();
		void addMine(int index);
		std::vector<int> getMinesIndex();
		void addHole(int index);
		std::vector<int> getHolesIndex();
		void addTeleporter(int index);
		std::vector<int> getTeleportersIndex();
		void addTrolley(int index);
		std::vector<int> getTrolleysIndex();
	private:
		int number;
		char descriptionLine1[32];
		char descriptionLine2[32];
		bool fillWithBrick;
		int definition[735];
		bool reserved[735];
		int start[16];
		int bonus[nbTypeBonus];
		int fireStrenght;
		int nbBombe;
		std::map<int, int> indexDefSky;
		std::map<int, int> indexDefWall;

		std::map<int, RailSwitch*> rails;
		std::vector<int> buttons;
		std::vector<int> holes;
		std::vector<int> mines;
		std::vector<int> teleporters;
		std::vector<int> trolleys;

};
#endif
