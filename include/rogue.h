// Usado para fazer com que o compilador não compile esse arquivo toda vez
#ifndef ROGUE_H
#define ROGUE_H

#include <curses.h>
#include <stdlib.h> 

// Struct 'Position' contem as coordenadas y, x
typedef struct {
	int y;
	int x;
} Position;

// Struct 'Entity' contem uma Position e como o jogador é representado em tela
typedef struct {
	Position pos;
	char ch;
} Entity;

// Funções de player.c
Entity* createPlayer(Position start_pos);
void handleInput(int input);

// externs
extern Entity* player;
/* extern é usado para criar e usar variaveis compartilhadas 
entre diferentes arquivos que incluem o 'rogue.h' */

#endif