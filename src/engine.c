#include "../include/rogue.h"

void cursesSetup(void) {
	initscr();  // Inicia o sistema curses
	noecho();  // Faz com que não desenhe na tela o que o usuario digita
	curs_set(0);  // Faz o cursor do terminal ficar invisivel
}

void gameLoop(void) {
	// Guarda os input do jogador
	int ch;
	
	/* Desenha o jogador na tela na posição especificada antes do while loop para não começar
	o jogo com uma tela preta */
	//mvaddch(player->pos.y, player->pos.x, player->ch);
	
	drawEverything();
  
	// getch() recebe um input de caractere - != significa 'não é igual' 
	// Inicia um while loop que espera o jogador apertar alguma tecla
	while(ch = getch()) {
	  // Saí do jogo
	  if (ch == 'q') {
		break;
	  }
	  
	handleInput(ch);
		drawEverything();
	/* Limpa a tela
	clear();
	// Desenha o jogador de novo em sua nova posição
	mvaddch(player->pos.y, player->pos.x, player->ch); */
	}
}

void closeGame(void) {
	endwin();
	free(player);  // Tira a memoria alocada do ponteiro argumentado
}