#include<stdlib.h>
#include<stdio.h>


typedef struct SAresta *Aresta;
typedef struct SAresta
{
    int id;
    Aresta next;
}TAresta;

typedef struct SH *H;
typedef struct SH
{
    int id;
    int flag;
    H indicado;
    H previous;
    H next;
}TH;
typedef struct SH *H;

typedef struct SPessoa *Pessoa;
typedef struct SPessoa
{
    int pindicada;
    int id;
    Aresta Indicadapor;
}TPessoa;

typedef struct SGrafo *Grafo;
typedef struct SGrafo
{
    Pessoa Pessoa;
    Aresta Aresta;
    int *flags;
}TGrafo;

void Inicializa(Grafo G, int npessoas)
{
    int i;
    for(i = 0; i < (npessoas); i++)
    {
        G->Pessoa[i].Indicadapor = NULL;
        G->Aresta[i].next = NULL;
        G->Aresta[i].id = 0;
    }
}

void InicializaFlags(int *flags, int n)
{
    int i;
    for (i=0; i<n; i++)
        flags[i] = 0;
}

void ImprimeFlags(int *flags, int n)
{
    int i;
    printf("%d", flags[1]);
    for( i=2; i< n; i++)
        printf(" %d", flags[i]);

}

Grafo AlocaG(int n)
{
    return n > 0 ? (Grafo)malloc(n*sizeof(TGrafo)) : NULL ;
}

Pessoa AlocaP(int n)
{
    return (n > 0) ? (Pessoa)malloc(n*sizeof(TPessoa)) : NULL ;
}

Aresta AlocaA(int n)
{
    return (n > 0) ? (Aresta)malloc(n*sizeof(TAresta)) : NULL ;
}

void AlocaG2(Grafo G, int n)
{
    G->Pessoa = AlocaP(n);
    G->Aresta = AlocaA(n);
    G->flags = malloc(n*sizeof(int));
}
void AlocaH(H G)
{
    G = (H)malloc(sizeof(TH));
    G->flag = 1;
    G->indicado = NULL;
    G->next = NULL;
    G->previous = NULL;
}
void RemoveH(H G)
{
    H aux;
     if(G)
    {
        G->previous->next = G->next;
        G->indicado->flag--;
        free(aux);
    }
}
Aresta InsereAresta(int id, Aresta X)
{
    if(!X)
    {
        X = AlocaA(1);
        X->id = id;
        X->next = NULL;
    }
    else
    {
        X->next = InsereAresta(id, X->next);
    }
    return X;
}

void ImprimeAresta(Aresta X)
{
    if(X)
    {
        printf("indicada por %d\n", X->id);
        if(X->next)
            ImprimeAresta(X->next);
    }
}

void ImprimeGrafo(Grafo G, int *flags, int n)
{
    int i;
    if(G)
    {
        for( i = 1; i<=n; i++)
        {
            if(flags[i])
                printf("%d ", G->Pessoa[i].id);
        }
    }
}

void ImprimeGrafoH(Grafo H, int n)
{
    int i;
    if(H)
    {
        for( i = 1; i<=n; i++)
            printf("%d ", H->Pessoa[i].id);
        }
}

int find1(int *flags, int n)
{
    int i;
    for(i = 1; i < n; i++)
        if(flags[i])
            return i;
    return 0;
}

int find0(int *flags, int n)
{
    int i;
    for(i = 1; i < n; i++)
        if(!flags[i])
            return i;
    return 0;
}
Grafo MaximalInducedSubgraph(Grafo G, int *flags, int n)
{
    Grafo H;
    int aux;
    if (!find1(flags, n))      // !find 1
        H = NULL;
    else
    if(!(aux=find0(flags, n))) // !find 0
        H = G;
    else
    {

        //v = vertex wih degree < k
        //H = MaximalInducedSubgraph(G-v, k)
    }
    return (H);
}


int main()
{
    int npessoas, i, j, k = 0;
    int pessoaid, indica;
    int *flags;
    int *flag2;
    Grafo G;
    H ListaH;
    G = AlocaG(1);
    ListaH = AlocaH;

    scanf("%d", &npessoas);         // primeira entrada, numero de pessoas
    npessoas++;                 //Desconsiderar posição zero do vetor

    AlocaG2(G, npessoas);
    flags = malloc(npessoas*sizeof(int));

    // Inicializando Pessoas
    Inicializa(G, npessoas);
    InicializaFlags(flags, npessoas);


    for(i = 1; i < (npessoas); i++)
    {
        scanf("%d", &pessoaid);     // indice da pessoa atual que fará sua indicação
        scanf("%d", &indica);       // pessoa que a atual indicou
        if(!flags[indica])
        {
            InsereH(ListaH, indica);
        }
        flags[indica]++;
        G->Pessoa[pessoaid].id = pessoaid;
        G->Pessoa[pessoaid].pindicada = indica;
        // Inserindo Aresta ->indicada por, na pessoa indicada
        // armazenando na pessoa indicada a pessoa que o indicou
        G->Pessoa[indica].Indicadapor = InsereAresta(pessoaid, G->Pessoa[indica].Indicadapor);
    }

    ImprimeFlags(flags, npessoas);
    printf("\n");
    ImprimeGrafo(G, flags, npessoas);
    printf("\n");
    ImprimeGrafoH(H, k);

    MaximalInducedSubgraph(G, flags, npessoas);
}
