/* 
	Feito por Nico Ramos - GRR20210574
*/

#include <stdio.h>

#include "libpilha.h"
#include "libteste.h"

int main()
{
	printf("\n-------------------------------------------------------------\n");

	
	pilha_t *p_pilha;

	/* Vamos primeiro testar a inicialização da pilha */
	printf("\nTesta se a pilha é iniciada corretamente\n");


	/* Testa a alocação de uma pilha de tam MAX_P */
	if (!(p_pilha = pilha_cria(MAX_P)))
	{
		fprintf(stderr, "Falha na alocação da pilha\n");
		return 0;
	}


	/* Testes para ver se os valores da pilha iniciam corretamente */
	/* Vê se o status de saída é 1 (pilha vazia) */
	printf("\nTeste: verifica se a pilha inicia vazia (status de saída)\n");
	imprime_teste(1, pilha_vazia(p_pilha));

	printf("\nTeste: verifica o tamanho inicial\n");
	imprime_teste(0, pilha_tamanho(p_pilha));

	printf("\nTeste: verifica se o topo é o índice correto\n");
	imprime_teste(0, pilha_topo(p_pilha));


	printf("\n-------------------------------------------------------------\n");


	/* Testa se o status de saída no caso de underflow no pop é 0 */
	printf("\nTeste: verifica o status de saída para underflow\n");
	imprime_teste(0, pop(p_pilha));


	printf("\n-------------------------------------------------------------\n");


	printf("\nTesta a impressão e se destrói cerretamente a pilha\n");

	/* Preenche uma pilha com valores de 0 até MAX_P-1 */
	completa_pilha(&p_pilha, MAX_P);

	/* Verifica se a pilha está correta e se está imprimindo corretamente */
	printf("\nTeste: Verifica a impressão de uma pilha de tam %d\n", MAX_P);

	/* Imprime a sequência esperada e a recebida */
	compara_pilha(&p_pilha, MAX_P);

	/* Destrói a pilha para usar o mesmo ponteiro em uma pilha maior */	
	printf("\nTeste: verifica o status de saída ao destruir a pilha\n");
	imprime_teste(0, !(pilha_destroi(p_pilha) == NULL));


	printf("\n-------------------------------------------------------------\n");


	printf("\nTestes de inserção e remoção na pilha\n");
	
	/* Cria uma pilha de tam MAX_G */
	if (!(p_pilha = pilha_cria(MAX_G)))
	{
		fprintf(stderr, "Falha na alocação da pilha\n");
		return 0;
	}


	/* Preenche a pilha e verifica se o tamanho realmente é MAX_G */
	printf("\nTeste: verifica se o tamanho é %d após completar pilha\n", MAX_G);
	imprime_teste(MAX_G, completa_pilha(&p_pilha, MAX_G));

	/* Verifica se o status de saída para o caso de overflow é -1 */
	printf("\nTeste: verifica o status de saída para overflow\n");
	imprime_teste(-1, push(p_pilha, MAX_G));

	/* Verifica o valor do topo com a pilha cheia */
	printf("\nTeste: verifica se o topo é o índice da última posição\n");
	imprime_teste(MAX_G-1, pilha_topo(p_pilha));

	/* Teste para garantir que a consulta ao topo não alterou o seu valor */
	printf("\nTeste: o elem do topo continua o mesmo após a consulta\n");
	imprime_teste(MAX_G-1, pop(p_pilha));

	/* Como foi retirado um elemento o tamanho será MAX_G-1 */
	printf("\nTeste: verifica o tamanho após pop (%d - 1)\n", MAX_G);
	imprime_teste(MAX_G-1, pilha_tamanho(p_pilha));

	/* Teste para garantir que o pop manipula o topo corretamente */
	printf("\nTeste: vê se o topo foi decrementado após pop(%d - 2)\n", MAX_G);
	imprime_teste(MAX_G-2, pilha_topo(p_pilha));


	printf("\n-------------------------------------------------------------\n");


	printf("\nTestes de esvaziar a pilha\n");

	/* Esvazia a pilha após ter retirado um elemento */
	esvazia_pilha(&p_pilha, MAX_G-1);

	printf("\nTeste: verifica o tamanho após esvaziar a pilha\n");
	imprime_teste(0, pilha_tamanho(p_pilha));

	printf("\nTeste: vê se o topo voltou a posição inicial após esvaziar\n");
	imprime_teste(0, pilha_topo(p_pilha));

	printf("\nTeste: imprime a pilha vazia\n");
	compara_pilha(&p_pilha, 0);
	printf("\n");

	printf("\n-------------------------------------------------------------\n");


	pilha_destroi(p_pilha);
	return 0;
}
