PIZZARIA
========

Trabalho da Disciplina de Programação Avançada do 4º semestre do curso de Desenvolvimento de Jogos Digitais
da FATEC Carapicuíba. Segundo semestre de 2013.

Professora Ana Travassos


Da de do do de de da de


PROPOSTA
========

  Implementar o conceito de fila em um jogo.


O JOGO
======

  O jogo é um jogo de Digitação que se passa numa pizzaria.
  Para atender os clientes deve-se digitar o pedido dos mesmos, que aparece escrito sobre suas cabeças.
  O primeiro cliente da fila é sempre o cliente a ser atendido.
  Para cada pedido digitado corretamente o jogador marca um ponto em 'Clientes satisfeitos'
  Um simples erro de digitação faz o cliente ir embora, marcando-se um ponto em 'Clientes irritados'

  O jogo possui 7 níveis.


BIBLIOTECAS
===========

stdlib.h
  biblioteca padrão C, usada para alocar memória dinamicamente para os elementos que constituem a fila

time.h
  Usada para alimentar a função rand(), para geração de números aleatórios.
  time.h auxilia na randomização, uma vez que o rand() não gera números aleatórios propriamente ditos,
      é preciso alimentar a função rand() com um valor, o time.h proporciona um novo numero com o passar do tempo,
      assim, o numero a ser jogado para rand() se torna previsivel, mas variavel

ncurses.h
  Biblioteca gráfica.


compilando:

gcc pizzaria.c -lncurses
