char fixed_input(){
	char c = getch();
	if(c >= 97 && c <= 122){
		c -= 32;
	}

	return c;
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

void get_space(){
	move(20, 18);
	attron(COLOR_PAIR(1));
	printw("( PRESSIONE ESPACO PARA CONTINUAR )");
	attroff(COLOR_PAIR(1));
	refresh();

	while(getch() != ' '){

	}
}