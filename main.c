#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.c"
#include "listaEncadeada.h"

int main(void)
{
  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  int opcao, dado, ok, pos;

  Aluno *al;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\n\nMenu de opções");
    printf("\n00 - Sair");
    printf("\n01 - Criar lista");
    printf("\n02 - Liberar lista");
    printf("\n03 - Inserir início");
    printf("\n04 - Inserir final");
    printf("\n05 - Inserir ordenado");
    printf("\n06 - Remover início");
    printf("\n07 - Remover final");
    printf("\n08 - Remover matricula");
    printf("\n09 - Buscar posição");
    printf("\n10 - Buscar dado");
    printf("\n11 - Imprimir");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
      li = criar_lista(); // criar lista

      if (li != NULL)
        printf("\nLista criada com sucesso!");
      else
        printf("\nLista não criada!");

      break;

    case 2:
      ok = liberar_lista(li); // liberar lista

      if (ok)
        printf("\n Lista liberada com sucesso!");
      else
        printf("\n Lista não liberada!");

      break;

    case 3:
      al = criar_aluno();
      ok = inserir_lista_inicio(li, *al); // inserir elemento no início

      if (ok == 1)
        printf("\n Inserção realizada com sucesso!");
      else
        printf("\n Falha na inserção!");

      break;

    case 4:
      al = criar_aluno();
      ok = inserir_lista_final(li, *al); // inserir elemento no final

      if (ok == 1)
        printf("\n Inserção realizada com sucesso!");
      else
        printf("\n Falha na inserção!");

      break;

    case 5:
      al = criar_aluno();
      ok = inserir_lista_ordenada(li, *al); // inserir elemento de forma ordenada

      if (ok == 1)
        printf("\n Inserção realizada com sucesso!");
      else
        printf("\n Falha na inserção!");

      break;

    case 6:
      ok = remover_lista_inicio(li); // remover elemento do início

      if (ok == 1)
        printf("\n Remoção realizada com sucesso!");
      else
        printf("\n Falha na remoção!");

      break;

    case 7:
      ok = remover_lista_final(li); // remover elemento do final

      if (ok == 1)
        printf("\n Remoção realizada com sucesso!");
      else
        printf("\n Falha na remoção!");

      break;

    case 8:
      printf("\nNúmero a ser removido: ");
      scanf("%d", &dado);

      ok = remover_lista_matricula(li, *al); // remover elemento do meio

      if (ok == 1)
        printf("\n Remoção realizada com sucesso!");
      else
        printf("\n Falha na remoção!");
      break;

    case 9:
      printf("\n Posição do elemento a ser buscado: ");
      scanf("%d", &pos);
      // busca elemento pela posicao
      ok = buscar_lista_posicao(li, pos, al);

      if (ok)
      {
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento da %dª posição: ", pos);
        printf("%d", dado);
      }
      else
      {
        printf("\n Posição não existe!");
      }

      break;

    case 10:
      printf("\n Código do produto a ser buscado: ");
      scanf("%d", &dado);
      // busca elemento pelo dado
      ok = buscar_lista_dado(li, *al, &pos);

      if (ok)
      {
        printf("\n Busca realizada com sucesso!");
        printf("\n Elemento da %dª posição: ", pos);
        printf("%d", dado);
      }
      else
        printf("\n Elemento não encontrado!");

      break;

    case 11:
      printf("\nLista de alunos: ");
      printf("\n[Matricula]\t[Nota]\t[Nome]");

      ok = imprimir_lista(li); // imprime a lista

      if (!ok)
        printf("\n Lista não encontrada!");

      break;

    default:

      liberar_lista(li);

      printf("\nFinalizando...\n\n");

      break;
    }
  } while (opcao != 0);

  return 0;
}
