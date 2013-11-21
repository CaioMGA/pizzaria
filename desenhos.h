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

void draw_cliente(int x, int y){
	//modelo do cliente
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