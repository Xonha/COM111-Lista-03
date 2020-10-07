#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.c"
#include "listaEncadeada.h"

int main(void)
{
  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  Lista *li2 = NULL;
  int opcao, ok, pos;
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
    printf("\n09 - Buscar posicao");
    printf("\n10 - Buscar matricula");
    printf("\n11 - Imprimir");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
      li = criar_lista(); // criar lista
      break;

    case 2:
      ok = liberar_lista(li); // liberar lista
      if (ok == 0)
        printf("\nLista não liberada!");
      break;

    case 3:
      ok = inserir_lista_inicio(li); // inserir elemento no início
      if (ok == 0)
        printf("\nFalha na inserção!");
      break;

    case 4:
      ok = inserir_lista_final(li); // inserir elemento no final
      if (ok == 0)
        printf("\nFalha na inserção!");
      break;

    case 5:
      ok = inserir_lista_ordenada(li); // inserir elemento de forma ordenada
      if (ok == 0)
        printf("\nFalha na inserção!");
      break;

    case 6:
      ok = remover_lista_inicio(li); // remover elemento do início
      if (ok == 0)
        printf("\nFalha na remoção!");
      break;

    case 7:
      ok = remover_lista_final(li); // remover elemento do final
      if (ok == 0)
        printf("\nFalha na remoção!");
      break;

    case 8:
      ok = remover_lista_matricula(li); // remover elemento do meio
      if (ok == 0)
        printf("\nFalha na remoção!");
      break;

    case 9:
      ok = buscar_lista_posicao(li); // busca elemento pela posicao
      if (ok == 0)
        printf("\nPosição não existe!");
      break;

    case 10:
      ok = buscar_lista_matricula(li); // busca elemento pelo dado
      if (ok == 0)
        printf("\nAluno não encontrado!");
      break;

    case 11:
      ok = imprimir_lista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 12:
      li2 = remover_matriculas_repetidas(li); // imprime a lista
      if (li2 == 0)
        printf("\nLista não encontrada!");
      imprimir_lista(li2);
      break;

    case 13:
      ok = imprimir_lista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 14:
      ok = imprimir_lista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 15:
      ok = imprimir_lista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 16:
      ok = imprimir_lista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    default:
      liberar_lista(li);
      printf("\nFinalizando...\n\n");
      break;
    }
  } while (opcao != 0);

  return 0;
}
