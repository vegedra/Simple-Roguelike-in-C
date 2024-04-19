#include "../include/rogue.h"  // Vai usar as structs feitas aí

// Função tem um argumento Position e retorna um ponteiro para uma Entity
Entity* createPlayer(Position start_pos) {
	// Declara a variavel 'newPlayer' e dinamicamente aloca uma memoria apropriada pra esse ponteiro
	Entity* newPlayer = calloc(1, sizeof(Entity));
	/* Estamos usando 'calloc' inves de 'malloc' pq ele aloca memoria e inicializa todos os bytes
	no bloco de memoria para 0, limpando o lixo de antes e usando de forma segura a memoria */
	
	// Se usa '->' quando se usa pointers para structs
	newPlayer->pos.y = start_pos.y;
	newPlayer->pos.x = start_pos.x;
	newPlayer->ch = '@';
	
	return newPlayer;
}

// Função que aumenta ou diminui as variaveis x e y da posição do jogador
void handleInput(int input) {
	Position newPos = { player->pos.y, player->pos.x };
	switch(input) {
		// Cima
		case 'w':
			newPos.y--;
			break;
		// Baixo
		case 's':
			newPos.y++;
			break;
		// Esquerda
		case 'a':
			newPos.x--;
			break;
		// Direita
		case 'd':
			newPos.x++;
			break;
		// Se nenhum
		default:
			break;
	}
	
	movePlayer(newPos);
}

void movePlayer(Position newPos) {
	if (map[newPos.y][newPos.x].walkable) {
		player->pos.y = newPos.y;
		player->pos.x = newPos.x;
	}
}