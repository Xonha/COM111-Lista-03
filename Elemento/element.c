#include <stdlib.h>

#include "element.h"
#include "../Aluno/aluno.h"

Elemento *alocarElemento()
{
    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    return no;
}
