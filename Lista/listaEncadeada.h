#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

#include "../Aluno/aluno.h"
#include "../Elemento/element.h"

//typedef struct elemento* Lista;
typedef Elemento *Lista;

// funcoes adicionadas TAREFA
Lista *removerRepetidos(Lista *li);  // 2
Lista *inverterLista(Lista *li);     // 3
void verificarOrdenacao(Lista *li);  // 4
int tamanhoListaRecursiva(Lista li); // 5

// funcoes EXTRAS da tarefa
Lista *clonarLista(Lista *li);
int verificarDecrescente(Lista *li);
int verificarCrescente(Lista *li);

// funções para alocar e desalocar memória
Lista *alocarLista();
int liberarLista(Lista *li);

// funções para obter informações da lista
int tamanhoLista(Lista *li);
int listaVazia(Lista *li);

// funções para inserção de elementos da lista
int inserirInicio(Lista *li);
int inserirFinal(Lista *li);
int inserirOrdenada(Lista *li);

// funções para remoção de elementos da lista
int removerInicio(Lista *li);
int removerFinal(Lista *li);
int removerMatricula(Lista *li, int dado);

// funções para buscar elementos na lista
int buscarPosicao(Lista *li);
int buscarMatricula(Lista *li);

// Imprimir Elementos na lista
int imprimirLista(Lista *li);

#endif
