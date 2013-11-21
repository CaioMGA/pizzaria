#include "myHeader.h"
#include "desenhos.h"
#include "fila.h"
#include "game.h"

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