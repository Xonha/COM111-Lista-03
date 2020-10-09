#include <stdio.h>
#include <stdlib.h>
#include "../Aluno/aluno.h"

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
