#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

struct aluno
{
  int matricula;
  char nome[30];
  float nota;
};
// definição do struct elemento
struct elemento
{
  Aluno dado;
  Elemento *prox;
};

Aluno *criar_aluno()
{
  Aluno *al = (Aluno *)malloc(sizeof(Aluno));

  printf("\nNome: ");
  scanf("%s", al->nome);
  printf("Matricula: ");
  scanf("%d", &al->matricula);
  printf("Nota: ");
  scanf("%f", &al->nota);

  return al;
}

// função para alocar memória do tipo Elemento
Elemento *criar_elemento()
{
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));

  return no;
}

// função para alocar memória do tipo Lista
Lista *criar_lista()
{
  Lista *li = (Lista *)malloc(sizeof(Lista));

  // se a lista foi criada corretamente, indica que ela está vazia
  if (li != NULL)
  {
    *li = NULL;
    printf("\nLista criada com sucesso!");
  }
  else
    printf("\nLista não criada!");
  return li;
}

// função para liberar memória
int liberar_lista(Lista *li)
{
  if (li == NULL)
  {
    printf("\n Lista nao existe!");
    return 0;
  }

  // libera todos os nós da lista que foram alocados
  Elemento *no;
  while (*li != NULL)
  {
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  // libera o ponteiro da lista
  free(li);

  printf("\nLista liberada com sucesso!");

  return 1;
}

// função para obter o tamanho da lista
int tamanho_lista(Lista *li)
{
  // a lista não foi criada corretamente
  if (li == NULL)
  {
    return 0;
  }

  int cont = 0;
  Elemento *no = *li;

  // acrescenta cont até acabar a lista
  while (no != NULL)
  {
    cont++;
    no = no->prox;
  }

  return cont;
}

// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, li não é uma lista válida
  if (li == NULL)
  {
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor
  if (*li == NULL)
  {
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}

// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li)
{
  if (li == NULL)
    return 0; // Se lista nao existe

  Aluno *al; // cria um aluno novo
  al = criar_aluno();

  Elemento *no; // cria um elemento novo
  no = criar_elemento();

  if (no == NULL)
    return 0; //  Verifica alocação

  // atribui valores ao elemento novo
  no = al;
  no->prox = (*li);

  // insere elemento no início da lista
  *li = no;
  printf("\nInserção realizada com sucesso!");

  return 1;
}

// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li)
{
  if (li == NULL)
    return 0;

  Aluno *al; // cria um aluno novo
  al = criar_aluno();

  Elemento *no; // cria um elemento novo
  no = criar_elemento();

  if (no == NULL)
    return 0;

  // atribui valores ao elemento novo
  no = al;
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if ((*li) == NULL)
  {
    *li = no;
  }
  else
  {
    // senão percorre a lista até o fim e insere no final
    Elemento *aux;
    aux = *li;

    while (aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = no;
  }

  printf("\nInserção realizada com sucesso!");

  return 1;
}

// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li)
{
  if (li == NULL)
    return 0;

  Aluno *al; // cria um aluno novo
  al = criar_aluno();

  Elemento *no; // cria um elemento novo
  no = criar_elemento();

  if (no == NULL)
    return 0;

  no = al; // atribui valores ao elemento novo

  // se a lista estiver vazia, insere no início da lista
  if ((*li) == NULL)
  {
    no->prox = NULL;
    *li = no;
  }
  else
  {
    // senão percorre a lista até achar o local correto e insere
    Elemento *anterior, *atual;
    atual = *li;

    while (atual != NULL && atual->dado.matricula < al->matricula)
    {
      anterior = atual;
      atual = atual->prox;
    }

    // insere na primeira posição
    if (atual == (*li))
    {
      no->prox = (*li);
      *li = no;
    }
    else
    {
      no->prox = atual;
      anterior->prox = no;
    }
  }

  return 1;
}

// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li)
{
  if (li == NULL)
  {
    return 0;
  }

  // lista vazia, não remove nada
  if ((*li) == NULL)
  {
    return 0;
  }

  // muda inicio para o proximo elemento
  Elemento *atual;
  atual = *li;
  *li = atual->prox;

  // libera Elemento atual
  free(atual);

  printf("\nRemoção realizada com sucesso!");

  return 1;
}

// função para remover elemento do final da lista
int remover_lista_final(Lista *li)
{
  if (li == NULL)
  {
    return 0;
  }

  // lista vazia, não remove nada
  if ((*li) == NULL)
  {
    return 0;
  }

  // percorre lista até o final
  Elemento *anterior, *atual;
  atual = *li;

  while (atual->prox != NULL)
  {
    anterior = atual;
    atual = atual->prox;
  }

  // remove o primeiro elemento, se este for o único da lista
  if (atual == (*li))
  {
    *li = atual->prox;
  }
  else
  {
    anterior->prox = atual->prox;
  }

  //libera Elemento atual
  free(atual);

  printf("\nRemoção realizada com sucesso!");

  return 1;
}

// função para remover elemento do meio da lista
int remover_lista_matricula(Lista *li)
{
  if (li == NULL)
    return 0;

  if ((*li) == NULL) // lista vazia, não remove nada
    return 0;

  printf("\nMatricula a ser removido: ");
  int dado;
  scanf("%d", &dado);

  Elemento *anterior, *atual;
  atual = *li;

  while (atual != NULL && atual->dado.matricula != dado)
  { // percorre a lista até achar o elemento e remove
    anterior = atual;
    atual = atual->prox;
  }

  // elemento não foi encontrado
  if (atual == NULL)
    return 0;

  if (atual == (*li)) // remove o primeiro elemento
    *li = atual->prox;
  else
    anterior->prox = atual->prox;

  //libera Elemento atual
  free(atual);

  return 1;
}

int buscar_lista_posicao(Lista *li)
{
  printf("\nPosição do aluno na lista: ");
  int pos;
  scanf("%d", &pos);

  // verifica se a lista foi criada corretamente, se não está vazia e se a posição é válida (note que é a posição na lista e não o índice do vetor)
  if (li == NULL || (*li) == NULL || pos <= 0)
    return 0;

  Lista no = *li;
  int i = 1;

  while (no != NULL && i < pos)
  {
    no = no->prox;
    i++;
  }

  if (no == NULL) // posição não existe na lista
    return 0;

  printf("\nAluno em %dº da lista: ", pos);
  printf("%s\t%i", no->dado.nome, no->dado.matricula);

  return 1;
}

int buscar_lista_matricula(Lista *li)
{
  printf("\nMatricula do aluno a ser buscado: ");
  int matricula;
  scanf("%d", &matricula);

  // procura a posição no vetor onde o dado desejado se encontra
  Elemento *no = *li;
  int i = 1;

  while (no != NULL && no->dado.matricula != matricula)
  {
    no = no->prox;
    i++;
  }

  if (no == NULL) // verifica se elemento não foi encontrado
    return 0;

  printf("\nAluno de matricula %d: ", matricula);
  printf("%s", no->dado.nome);

  return 1;
}

//**************************************************************************
// função para imprimir a lista dinâmica
int imprimir_lista(Lista *li)
{
  if (li == NULL || (*li) == NULL)
    return 0;

  Elemento *aux = (*li);

  printf("\nLista de alunos: ");
  printf("\n[Matricula]\t[Nota]\t[Nome]");

  while (aux->prox != NULL)
  {
    printf("\n%d\t%.2f\t%s", aux->dado.matricula, aux->dado.nota, aux->dado.nome);
    aux = aux->prox;
  }
  //printf("\n%s\t%d\t%.2f\n", aux->dado.nome, aux->dado.matricula, aux->dado.nota);
  printf("\n%d\t%.2f\t%s", aux->dado.matricula, aux->dado.nota, aux->dado.nome);
  return 1;
}

Lista *remover_matriculas_repetidas(Lista *li)
{
  Elemento *copia = *li;

  return li;
}

/*
Lista *remover_matriculas_repetidas(Lista *li)
{
  Lista *li2 = NULL;
  li2 = criar_lista();

  *li2 = *li;

  Elemento *no = *li2;

  do
  {
    no = no->prox;
  } while (no != NULL);

  return li2;
} 

Elemento *remove_duplicados(Elemento *agenda)
{
  Elemento *a;
  Elemento *p;
  Elemento *q;

  for (p = agenda; p != NULL; p = p->prox)
  {
    a = NULL; //a cada varrimento a começa a NULL

    for (q = p->prox; q != NULL;)
    { //sem incremento
      if (0 == strcmp(p->info.nome, q->info.nome))
      { //teste de igual
        if (a == NULL)
        { //remove do inicio
          p->prox = q->prox;
        }
        else
        { //ou do meio/fim
          a->prox = q->prox;
        }

        Elemento *remover = q;
        q = q->prox;
        free(remover);
      }
      else
      { //so atualiza o anterior quando não é igual
        a = q;
        q = q->prox;
      }
    }
  }

  return agenda;
}
*/