#ifndef _ALUNO
#define _ALUNO

typedef struct aluno
{
    int matricula;
    char nome[30];
    float nota;

} Aluno;

void preencherAluno(Aluno *al); //  A

Aluno *alocarAluno();

#endif