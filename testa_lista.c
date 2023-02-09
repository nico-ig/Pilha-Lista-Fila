/* 
	Feito por Nico Ramos - GRR20210574
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "liblista.h"
#include "libteste.h"

int main()
{
	printf("\n-------------------------------------------------------------\n");


	lista_t *p_lista;

	/* Vamos primeiro testar a inicialização da lista */
	printf("\nTesta se a lista é iniciada corretamente\n");

	/* Testa a alocação da lista */
	if (!(p_lista = lista_cria()))
	{
		fprintf(stderr, "Falha na alocação da lista\n");
		return 0;
	}


	/* Testes para ver se os valores da lista iniciam corretamente */
	/* Vê se o status de saída é 1 (lista vazia) */
	printf("\nTeste: verifica se a lista inicia vazia (status de saída)\n");
	imprime_teste(1, lista_vazia(p_lista));

	printf("\nTeste: verifica o tamanho inicial\n");
	imprime_teste(0, lista_tamanho(p_lista));


	printf("\n-------------------------------------------------------------\n");


	/* Testes do status de saída para underflow e não pertence a lista vazia */
	printf("\nTesta as funções de remoção e pertence para a lista vazia\n"); 

	/* Declara um elemento para testar remoção */
	int elem;

	printf("\nTeste: tenta remover do início da lista (status de saída)\n");
	imprime_teste(0, lista_retira_inicio(p_lista, &elem));

	printf("\nTeste: tenta remover do fim da lista (status de saída)\n");
	imprime_teste(0, lista_retira_fim(p_lista, &elem));

	/* Atribui um valor para testar a retirada por elemento */
	elem = 0;

	printf("\nTeste: remover por elemento na lista vazia (status de saída)\n");
	imprime_teste(0, lista_retira_elemento(p_lista, &elem));

	printf("\nTeste: vê se o elemento está na lista vazia (status de saída)\n");
	imprime_teste(0, lista_pertence(p_lista, elem));


	printf("\n-------------------------------------------------------------\n");

	
	printf("\nTestes de inserir e remover pelo início\n");

	/* Preenche a lista com valores de 1 até MAX_P-1 pelo início */ 
	preenche_lista(&p_lista, MAX_P, "ini");

	/* Insere o elemento 0 para verificar o status de saída */
	printf("\nTeste: verifica o status de saída para a inserção no início\n");
	imprime_teste(1, lista_insere_inicio(p_lista, 0));

	/* Verifica que o tamanho é MAX_P elementos */
	printf("\nTeste: verifica o tamanho após inserir no inicio\n");
	imprime_teste(MAX_P, lista_tamanho(p_lista));

	printf("\nTeste: vê a impressão de uma lista com %d elementos\n", MAX_P);
	
	/* Imprime a sequência esperada e a recebida */
	compara_lista(&p_lista, MAX_P);

	/* Verifica o status de saída e retira um elemento */
	printf("\nTeste: status de saída da remoção no início da lista\n");
	imprime_teste(1, lista_retira_inicio(p_lista, &elem));

	printf("\nTeste: verifica se o elemento retirado é o esperado\n");
	imprime_teste(0, elem);

	/* Esvazia a lista após já ter retirado 1 elemento */
	esvazia_lista(&p_lista, MAX_P-1, "ini");

	printf("\nTeste: checa que a lista voltou a ser vazia (status de saída)\n");
	imprime_teste(1, lista_vazia(p_lista));

	printf("\nTeste: imprime a lista após a remoção\n");
	compara_lista(&p_lista, 0);
	printf("\n");


	printf("\n-------------------------------------------------------------\n");


	printf("\nTestes de inserir e remover pelo fim\n");

	/* Preenche a lista com valores de 0 até MAX_P-2 pelo fim*/ 
	preenche_lista(&p_lista, MAX_P-1, "fim");

	/* Insere o elemento MAX_P-1 para verificar o status de saída */
	printf("\nTeste: verifica o status de saída para a inserção no fim\n");
	imprime_teste(1, lista_insere_fim(p_lista, MAX_P-1));

	/* Verifica que o tamanho é MAX_P elementos */
	printf("\nTeste: verifica o tamanho após inserir no fim\n");
	imprime_teste(MAX_P, lista_tamanho(p_lista));

	printf("\nTeste: vê a impressão de uma lista com %d elementos\n", MAX_P);
	
	/* Imprime a sequência esperada e a recebida */
	compara_lista(&p_lista, MAX_P);

	/* Verifica o status de saída e retira um elemento */
	printf("\nTeste: status de saída da remoção no fim da lista\n");
	imprime_teste(1, lista_retira_fim(p_lista, &elem));

	printf("\nTeste: verifica se o elemento retirado é o esperado\n");
	imprime_teste(9, elem);

	/* Esvazia a lista após já ter retirado 1 elemento */
	esvazia_lista(&p_lista, MAX_P-1, "fim");

	printf("\nTeste: checa se a lista voltou a ser vazia (status de saída)\n");
	imprime_teste(1, lista_vazia(p_lista));

	printf("\nTeste: imprime a lista após a remoção\n");
	compara_lista(&p_lista, 0);
	printf("\n");


	printf("\n-------------------------------------------------------------\n");

	
	printf("\nTestes de inserção ordenada\n");
	
	/* Preenche a lista com MAX_P-1 valores de forma ordenada */
	preenche_lista(&p_lista, MAX_P-1, "ord");

	/* Insere um elemento qualquer para verificar o status de saída */
	printf("\nTeste: verifica o status de saída para a inserção ordenada\n");
	imprime_teste(1, lista_insere_ordenado(p_lista, 7));

	printf("\nTeste: verifica o tamanho após inserir ordenado\n");
	imprime_teste(MAX_P, lista_tamanho(p_lista));

	printf("\nTeste: impressão da lista com %d elementos aleatórios\n", MAX_P);
	printf("Recebido: ");
	lista_imprime(p_lista);


	printf("\n-------------------------------------------------------------\n");


	printf("\nTestes de operações por elemento na lista\n");

	/* Recria a lista anterior agora com MAX_G elementos */
	if (!(recria_lista(&p_lista, MAX_G)))
	{
		fprintf(stderr, "Falha na alocação da pilha\n");
		return 0;
	}

	/* Retira um elemento qualquer que pertence a lista */
	printf("\nTeste: retira elemento que pertence a lista (status de saída)\n");
	elem = 100;
	imprime_teste(1, lista_retira_elemento(p_lista, &elem));

	printf("\nTeste: retira primeiro elemento da lista (status de saída)\n");
	elem = 0;
	imprime_teste(1, lista_retira_elemento(p_lista, &elem));

	/* O tamanho será MAX_G-2 pois foram retirados 2 elementos */
	printf("\nTeste: verifica o tamanho após 2 remoções\n");
	imprime_teste(MAX_G-2, lista_tamanho(p_lista));

	printf("\nTeste: retira um elemento que não pertence (status de saída)\n");
	elem = 300;
	imprime_teste(0, lista_retira_elemento(p_lista, &elem));

	/* Testes de pertencimento à lista */
	printf("\nTeste: checa que um elemento está na lista (status de saída)\n");
	elem = 200;
	imprime_teste(1, lista_pertence(p_lista, elem));

	printf("\nTeste: checa que elemento não está na lista (status de saída)\n");
	elem = 1000;
	imprime_teste(0, lista_pertence(p_lista, elem));


	printf("\n-------------------------------------------------------------\n");


	lista_destroi(p_lista);
	return 0;
}
