#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

struct aluno
{
  int matricula;
  char nome[30];
  float nota;
};

struct elemento
{
  Aluno dado;
  Elemento *prox;
};

void preencherAluno(Aluno *al)
{
  printf("\nNome: ");
  scanf("%s", al->nome);
  printf("Matricula: ");
  scanf("%d", &al->matricula);
  printf("Nota: ");
  scanf("%f", &al->nota);
}

Aluno *alocarAluno()
{
  Aluno *al = (Aluno *)malloc(sizeof(Aluno));
  return al;
}

Elemento *alocarElemento()
{
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));
  return no;
}

Lista *alocarLista()
{
  Lista *li = (Lista *)malloc(sizeof(Lista));

  if (li != NULL)
    *li = NULL;

  return li;
}

int liberarLista(Lista *li)
{
  if (li == NULL) // verifica se a lista existe
    return 0;

  Elemento *no;

  while (*li != NULL)
  { // libera todos os nós da lista que foram alocados
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  free(li); // libera o ponteiro da lista

  return 1;
}

int tamanhoListaRecursiva(Lista li)
{
  if (li == NULL)
    return 0;

  return 1 + tamanhoListaRecursiva(li->prox);
}

int tamanhoLista(Lista *li)
{
  if (li == NULL) // verifica se a lista existe
    return 0;

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

int listaVazia(Lista *li)
{
  if (li == NULL) // verifica se houve problema na criação da lista
    return -1;    // ou seja, li não é uma lista válida

  if (*li == NULL) // verifica se a lista foi criada corretamente
    return 1;      // mas não contém nenhum valor

  return 0; // se houver elementos, retorna 0
}

int inserirInicio(Lista *li)
{
  if (li == NULL) // verifica se a lista existe
    return 0;

  Aluno *al = alocarAluno(); // cria um aluno novo
  preencherAluno(al);

  Elemento *no = alocarElemento(); // cria um elemento novo

  if (no == NULL)
    return 0; //  Verifica alocação

  // atribui valores ao elemento novo
  no->dado = *al;
  no->prox = (*li);

  // insere elemento no início da lista
  *li = no;

  return 1;
}

int inserirFinal(Lista *li)
{
  if (li == NULL) // verifica se a lista existe
    return 0;

  Aluno *al = alocarAluno(); // cria um aluno novo
  preencherAluno(al);

  Elemento *no = alocarElemento(); // cria um elemento novo

  if (no == NULL) // verifica se o no foi criado
    return 0;

  // atribui valores ao elemento novo
  no->dado = *al;
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if ((*li) == NULL)
    *li = no;
  else
  {
    // senão percorre a lista até o fim e insere no final
    Elemento *aux;
    aux = *li;

    while (aux->prox != NULL)
      aux = aux->prox;

    aux->prox = no;
  }

  return 1;
}

int inserirOrdenada(Lista *li)
{
  if (li == NULL) // verifica se a lista existe
    return 0;

  Aluno *al = alocarAluno(); // cria um aluno novo
  preencherAluno(al);

  Elemento *no = alocarElemento(); // cria um elemento novo

  if (no == NULL)
    return 0;

  no->dado = *al; // atribui valores ao elemento novo

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

int removerInicio(Lista *li)
{
  if (li == NULL) // verifica se a lista existe
    return 0;

  if ((*li) == NULL) // lista vazia, não remove nada
    return 0;

  Elemento *atual;

  atual = *li; // muda inicio para o proximo elemento
  *li = atual->prox;

  // libera Elemento atual
  free(atual);

  return 1;
}

// função para remover elemento do final da lista
int removerFinal(Lista *li)
{
  if (li == NULL) // verifica se a lista existe
    return 0;

  if ((*li) == NULL) // lista vazia, não remove nada
    return 0;

  Elemento *anterior, *atual;
  atual = *li;

  while (atual->prox != NULL)
  { // percorre lista até o final
    anterior = atual;
    atual = atual->prox;
  }

  // remove o primeiro elemento, se este for o único da lista
  if (atual == (*li))
    *li = atual->prox;
  else
    anterior->prox = atual->prox;

  free(atual); //libera Elemento atual

  return 1;
}

int removerMatricula(Lista *li)
{
  if (li == NULL) // verifica se a lista existe
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

  free(atual); //libera Elemento atual

  return 1;
}

int buscarPosicao(Lista *li)
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

int buscarMatricula(Lista *li)
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

int imprimirLista(Lista *li)
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
  printf("\n%d\t%.2f\t%s", aux->dado.matricula, aux->dado.nota, aux->dado.nome);

  return 1;
}

Lista *clonarLista(Lista *li)
{

  Lista *lista = alocarLista();

  for (Elemento *copia = *li; copia != NULL; copia = copia->prox)
  {

    Elemento *no = alocarElemento();
    Aluno *al = alocarAluno();

    al->matricula = copia->dado.matricula;
    al->nota = copia->dado.nota;

    no->dado = *al;
    no->prox = NULL;

    if ((*lista) == NULL)
      *lista = no;
    else
    {
      Elemento *aux;
      aux = *lista;

      while (aux->prox != NULL)
        aux = aux->prox;

      aux->prox = no;
    }
  }

  return lista;
}

Lista *inverterLista(Lista *li)
{
  Lista *lista = clonarLista(li);

  Lista *li2 = alocarLista();

  Elemento *copia = *lista;

  while (copia != NULL)
  {

    while (copia->prox != NULL)
      copia = copia->prox;

    Elemento *no = alocarElemento();
    Aluno *al = alocarAluno();

    al->matricula = copia->dado.matricula;
    al->nota = copia->dado.nota;

    no->dado = *al;
    no->prox = NULL;

    if ((*li2) == NULL)
      *li2 = no;
    else
    {
      Elemento *aux;
      aux = *li2;

      while (aux->prox != NULL)
        aux = aux->prox;

      aux->prox = no;
    }

    removerFinal(lista);
    copia = *lista;
  }

  return li2;
}
