/* Jogo Roguelike em C por Pedro Ivo - 2024
   https://dev.to/ignaoya/the-c-roguelike-tutorial-part-1-the-player-3291
   Para compilar: gcc -o teste main.c -lpdcurses */
   

//#include <curses.h>  -- Biblioteca para cuidar da tela pro Windows
#include "../include/rogue.h"  // Header que criamos que já tem o 'curses.h'

// Declara variavel que usaremos para apontar para nosso objeto player
Entity* player;

int main(void)  // Função não tem argumentos
{
  // Guarda os input do jogador
  int ch;
  // Cria uma struct Position para dar uma posição inicial em createPlayer()
  Position start_pos = { 10, 20 };
  
  initscr();  // Inicia o sistema curses
  noecho();  // Faz com que não desenhe na tela o que o usuario digita
  curs_set(0);  // Faz o cursor do terminal ficar invisivel
  
  player = createPlayer(start_pos);
  /* Desenha o jogador na tela na posição especificada antes do while loop para não começar
  o jogo com uma tela preta */
  mvaddch(player->pos.y, player->pos.x, player->ch);
  
  // getch() recebe um input de caractere - != significa 'não é igual' 
  // Inicia um while loop que espera o jogador apertar alguma tecla
  while(ch = getch()) {
	  // Saí do jogo
	  if (ch == 'q') {
		break;
	  }
	  
	  handleInput(ch);
	  // Limpa a tela
	  clear();
	  // Desenha o jogador de novo em sua nova posição
	  mvaddch(player->pos.y, player->pos.x, player->ch);
  }
  
  endwin();  // Fecha o terminal, ultima função antes de finalizar o programa

  return 0;
}