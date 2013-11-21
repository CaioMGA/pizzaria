#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
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


int main(){
	Fila * f = cria_fila();
	
	int i = 0;
	int level_atual = 1;
	int clientes_satisfeitos = 0;
	int clientes_irritados = 0;
	char foo;
	char ch;
	bool game = TRUE;
	bool rodada = TRUE;

	srand(time(0));//inicializo o randomizador

	initscr(); //inicia curses
	start_color();
	noecho();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLUE);
	init_pair(4, COLOR_GREEN, COLOR_YELLOW);
	init_pair(5, COLOR_GREEN, COLOR_CYAN);
	init_pair(6, COLOR_GREEN, COLOR_WHITE);
	init_pair(7, COLOR_GREEN, COLOR_RED);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	
	
	while(game){
		rodada = TRUE;
		level(f, level_atual);
		while(rodada){
			foo = f -> primeiro -> pedido[i];
			show_clientes(f);
			while(foo != '\0'){
				ch = fixed_input();
				
				if(foo == ch){
					
					attron(COLOR_PAIR(2));
					move(0, i);
					printw("%c", ch);
					i++;
					foo = f -> primeiro -> pedido[i];
					attroff(COLOR_PAIR(2));	

				}
				else{
					clientes_irritados++;
					break;
				}

			}
			if(foo == '\0'){
				clientes_satisfeitos++;	
			}
			i = 0;
			pop_cliente(f);
			cenario();
			
			
			if(num_clientes(f) == 0) {
				rodada = FALSE;
				if(level_atual < 7){
					level_atual++;
				}
				else{
					game = FALSE;
				}
			}
		}
		placar(clientes_satisfeitos, clientes_irritados);
	}
	move(20, 20);
	printw("Saindo...");
	refresh();
	getch();
	endwin(); //finaliza curses
	return 0;
}

Fila * cria_fila(){
	Fila * nova = (Fila *) malloc(sizeof(Fila));
	nova -> primeiro = NULL;

	return nova;
}

void cria_cliente(Fila * f, char *c){
	Cliente * novo = (Cliente *)malloc(sizeof(Cliente));
	novo -> pedido = c;
	novo -> proximo = NULL;

	if(f -> primeiro){
		Cliente * foo;
		Cliente * ultimo;

		foo = f -> primeiro;
		do{
			ultimo = foo;
			foo = foo -> proximo;
		}while(foo != NULL);
		ultimo -> proximo = novo;
	}
	else {
		f -> primeiro = novo;
	}
}

void show_clientes(Fila * f){
	Cliente * aux;
	int x, y;
	int num_cliente_atual = 0;
	char c = (char)219;
	x = 0;
	y = 0;

	bool primeiro_cliente = TRUE;
	for(aux = f -> primeiro; aux != NULL && num_cliente_atual <15; aux = aux -> proximo){
		
		if(num_cliente_atual % 5 == 0 && num_cliente_atual != 0){

			x+=12;
			y = 0;
			primeiro_cliente = TRUE;
		}

		move(x, y);
		attron(COLOR_PAIR(1));
		printw("%s", aux -> pedido);
		attroff(COLOR_PAIR(1));

		if(primeiro_cliente){
			y+= 4;
		}
		draw_cliente(x, y);
		

		refresh();

		if(primeiro_cliente){
			y-= 4;
			primeiro_cliente = FALSE;
		}

		//x += 10;
		y+= 20;
		num_cliente_atual +=1;
	}
}
void pop_cliente(Fila * f){
	if(f -> primeiro){
		Cliente * foo;

		foo = f -> primeiro;
		f -> primeiro = foo -> proximo;
		free(foo);
	}
}

int num_clientes(Fila * f){
	int qtd = 0;
	Cliente * foo;
	for(foo = f -> primeiro;foo != NULL; foo = foo -> proximo){
		qtd += 1;
	}

	return qtd;
	
}

char fixed_input(){
	char c = getch();
	if(c >= 97 && c <= 122){
		c -= 32;
	}

	return c;
}

void cenario(){
	int i, j;
	int bar = 0;
	clear();



	attron(COLOR_PAIR(3));
	for(i = 1; i <11; i++){
		for(j = 0; j < 15; j++){
			bar = i+j;
			bar = bar % 2;
			if(bar){
				move(i, j);
				printw(" ");
			}
			
		}
		
	}
	attroff(COLOR_PAIR(3));


	attron(COLOR_PAIR(4));
	for(j = 0; j<11 ; j++){
		move(j, 15);
		printw("  ");
	}
	attroff(COLOR_PAIR(4));

	bar = 0;	
	attron(COLOR_PAIR(5));
	for(i = 1; i <11; i++){
		for(j = 17; j <90; j++){
			bar = i+j;
			bar = bar  % 2;
			if(bar == 0){
				move(i, j);
				
				printw(" ");
				refresh();
			}

		}
	}

	for(i = 35; i<90; i+= 20){
		move(0, i);
		printw(" ");
	}
	//segunda fila
	for(i = 13; i <23; i++){
		for(j = 0; j <90; j++){
			bar = i+j;
			bar = bar  % 2;
			if(bar == 0){
				move(i, j);
				
				printw(" ");
				refresh();
			}

		}
	}

	for(i = 15; i<90; i+= 20){
		move(12, i);
		printw(" ");
	}

	//terceira fila
	for(i = 25; i <35; i++){
		for(j = 0; j <90; j++){
			bar = i+j;
			bar = bar  % 2;
			if(bar == 0){
				move(i, j);
				
				printw(" ");
				refresh();
			}

		}
	}

	for(i = 15; i<90; i+= 20){
		move(24, i);
		printw(" ");
	}

	attroff(COLOR_PAIR(5));
	
	refresh();
	
}

