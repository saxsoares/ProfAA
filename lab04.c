#include <stdio.h>
#include <stdlib.h>


typedef struct SPessoa *Pessoa;
typedef struct SPessoa{
    int id;
    int indre;
    int pind;
}TPessoa;

typedef struct SLista *Lista;
typedef struct SLista{
    Pessoa P;
    Pessoa next;
    Pessoa previous;
}TLista;

Lista AlocaL(int n)
{
    return n > 0 ? (Lista)malloc(n*sizeof(TLista)) : NULL;
}

Pessoa AlocaP(int n)
{
    return n > 0 ? (Pessoa)malloc(n*sizeof(TPessoa)) : NULL;
}

int AlocaF()
{

}

void InicializaL(Lista L, int n)
{
    int i;
    L->P = AlocaP(1);
        L->P[i].id = 0;
        L->P[i].indre = 0;
        L->P[i].pind = 0;
}

int find1(Lista L, int n)
{
    int i;
    for(i = 1; i < n; i++)
        if(L->P[i].indre)
            return i;
    return 0;
}

int find0(Lista L, int n)
{
    int i;
    for(i = 1; i < n; i++)
        if(!L->P[i].indre)
            return i;
    return 0;
}

Lista MaximalInducedSubgraph(Lista L, int k)
{
    Lista H;
    int v;
    H = AlocaL(1);
    if (!find1(L, k))      // !find 1
        H = NULL;
    else
    if(!(v=find0(L, k))) // !find 0
        H = L;
    else
    {
        L->P[ L->P[v].pind ].indre--;
        L->P[v].indre = -1;
        H = MaximalInducedSubgraph(L, k);
    }
    return (H);
}

int main()
{
    int i = 0, j = 0 ,k = 0;
    int npessoas, pid, pindicada, *flag;
    Lista L, aux;

    scanf("%d", &npessoas);
    npessoas++;
    L = AlocaL(1);
    InicializaL(L, npessoas);

    for( i = 1; i < npessoas; i++)
    {
        scanf("%d", &pid);
        scanf("%d", &pindicada);
        if( i == 1)
            InsereRaiz(L,  pid,pindicada);
        else
            InsereP(L, pid, pindicada);
    }

    L = MaximalInducedSubgraph(L, npessoas);
    for( i = 1; i< npessoas; i++)
        if(L->P[i].indre > 0)
            printf("%d ", L->P[i].id);

}
