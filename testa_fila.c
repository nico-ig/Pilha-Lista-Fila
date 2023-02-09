/* 
	Feito por Nico Ramos - GRR20210574
*/

#include <stdio.h>

#include "libfila.h"
#include "libteste.h"

int main()
{
	printf("\n-------------------------------------------------------------\n");


	fila_t *p_fila;

	/* Vamos primeiro testar a inicialização da fila */
	printf("\nTesta se a fila é iniciada corretamente\n");

	if (!(p_fila = fila_cria()))
	{
		fprintf(stderr, "Falha na alocação da fila\n");
		return 0;
	}


	/* Testes para ver se os valores da fila iniciam corretamente */
	/* Vê se o status de saída é 1 (fila vazia) */
	printf("\nTeste: verifica se a fila inicia vazia (status de saída)\n");
	imprime_teste(1, fila_vazia(p_fila));

	printf("\nTeste: verifica o tamanho inicial\n");
	imprime_teste(0, fila_tamanho(p_fila));


	printf("\n-------------------------------------------------------------\n");

	
	/* Testa se o status de saída no caso de underflow no dequeue é 0 */
	printf("\nTeste: verifica o status de saída para underflow\n");
	int elem;
	imprime_teste(0, dequeue(p_fila, &elem));


	printf("\n-------------------------------------------------------------\n");

	
	printf("\nTesta a impressão e se destrói cerretamente a fila\n");

	/* Preenche a fila com valores de 0 até MAX_P-1 */ 
	preenche_fila(&p_fila, MAX_P);

	printf("\nTeste: vê a impressão de uma fila com %d elementos\n", MAX_P);
	
	/* Imprime a sequência esperada e a recebida */
	compara_fila(&p_fila, MAX_P);

	/* Destrói a fila para usar o mesmo ponteiro em uma fila maior */	
	printf("\nTeste: verifica o status de saída ao destruir a fila\n");
	imprime_teste(0, !(fila_destroi(p_fila) == NULL));


	printf("\n-------------------------------------------------------------\n");
		

	printf("\nTestes de inserção e remoção na fila\n");

	/* Cria uma fila com MAX_G elementos */	
	if (!(p_fila = fila_cria()))
		printf("\nFalha na criação da fila\n");

	/* Preenche uma fila com valores de 0 até MAX_G-2 */
	preenche_fila(&p_fila, MAX_G-1);

	/* Insere um elemento para testar o status de saída */
	printf("\nTeste: verifica o status de saída para o queue\n");
	imprime_teste(1, queue(p_fila, MAX_G-1));

	printf("\nTeste: vê se realmente tem a quantidade esperada de elementos\n");
	imprime_teste(MAX_G, fila_tamanho(p_fila));

	printf("\nTeste: vê se a fila não é vazia após queue (status de saída)\n");
	imprime_teste(0, fila_vazia(p_fila));

	/* Remove o primeiro da fila "0" e verifica o status de saida */
	printf("\nTeste: verifica o status de saida da função dequeue\n");
	imprime_teste(1, dequeue(p_fila, &elem));

	printf("\nTeste: verifica se o elemento retirado é o esperado\n");
	imprime_teste(0, elem);

	/* Faz o dequeue de mais um elemento: "1" */
	printf("\nTeste: verifica o dequeue do segundo elemento\n");
	dequeue(p_fila, &elem);
	imprime_teste(1, elem);

	/* Verifica o tamanho após retirar dois elementos */
	printf("\nTeste: verifica o tamanho após dois dequeue\n");
	imprime_teste(MAX_G-2, fila_tamanho(p_fila));


	printf("\n-------------------------------------------------------------\n");


	printf("\nTestes de esvaziar a fila\n");

	/* Retira os elementos até sobrar apenas o último */
	esvazia_fila(&p_fila, MAX_G-3);

	printf("\nTeste: verifica o dequeue do último elemento da fila\n");
	dequeue(p_fila, &elem);
	imprime_teste(254, elem );

	printf("\nTeste: verifica o tamanho após esvaziar a fila\n");
	imprime_teste(0, fila_tamanho(p_fila));

	printf("\nTeste: imprime a fila vazia\n");
	compara_fila(&p_fila, 0);
	printf("\n");


	printf("\n-------------------------------------------------------------\n");


	fila_destroi(p_fila);
	return 0;
}
