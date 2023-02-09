/* 
	Feito por Nico Ramos - GRR20210574
*/

#include "libpilha.h"
#include "libfila.h"
#include "liblista.h"

#define MAX_G 255
#define MAX_P 10

/* ---------------------------------------------------- */

/* Funções auxiliares gerais */

/* Função que imprime o resultado esperado e o resultado recebido */
void imprime_teste(int esp, int result);

/* Função que imprime uma sequência de 0 até max */
void imprime_seq (int max);

/* ---------------------------------------------------- */

/* Funções auxiliares para a pilha */

/* Função que completa uma pilha com valores de 0 até max */
/* Retorna o tamanho após inserir max elementos */
int completa_pilha(pilha_t **pp_pilha, int max);

/* Função que retira todos os elementos da pilha */
void esvazia_pilha(pilha_t **pp_pilha, int max);

/* Função que imprime a pilha esperada e a pilha de fato */
void compara_pilha(pilha_t **pp_pilha, int max);

/* ---------------------------------------------------- */

/* Funções auxiliares para a fila */

/* Função que preenche uma fila com valores de 0 até max */
void preenche_fila(fila_t **pp_fila, int max);

/* Função que retira todos os elementos da fila */
void esvazia_fila(fila_t **pp_fila, int fim);

/* Função que imprime a fila esperada e a fila de fato */
void compara_fila(fila_t **pp_fila, int max);

/* ---------------------------------------------------- */

/* Funções auxiliares para a lista */

/* Função que preenche uma lista com valores de 0 até max */
/* Pode preencher pelo inicio, fim ou ordenado */
void preenche_lista(lista_t **pp_lista, int max, char* opcao);

/* Função que retira todos os elementos da lista */
void esvazia_lista(lista_t **pp_lista, int max, char* opcao);

/* Função que imprime a fila esperada e a fila de fato */
void compara_lista(lista_t **pp_lista, int max);

/* Função que destrói a lista recebida e a recria com max elem */
int recria_lista(lista_t **pp_lista, int max);