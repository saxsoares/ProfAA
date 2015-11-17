#include <stdio.h>
#include <stdlib.h>

//
/* representação de uma aresta */
typedef struct SEdge *apEdge;
typedef struct SEdge
{
    int c; /* 'peso' ou 'custo' associado à aresta */
    int indicado; /* índice do vértice 'destino' */
    apEdge next; /* próxima aresta da lista */
} TEdge;

/* descrição de um vértice */
//typedef struct SVert *Grafo;
typedef struct SVert
{
    int id;


    int d; /* 'distância' do vértice à 'origem' */
    int r; /* próximo vértice no caminho até a origem */
    int m; /* vértice marcado ? */
    apEdge list; /* lista de arestas */
} TVert;

typedef struct SGrafo
{
    TVert *Nos;
    TEdge *Arestas;
    int flagsInd;
}TGrafo;

apEdge InicializaVe()
{
    apEdge aresta;
    aresta = (apEdge)malloc(sizeof(TEdge));
    aresta->next = NULL;
    return aresta;
}

TVert InicializaNo()
{
	TVert No;

	No = (TVert) malloc(sizeof(TVert));
	No->m = 0;
	No->list = InicializaVe();

	return No;
}

int Carrega(TVert *G)
{
    int npessoas;

    scanf("%d", &npessoas);

    return npessoas;
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
    Grafo G;
    TGrafo *grafo;
    int npessoas, nindicados;

    G = InicializaNo();

    npessoas = Carrega(&G);
    grafo = (TGrafo)malloc(sizeof(SGrafo));
    grafo.Nos = (TVert)malloc(n*sizeof(SVert));
//    int nconvidados, indica, i;
//    int *convidado, *auxconvidado, *seraconv; // convidado armazena quem o item indicou, indicado armazena por quem foi indicado


//    scanf("%d", &nconvidados);
//    nconvidados = nconvidados + 1;
//
//    convidado = (int *) malloc(nconvidados* sizeof(int));
//    auxconvidado = (int *) malloc(nconvidados* sizeof(int));
//    seraconv = (int *) malloc(nconvidados* sizeof(int));
//
//    for(i=0; i<nconvidados; i++)
//        seraconv[i] = 1;
//
//    for(i=0; i<nconvidados; i++)
//    {
//        scanf("%d", &indica); // atual que esta indicando
//        scanf("%d", &convidado[indica]); // quem ele indicou
//        auxconvidado[indica] = convidado[indica];
//
//    }
//
//    qsort(convidado, nconvidados, sizeof(int), compara);
}
