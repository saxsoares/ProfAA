#include <stdio.h>
#include <stdlib.h>

int compara(x, y)

void *x, *y; /* Declaração antiga do ANSI C, mas muito útil */
{
    if ( *(int*)x > *(int*)y )
       return 1;
    else if ( *(int*)x == *(int*)y )
            return 0;
    else if ( *(int*)x < *(int*)y )
            return -1;
}

int remove(int x, int *seraconv, int *auxconvidado)
{
    seraconv[x] = 0;
    return auxconvidado[x]
}

int main()
{
    int nconvidados, indica, i;
    int *convidado, *auxconvidado, *seraconv; // convidado armazena quem o item indicou, indicado armazena por quem foi indicado

    scanf("%d", &nconvidados);
    nconvidados = nconvidados + 1;

    convidado = (int *) malloc(nconvidados* sizeof(int));
    auxconvidado = (int *) malloc(nconvidados* sizeof(int));
    seraconv = (int *) malloc(nconvidados* sizeof(int));

    for(i=0; i<nconvidados; i++)
        seraconv[i] = 1;

    for(i=0; i<nconvidados; i++)
    {
        scanf("%d", &indica); // atual que esta indicando
        scanf("%d", &convidado[indica]); // quem ele indicou
        auxconvidado[indica] = convidado[indica];

    }

    qsort(convidado, nconvidados, sizeof(int), compara);


}
