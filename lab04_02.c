#include<stdlib.h>
#include<stdio.h>


typedef struct SAresta *Aresta;
typedef struct SAresta
{
    int id;
    Aresta next;
}TAresta;

typedef struct SPessoa *Pessoa;
typedef struct SPessoa
{
    int pindicada;
    Aresta Indicadapor;
}TPessoa;

typedef struct SGrafo *Grafo;
typedef struct SGrafo
{
    Pessoa Pessoa;
    Aresta Aresta;
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
//MaximalInducedSubgraph(Grafo G, k)
//{
//    if (n<k+1)      // !find 1
//        H = ∅
//    else
//    if(every vertex of G has degree >= k) // !find 0
//        H = G
//    else
//    {
//        v = vertex wih degree < k
//        H = MaximalInducedSubgraph(G-v, k)
//    }
//    return (H)
//}


int main()
{
    int npessoas, i, j, k;
    int pessoaid, indica;
    Grafo G;
    G = AlocaG(1);

    scanf("%d", &npessoas);         // primeira entrada, numero de pessoas
    npessoas++;
    G->Pessoa = AlocaP(npessoas);
    G->Aresta = AlocaA(npessoas);

    // Inicializando Pessoas
    Inicializa(G, npessoas);


    for(i = 1; i < (npessoas); i++)
    {
        scanf("%d", &pessoaid);     // indice da pessoa atual que fará sua indicação
        scanf("%d", &indica);       // pessoa que a atual indicou
        G->Pessoa[pessoaid].pindicada = indica;
        // Inserindo Aresta ->indicada por, na pessoa indicada
        G->Pessoa[indica].Indicadapor = InsereAresta(pessoaid, G->Pessoa[indica].Indicadapor); // armazenando na pessoa indicada a pessoa que o indicou
    }

      for(i = 1; i < npessoas; i++)
    {
        printf("%d %d\n", i, G->Pessoa[i].pindicada);
        printf("pessoa %d  - \n",i);
        ImprimeAresta(G->Pessoa[i].Indicadapor);
        printf("\n");
    }
}
