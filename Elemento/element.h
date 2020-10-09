#include "../Aluno/aluno.h"

#ifndef _ELEMENT
#define _ELEMENT

typedef struct elemento
{
    Aluno dado;
    struct elemento *prox;

} Elemento;

Elemento *alocarElemento();

#endif