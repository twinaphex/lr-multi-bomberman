#include "Brain.h"

Brain::Brain(unsigned short * keystate, int tab[sizeX * sizeY], float * tabPlayerCoord, int nbPlayerConfig, int playerNumberControle, int posX, int posY) {
	this->keystate = keystate;
	this->tab = tab;
	this->tabPlayerCoord = tabPlayerCoord;
	this->nbPlayerConfig = nbPlayerConfig;
	this->playerNumberControle = playerNumberControle;
	this->posX = posX;
	this->posY = posY;
	nbTick = 0;
	astar = new AStar(tab);
}

Brain::~Brain() {
	free (astar);
	keystate = NULL;
	tab = NULL;
	tabPlayerCoord = NULL;
}

void Brain::think() {
	*keystate = (short) 0;
	if (nbTick >= 20) {
		nbTick = 0;
	}
	if (nbTick < 10) {
		*keystate += (short) brainKeyRight;
	} else {
		*keystate += (short) brainKeyLeft;
	}
	nbTick++;

	astar->init(tabPlayerCoord[0], tabPlayerCoord[1], tabPlayerCoord[this->playerNumberControle * 2], tabPlayerCoord[this->playerNumberControle * 2 + 1], 3);
	astar->solve();
	if (astar->isSolved()) {
		fprintf(stderr, "Brain %i : ", this->playerNumberControle);
		Cell current = astar->getEnd();
		Cell * parent;
		current.printHimself();
		parent = current.getParent();
		while (true) {
			if (parent) {
				fprintf(stderr, " ->");
				parent->printHimself();
				parent = parent->getParent();
			} else {
				break;
			}
		}
		free(parent);
		fprintf(stderr, "\n");
	} else {
		fprintf(stderr, "Brain %i : pas de chemin possible vers cible \n", playerNumberControle);
	}

}
