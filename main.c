#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.c"
#include "listaEncadeada.h"

int main(void)
{
  Lista *li = NULL;
  int opcao, ok;

  do
  { // menu de opções para execuções de operações sobre a lista
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
      li = alocarLista(); // criar lista
      break;

    case 2:
      ok = liberarLista(li); // liberar lista
      if (ok == 0)
        printf("\nLista não liberada!");
      break;

    case 3:
      ok = inserirInicio(li); // inserir elemento no início
      if (ok == 0)
        printf("\nFalha na inserção!");
      break;

    case 4:
      ok = inserirFinal(li); // inserir elemento no final
      if (ok == 0)
        printf("\nFalha na inserção!");
      break;

    case 5:
      ok = inserirOrdenada(li); // inserir elemento de forma ordenada
      if (ok == 0)
        printf("\nFalha na inserção!");
      break;

    case 6:
      ok = removerInicio(li); // remover elemento do início
      if (ok == 0)
        printf("\nFalha na remoção!");
      break;

    case 7:
      ok = removerFinal(li); // remover elemento do final
      if (ok == 0)
        printf("\nFalha na remoção!");
      break;

    case 8:
      ok = removerMatricula(li); // remover elemento do meio
      if (ok == 0)
        printf("\nFalha na remoção!");
      break;

    case 9:
      ok = buscarPosicao(li); // busca elemento pela posicao
      if (ok == 0)
        printf("\nPosição não existe!");
      break;

    case 10:
      ok = buscarMatricula(li); // busca elemento pelo dado
      if (ok == 0)
        printf("\nAluno não encontrado!");
      break;

    case 11:
      ok = imprimirLista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 12:
      ok = imprimirLista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 13:
      ok = imprimirLista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 14:
      ok = imprimirLista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 15:
      ok = imprimirLista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista não encontrada!");
      break;

    case 16:
      ok = tamanhoListaRecursiva(*li); // Calcula o tamanho da lista
      printf("\nTamanho da lista: %i", ok);
      break;

    default:
      liberarLista(li);
      printf("\nFinalizando...\n\n");
      break;
    }
  } while (opcao != 0);

  return 0;
}
