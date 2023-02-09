/* 
	Feito por Nico Ramos - GRR20210574
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "libpilha.h"
#include "libfila.h"
#include "liblista.h"

#define MAX_G 255
#define MAX_P 10

/* ---------------------------------------------------- */

/* Funções auxiliares gerais */

void imprime_teste(int esp, int result)
{
	printf("Esperado: %d\n", esp);
	printf("Recebido: %d\n", result);
}

void imprime_seq (int max)
{
	int i;

	for (i = 0; i < max; i++)
		printf(" %d", i);

	printf("\n");
}

/* ---------------------------------------------------- */

/* Funções auxiliares para a pilha */

int completa_pilha(pilha_t **pp_pilha, int max)
{
	int i, tam;

	for (i = 0; i < max; i++)
		tam = push(*pp_pilha, i);

	return tam;
}

void esvazia_pilha(pilha_t **pp_pilha, int max)
{
	int i;

	for (i = 0; i < max; i++)
		pop(*pp_pilha);
}

void compara_pilha(pilha_t **pp_pilha, int max)
{
	printf("Esperado:");
	imprime_seq(max);

	printf("Recebido: ");
	pilha_imprime(*pp_pilha);
}

/* ---------------------------------------------------- */

/* Funções auxiliares para a fila */

void preenche_fila(fila_t **pp_fila, int max)
{
	int i;

	for (i = 0; i < max; i++)
		queue(*pp_fila, i);
}

void esvazia_fila(fila_t **pp_fila, int fim)
{
	int i, elem;
	for (i = 0; i < fim; i++)
		dequeue(*pp_fila, &elem);
}

void compara_fila(fila_t **pp_fila, int max)
{
	printf("Esperado:");
	imprime_seq(max);

	printf("Recebido: ");
	fila_imprime(*pp_fila);
}

/* ---------------------------------------------------- */

/* Funções auxiliares para a lista */

void preenche_lista(lista_t **pp_lista, int max, char* opcao)
{
	int i;

	/* Escolhe a inserção de acordo com a opção selecionada */
	if (strcmp(opcao, "ini") == 0)
	{
		/* Insere para que ao final a lista seja crescente */
		for (i = max-1; i >= 1; i--)
			lista_insere_inicio(*pp_lista, i);
	}

	else if (strcmp(opcao, "fim") == 0)
	{
		for (i = 0; i < max; i++)
			lista_insere_fim(*pp_lista, i);
	}

	else if (strcmp(opcao, "ord") == 0)
	{
		/* Inicializa o gerador de números aleatórios */
		srand(time(0));

		for (i = 0; i < max; i++)
			/* Insere um valor aleatório */
			lista_insere_ordenado(*pp_lista, rand() % (max*3));
	}
}

void esvazia_lista(lista_t **pp_lista, int max, char* opcao)
{
	int i;

	/* Escolhe a remoção de acordo com a opção selecionada */
	if (strcmp(opcao, "ini") == 0)
	{
		int elem;

		for (i = max-1; i >= 0; i--)
			lista_retira_inicio(*pp_lista, &elem);
	}

	else if (strcmp(opcao, "fim") == 0)
	{
		int elem;

		for (i = 0; i < max; i++)
			lista_retira_fim(*pp_lista, &elem);
	}

	else if (strcmp(opcao, "elem") == 0)
	{
		for (i = 0; i < max; i++)
			lista_retira_elemento(*pp_lista, &i);
	}
}

void compara_lista(lista_t **pp_lista, int max)
{
	printf("Esperado:");
	imprime_seq(max);

	printf("Recebido: ");
	lista_imprime(*pp_lista);
}

int recria_lista(lista_t **pp_lista, int max)
{
	lista_destroi(*pp_lista);

	if (!(*pp_lista = lista_cria()))
		return 0;

	preenche_lista(pp_lista, max, "fim");

	return 1;
}
