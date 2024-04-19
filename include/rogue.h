// Usado para fazer com que o compilador não compile esse arquivo toda vez
#ifndef ROGUE_H
#define ROGUE_H

#include <curses.h>
#include <stdlib.h> 
#include <stdbool.h>

// Struct 'Position' contem as coordenadas y, x
typedef struct {
	int y;
	int x;
} Position;

typedef struct {
	char ch;
	bool walkable;
} Tile;

// Struct 'Entity' contem uma Position e como o jogador é representado em tela
typedef struct {
	Position pos;
	char ch;
} Entity;

// funções de engine.c
void cursesSetup(void);
void gameLoop(void);
void closeGame(void);

// Funções de map.c
Tile** createMapTiles(void);
Position setupMap(void);
void freeMap(void);

// Funções de player.c
Entity* createPlayer(Position start_pos);
void handleInput(int input);
void movePlayer(Position newPos);

// Funções de draw.c 
void drawMap(void);
void drawEntity(Entity* entity);
void drawEverything(void);

// externs
extern const int MAP_HEIGHT;
extern const int MAP_WIDTH;
extern Entity* player;
extern Tile** map;
/* extern é usado para criar e usar variaveis compartilhadas 
entre diferentes arquivos que incluem o 'rogue.h' */

#endif