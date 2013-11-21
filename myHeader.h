#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PEDIDOS 4

typedef struct cliente{
	char *pedido;
	struct cliente * proximo;
} Cliente;

typedef struct fila{
	struct cliente * primeiro;
	//primeiro da fila
} Fila;



// cria fila
// cria cliente
// cria array com os possiveis pedidos
// cria sorteio de pedido
// exibe clientes na fila
// exclui cliente da fila
// arruma o input, tanto faz upper e lower case.
// cria o cenario basico do jogo

Fila * cria_fila(void);
void cria_cliente(Fila *, char*);
void show_clientes(Fila *);
void pop_cliente(Fila *);
int num_clientes(Fila *);
char fixed_input();
void cenario(void);
void draw_cliente(int, int);
void level(Fila *, int);
void intro(int);
void intro_draw_level(int, int);
void placar(int, int);
void get_space(void);
