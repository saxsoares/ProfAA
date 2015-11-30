#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int quickSort_particao(int *A, int p, int r)
{
    int i = p-1, j = p;
    int pivo = r;
    int aux;

    for(j = p; j< r; j++)
    {
        if(A[j] < A[pivo])
        {
            i++;
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    aux = A[i+1];
    A[i+1] = A[j];
    A[j] = aux;

    return i+1;
    // Implemente o seu metodo aqui!
}

void quickSort_ordena(int *A, int p, int r)
{
    int i;

    if (r > p)
    {
       i = quickSort_particao(A, p, r);
       quickSort_ordena(A, p, i-1 );
       quickSort_ordena(A, i+1, r);
    }
    // Implemente o seu metodo aqui!
}

void quickSort(int *A, int n)
{
    if(n)
        quickSort_ordena(A, 0, n-1);
    // Implemente o seu metodo aqui!
}

typedef struct item{
    int v;
    int m;
}Titem;

int main()
{
    char S[200], Si[200];
    Titem c[200][200];
    int Slen, *n, i, j, k, l;
    int *mut;
    n = malloc(sizeof(int));

    scanf("%s", S);
    Slen = strlen(S);

    scanf("%d", n);
    mut = malloc((*n)*sizeof(int));
    for(k = 0; k < (*n); k++){
        scanf("%d", &i);
        mut[k]= i-1;
    }
    if(n)
        quickSort(mut, *n);

    i = 0;
    for(j = Slen-1; j >=0; j--)
    {
        Si[i] = S[j];
        i++;
    }

    for(i = 0; i < Slen; i++){
        c[i][-1].v = 0;
        c[i][-1].m = 0;
    }
    for(j = -1; j < Slen; j++){
        c[-1][j].v = 0;
        c[-1][j].m = 0;
    }

    for(i = 0; i < Slen; i++){
        for(j = 0; j < Slen ; j++){
            if (S[i] == Si[j] ){
                    printf("%d,%d -> %d\n", i,j,c[i-1][j-1].m);
                    c[i][j].v = c[i-1][j-1].v+1;
                    c[i][j].m = c[i-1][j-1].m;
            }
            else
            if( c[i-1][j].m > c[i][j-1].m ){
                c[i][j].v = c[i-1][j].v;
                c[i][j].m = c[i-1][j].m;
            }
            else
            if( c[i-1][j].m == c[i][j-1].m ){
                if(c[i-1][j].v >= c[i][j-1].v){
                    c[i][j].v = c[i-1][j].v;
                    c[i][j].m = c[i-1][j].m;
                }
                else{
                    c[i][j].v = c[i][j-1].v;
                    c[i][j].m = c[i][j-1].m;
                }
            }
            else{
                c[i][j].v = c[i][j-1].v;
                c[i][j].m = c[i][j-1].m;
            }
        }
    }
    printf("%d", c[Slen-1][Slen-1].v);
}

