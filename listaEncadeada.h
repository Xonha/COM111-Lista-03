#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

//typedef struct elemento* Lista;
typedef struct elemento Elemento;
typedef struct aluno Aluno;
typedef Elemento *Lista;

// funcoes adicionadas TAREFA
void preencherAluno(Aluno *al);

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

int imprimirLista(Lista *li);

#endif
