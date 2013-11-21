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