void draw_cliente(int x, int y){
	attron(COLOR_PAIR(6));

		move(x+2, y+0);
		printw("     ");
		
		move(x+3, y+0);
		printw(" ");
		move(x+3, y+2);
		printw(" ");
		move(x+3, y+4);
		printw(" ");

		move(x+4, y+0);
		printw(" ");
		move(x+4, y+2);
		printw(" ");
		move(x+4, y+4);
		printw(" ");

		move(x+5, y+0);
		printw("     ");

		move(x+6, y+0);
		printw(" ");
		move(x+6, y+4);
		printw(" ");

		move(x+7, y+0);
		printw("     ");

		move(x+8, y+0);
		printw(" ");
		move(x+8, y+4);
		printw(" ");

		move(x+9, y-1);
		printw("  ");
		move(x+9, y+3);
		printw("  ");


	attroff(COLOR_PAIR(6));
}

void level(Fila * f, int opt){
	int i;
	int r;

	char *pedidos [NUM_PEDIDOS]  = { "MOZZARELA", "CALABRESA", "ATUM", "BANANA" };
	switch(opt){
		case 1:
			i = 1;
			break;
		
		case 2:
			i = 4;
			break;

		case 3:
			i = 7;
			break;
		
		case 4:
			i = 12;
			break;

		case 5:
			i = 18;
			break;

		case 6:
			i = 25;
			break;

		case 7:
			i = 35;
			break;

		default:
			break;
	}

	do {
		r = rand() % NUM_PEDIDOS;
		cria_cliente(f, pedidos[r]);
		i--;
	} while(i>0);
	intro(opt);
}

void intro(int l){
	int i, j;
	clear();
	intro_draw_level(10, 20);
	attron(COLOR_PAIR(7));

	switch(l){
		case 1:
			for(i = 0; i< 5;i++){
				move(10 +i, 40);
				printw(" ");
			}
			move(10, 39);
			printw(" ");

			break;
		case 2:
			for(i = 0; i< 5; i += 2){
				move(10 +i, 40);
				printw("   ");
			}
			
			move(13, 40);
			printw(" ");

			move(11, 42);
			printw(" ");

			break;

		case 3:
			for(i = 0; i< 5; i += 4){
				move(10 +i, 40);
				printw("   ");
			}
				move(11, 42);
				printw(" ");

				move(12, 42);
				printw(" ");

				move(13, 42);
				printw(" ");

				move(12, 41);
				printw(" ");

				break;

		case 4:
			move(10, 40);
			printw(" ");

			move(11, 40);
			printw(" ");

			move(12, 40);
			printw("  ");

			for(i = 0; i<5; i++){
				move(10 +i, 42);
				printw(" ");
			}

			break;

		case 5:
			for(i = 0; i< 5; i += 2){
				move(10 +i, 40);
				printw("   ");
			}
			
			move(13, 42);
			printw(" ");

			move(11, 40);
			printw(" ");

			break;

		case 6:
			for(i = 2; i< 5; i += 2){
				move(10 +i, 40);
				printw("   ");
			}
			
			for(i = 0; i< 5; i ++){
				move(10 +i, 40);
				printw(" ");
			}

			for(i = 0; i< 3; i ++){
				move(12 +i, 42);
				printw(" ");
			}

			break;

		case 7:
			for(i = 0; i< 5;i++){
				move(10 +i, 40);
				printw(" ");
			}
			move(10, 38);
			printw("  ");
			break;
		default:
			break;
	}
	attroff(COLOR_PAIR(7));

	get_space();
	cenario();
}

void intro_draw_level(int x, int y){
	int i;
	int j;

	attron(COLOR_PAIR(7));
	for(j = 0; j < 5; j++){
			
			move(j+x, 0+y);
			printw(" ");
	}

	for(j = 0; j < 5; j++){
			
			move(j+x, 3+y);
			printw(" ");
	}

	for(j = 0; j < 4; j++){
			
			move(j+x, 6+y);
			printw(" ");
	}

	for(j = 0; j < 4; j++){
			
			move(j+x, 8+y);
			printw(" ");
	}

	for(j = 0; j < 5; j++){
			
			move(j+x, 10+y);
			printw(" ");
	}
	for(j = 0; j < 5; j++){
			
			move(j+x, 13+y);
			printw(" ");
	}

	move(x+0, 4+y);
	printw(" ");

	move(x+0, 11+y);
	printw(" ");

	move(x+2, 4+y);
	printw(" ");

	move(x+2, 11+y);
	printw(" ");

	move(x+4, 1+y);
	printw(" ");

	move(x+4, 4+y);
	printw(" ");

	move(x+4, 7+y);
	printw(" ");

	move(x+4, 11+y);
	printw(" ");

	move(x+4, 14+y);
	printw(" ");

	attroff(COLOR_PAIR(7));
}

void placar(int clientes_satisfeitos, int clientes_irritados){
	int x = 15;
	int y = 20;

	clear();
	attron(COLOR_PAIR(1));
	move(x, y);
	printw("CLIENTES SATISFEITOS:\t%d\n", clientes_satisfeitos);
	attroff(COLOR_PAIR(1));

	attron(COLOR_PAIR(8));
	move(x+2, y);
	printw("CLIENTES IRRITADOS:\t\t%d\n", clientes_irritados);
	attroff(COLOR_PAIR(8));

	get_space();
}

void get_space(){
	move(20, 18);
	attron(COLOR_PAIR(1));
	printw("( PRESSIONE ESPACO PARA CONTINUAR )");
	attroff(COLOR_PAIR(1));
	refresh();

	while(getch() != ' '){

	}
}