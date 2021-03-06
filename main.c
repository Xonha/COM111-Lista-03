#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"
#include "listaEncadeada.c"

int main(void)
{
  Lista *li = NULL;
  Lista *li2 = NULL;
  Lista *li3 = NULL;
  Lista *li4 = NULL;
  Lista *li5 = NULL;
  int opcao, ok, valor;

  do
  { // menu de opções para execuções de operações sobre a lista
    printf("\n\n################# MENU DE OPCOES #################");
    printf("\n 0 - Sair\t\t\t\t\t 1 - Criar lista");
    printf("\n 2 - Liberar lista\t\t\t 3 - Inserir início");
    printf("\n 4 - Inserir final\t\t\t 5 - Inserir ordenado");
    printf("\n 6 - Remover início\t\t\t 7 - Remover final");
    printf("\n 8 - Remover matricula\t\t 9 - Buscar posicao");
    printf("\n10 - Buscar matricula\t\t11 - Imprimir");
    printf("\n12 - Concatenar listas\t\t13 - Remover repetidos");
    printf("\n14 - Inverter lista\t\t15 - Verifica ordenada");
    printf("\n16 - Tamanho lista\t\t");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 0:
      liberarLista(li);
      printf("\nFinalizando...\n\n");
      break;
    case 1:
      li = alocarLista(); // criar lista

      if (li != NULL)
        printf("\nLista criada com sucesso!");
      else
        printf("\nLista não criada!");
      break;

    case 2:
      ok = liberarLista(li); // liberar lista
      if (ok == 1)
        printf("\nLista liberada com sucesso!");
      else
        printf("\nLista nao liberada!");
      break;

    case 3:
      ok = inserirInicio(li); // inserir elemento no início
      if (ok == 1)
        printf("\nInsercao realizada com sucesso!");
      else
        printf("\nFalha na insercao!");
      break;

    case 4:
      ok = inserirFinal(li); // inserir elemento no final
      if (ok == 1)
        printf("\nInsercao realizada com sucesso!");
      else
        printf("\nFalha na insercao!");
      break;

    case 5:
      ok = inserirOrdenada(li); // inserir elemento de forma ordenada
      if (ok == 1)
        printf("\nInsercao realizada com sucesso!");
      else
        printf("\nFalha na insercao!");
      break;

    case 6:
      ok = removerInicio(li); // remover elemento do início
      if (ok == 1)
        printf("\nRemocao realizada com sucesso!");
      else
        printf("\nFalha na remocao!");
      break;

    case 7:
      ok = removerFinal(li); // remover elemento do final
      if (ok == 1)
        printf("\nRemocao realizada com sucesso!");
      else
        printf("\nFalha na remocao!");
      break;

    case 8:
      printf("\nMatricula a ser removido: ");
      scanf("%d", &valor);

      ok = removerMatricula(li, valor); // remover elemento do meio

      if (ok == 1)
        printf("\nRemocao realizada com sucesso!");
      else
        printf("\nFalha na remocao!");
      break;

    case 9:
      ok = buscarPosicao(li); // busca elemento pela posicao
      if (ok == 0)
        printf("\nPosição nao existe!");
      break;

    case 10:
      ok = buscarMatricula(li); // busca elemento pelo dado
      if (ok == 0)
        printf("\nAluno nao encontrado!");
      break;

    case 11:
      ok = imprimirLista(li); // imprime a lista
      if (ok == 0)
        printf("\nLista nao encontrada!");
      break;

    case 12:
      li3 = concatenarListas(li, li2); // remove itens repetidos da lista
      if (ok == 0)
        printf("\nLista nao encontrada!");
      imprimirLista(li3);
      break;

    case 13:
      li4 = removerRepetidos(li); // remove itens repetidos da lista
      if (ok == 0)
        printf("\nLista nao encontrada!");
      imprimirLista(li3);
      break;

    case 14:
      li5 = inverterLista(li); // inverte a lista
      if (!li5)
        printf("\nLista nao encontrada!");
      imprimirLista(li5);
      break;

    case 15:
      verificarOrdenacao(li); // verifica se a lista esta ordenada
      break;

    case 16:
      ok = tamanhoListaRecursiva(*li); // Calcula o tamanho da lista
      printf("\nTamanho da lista: %i", ok);
      break;

    default:
      printf("\nOpcao invalida!");
      break;
    }
  } while (opcao != 0);

  return 0;
}
