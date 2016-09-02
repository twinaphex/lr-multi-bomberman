#include "Grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Grid::Grid(){
    init();
}


Grid::Grid(int x, int y, int levelIndex)
{
    sizeX = x;
    sizeY = y;
    lvl = levelIndex;
    tab = new int[sizeX * sizeY];
    init();
    generateGrid();
}


Grid::~Grid()
{
    
    int i;
    for(i = 0; i < 40; i++){
        SDL_FreeSurface(textures[i]);
    }
    for(i = 0; i < 2; i++){
        SDL_FreeSurface(skys[i]);
    }
    SDL_FreeSurface(ground);
    SDL_FreeSurface(brickShadow);
    SDL_FreeSurface(playersBombes);
    SDL_FreeSurface(skyFixe);
    SDL_FreeSurface(skyMove);
    SDL_FreeSurface(theGrid);
}


SDL_Surface * Grid::getGrid(){
    mergeGrid();
	return theGrid;
}


void Grid::configure(int x, int y, int levelNumber){
    sizeX = x;
    sizeY = y;
    lvl = levelNumber;
    tab = new int[sizeX * sizeY];
    init();
    generateGrid();
}


void Grid::init(){
    //declarativ color mask, used for create a RGB surface
    Uint32 rmask, gmask, bmask, amask;
    amask = 0xff000000;
    rmask = 0x00ff0000;
    gmask = 0x0000ff00;
    bmask = 0x000000ff;
    
    //buffer for loading textures
    SDL_Surface *textureBuffer = IMG_Load(levelSprite);
    
    //initialise the surface Tab
    textures = new SDL_Surface*[40];
    skys = new SDL_Surface*[2];
    
    //rectangle for cropped the texture
    SDL_Rect textureRect;
    SDL_Rect skyRect;
    SDL_Rect destTextureRect;
    
    int offset = lvl * 128;
    
    //CROPPING textures level
    destTextureRect.x = 0;
    destTextureRect.y = 0;
    destTextureRect.w = 18;
    destTextureRect.h = 16;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 8 ; j++){
            textureRect.x = i * 18;
            textureRect.y = offset + (j * 16);
            textureRect.w = 18;
            textureRect.h = 16;
            textures[i+(j*5)] =  SDL_CreateRGBSurface(0, 18, 16, 32, rmask, gmask, bmask, amask);
            SDL_BlitSurface(textureBuffer, &textureRect, textures[i+(j*5)], &destTextureRect);
        }
    }
    
    destTextureRect.x = 0;
    destTextureRect.y = 0;
    destTextureRect.w = 54;
    destTextureRect.h = 48;
    for(int k = 0; k < 2 ; k++){
        skyRect.x = 90;
        skyRect.y = offset + (k * 48);
        skyRect.w = 54;
        skyRect.h = 48;
        skys[k] =  SDL_CreateRGBSurface(0, 54, 48, 32, rmask, gmask, bmask, amask);
        SDL_BlitSurface(textureBuffer, &skyRect, skys[k], &destTextureRect);
    }
    
    theGrid = SDL_CreateRGBSurface(0, 630, 336, 32, rmask, gmask, bmask, amask);
    ground = SDL_CreateRGBSurface(0, 630, 336, 32, rmask, gmask, bmask, amask);
    brickShadow = SDL_CreateRGBSurface(0, 630, 336, 32, rmask, gmask, bmask, amask);
    playersBombes = SDL_CreateRGBSurface(0, 630, 336, 32, rmask, gmask, bmask, amask);
    skyFixe = SDL_CreateRGBSurface(0, 630, 336, 32, rmask, gmask, bmask, amask);
    skyMove = SDL_CreateRGBSurface(0, 630, 336, 32, rmask, gmask, bmask, amask);
    SDL_FillRect(theGrid, NULL, SDL_MapRGB(theGrid->format, 255, 204, 0));
    SDL_FreeSurface(textureBuffer);
}


void Grid::generateGrid(){
    srand (time(NULL));
    
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            if( j == 0 || j == (sizeY-1) || i == 0 || i == (sizeX-1)|| (j%2 == 0 && i%2 == 0)){
                tab[i+(j*sizeX)] = 1;
            } else {
                /* generate secret number between 1 and 3: */
                if((rand() % 7 + 1)>=2){
                    tab[i+(j*sizeX)] = 2;
                } else {
                    tab[i+(j*sizeX)] = 0;
                }
            }
        }
    }
    SDL_Rect dstrect;
    SDL_Rect srcrect;
    SDL_Rect skyRect;
    srcrect.x = 0;
    srcrect.y = 0;
    srcrect.w = 18;
    srcrect.h = 16;
    
    skyRect.x = 0;
    skyRect.y = 0;
    skyRect.w = 54;
    skyRect.h = 48;
    
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY ; j++){
            dstrect.x = i * 18;
            dstrect.y = j * 16;
            dstrect.w = 18;
            dstrect.h = 16;
            SDL_BlitSurface(textures[18], &srcrect, theGrid, &dstrect);
            int textureIndex = level[lvl][j][i];
            if(textureIndex < 40){
                SDL_BlitSurface(textures[textureIndex], &srcrect, ground, &dstrect);
            }else{
                dstrect.x = (i-1) * 18;
                dstrect.y = (j-1) * 16;
                dstrect.w = 54;
                dstrect.h = 48;
                SDL_BlitSurface(skys[textureIndex % 40], &skyRect, skyFixe, &dstrect);
            }
            if(tab[i+(j*sizeX)] == 2){
                if(reservedSpot[j][i] == 0){
                    if(textureIndex == 40){
                        dstrect.x = i * 18;
                        dstrect.y = j * 16;
                        dstrect.w = 18;
                        dstrect.h = 16;
                    }
                    SDL_BlitSurface(textures[21], &srcrect, brickShadow, &dstrect);
                }else{
                    //reservedSpot !
                    tab[i+(j*sizeX)] = 0;
                }
            }
        }
    }
    mergeGrid();
}

void Grid::mergeGrid(){
    SDL_Rect mergeRect;
    mergeRect.x = 0;
    mergeRect.y = 0;
    mergeRect.w = 630;
    mergeRect.h = 336;
    SDL_BlitSurface(ground          , &mergeRect, theGrid, &mergeRect);
    SDL_BlitSurface(brickShadow     , &mergeRect, theGrid, &mergeRect);
    SDL_BlitSurface(playersBombes   , &mergeRect, theGrid, &mergeRect);
    SDL_BlitSurface(skyFixe         , &mergeRect, theGrid, &mergeRect);
    SDL_BlitSurface(skyMove         , &mergeRect, theGrid, &mergeRect);
}
