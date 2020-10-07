// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

//typedef struct elemento* Lista;
typedef struct elemento Elemento;
typedef struct aluno Aluno;
typedef Elemento *Lista;

// funcoes adicionadas TAREFA
Aluno *criar_aluno(void);
Lista *remover_matriculas_repetidas(Lista *li);

// funções para alocar e desalocar memória
Lista *criar_lista(void);
int liberar_lista(Lista *li);

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li);
int inserir_lista_final(Lista *li);
int inserir_lista_ordenada(Lista *li);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_matricula(Lista *li);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li);
int buscar_lista_matricula(Lista *li);

int imprimir_lista(Lista *li);

#endif
