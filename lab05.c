#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item{
    int v;
    int m;
}Titem;

void Imprime(char *S)
{
    printf("%s", S);
}

int main()
{
    char S[200], Si[200];
    Titem c[200][200];
    int Slen, i, j, k, l, n;
    int *mut;

    scanf("%s", S);

    Slen = strlen(S);
    mut = malloc(Slen * sizeof(int));


    scanf("%d", &n);

    for(i = 0; i < Slen; i++) mut[i] = 0; // INICIALIZANDO VETOR DE MUTACOES

    for(i = 0; i < Slen; i++){  ///Inicializando diagonal
            c[i][i].m = 0;
            c[i][i].v = 1;
    }

    for(i = 1; i <= n; i++){
        scanf("%d", &k);
        mut[k-1] = 1;
        c[k-1][k-1].m = 1;
    }

    j = 1;
    for(i = 0; i<Slen -1; i++){
        if(S[i] == S[j]){
            c[i][j].v = 2;
            c[i][j].m = mut[i] + mut[j];
        }
        else{
            if(c[i+1][j].m > c[i][j-1].m){
                c[i][j].v = c[i+1][j].v;
                c[i][j].m = c[i+1][j].m;
            }
            else
            if(c[i+1][j].m < c[i][j-1].m){
                c[i][j].v = c[i][j-1].v;
                c[i][j].m = c[i][j-1].m;
            }
            else
            if(c[i+1][j].m == c[i][j-1].m){
                if(c[i+1][j].v >= c[i][j-1].v){
                    c[i][j].v = c[i+1][j].v;
                    c[i][j].m = c[i+1][j].m;
                }
                else
                if(c[i+1][j].v < c[i][j-1].v){
                    c[i][j].v = c[i][j-1].v;
                    c[i][j].m = c[i][j-1].m;
                }
            }
        }
        j++;
    }
}


