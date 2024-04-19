/* Jogo Roguelike em C por Pedro Ivo - 2024
   https://dev.to/ignaoya/the-c-roguelike-tutorial-part-1-the-player-3291
   Para compilar: gcc -o teste main.c -lpdcurses */
   
//#include <curses.h>  -- Biblioteca para cuidar da tela pro Windows
#include "../include/rogue.h"  // Header que criamos que já tem o 'curses.h'

const int MAP_HEIGHT = 25;
const int MAP_WIDTH = 100;

// Declara variavel que usaremos para apontar para nosso objeto player
Entity* player;
Tile** map;

int main(void)  // Função não tem argumentos
{
  Position start_pos;
  cursesSetup();
  
  // Cria uma struct Position para dar uma posição inicial em createPlayer()
  map = createMapTiles();
  start_pos = setupMap();
  player = createPlayer(start_pos);
  
  gameLoop();
  closeGame();

  return 0;
}