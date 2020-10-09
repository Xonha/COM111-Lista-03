#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

#include "../Aluno/aluno.h"
#include "../Elemento/element.h"

//typedef struct elemento* Lista;
typedef Elemento *Lista;

// funcoes adicionadas TAREFA
int tamanhoListaRecursiva(Elemento *cabeca); //  5
void tamanho(Lista *cabeca, Aluno novodado);

// funções para alocar e desalocar memória
Aluno *alocarAluno(void);
Lista *alocarLista(void);
Elemento *alocarElemento(void);
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
int removerMatricula(Lista *li);

// funções para buscar elementos na lista
int buscarPosicao(Lista *li);
int buscarMatricula(Lista *li);

// Imprimir Elementos na lista
int imprimirLista(Lista *li);

#endif
