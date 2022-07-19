#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


struct TPtPilha{
        TipoInfo dado;
        struct TPtPilha *elo;
};


TipoPilha* InicializaPilha (void)
{
    return NULL;
}

int PilhaVazia (TipoPilha *Topo)
{
    if (Topo==NULL)
       return 1;
    else
       return 0;
}

void ImprimirPilha (TipoPilha *Topo)
{
     TipoPilha *ptaux;

     if (Topo != NULL)
     {
        puts("---Imprimindo pilha---");
        for (ptaux=Topo; ptaux!=NULL; ptaux=ptaux->elo)
            printf("%d\n",ptaux->dado);
        puts("-------Fim pilha------");
     }
     else
       puts("Pilha vazia");

}


TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado)
{
       TipoPilha *novo; //novo elemento
       TipoPilha *ptaux = Topo; //ponteiro auxiliar para percorrer a lista

       /*aloca um novo nodo */
       novo = (TipoPilha*) malloc(sizeof(TipoPilha));
       novo->elo = NULL;

       /*insere a informação no novo nodo*/
       novo->dado = Dado;

       /*encaeia o elemento*/
       novo->elo = Topo;
       Topo = novo;
       return Topo;
}


int PopPilha (TipoPilha **Topo, TipoInfo *Dado) //retorna 1 se exclui e zero se não exclui
{
   TipoPilha* ptaux;

   if (PilhaVazia(*Topo))
     return 0;   //não tem nada na pilha
   else
   {
        *Dado = (*Topo)->dado;     // devolve o valor do topo
        ptaux = *Topo;          //guarda o endereço do topo
        *Topo = (*Topo)->elo;     //o próximo passa a ser o topo
        free(ptaux);           //libera o que estava no topo
        ptaux=NULL;
        return 1;
   }
}

TipoInfo ConsultaPilha (TipoPilha *Topo)
{
 if (Topo==NULL)
   return 0;
 else
   return Topo->dado;

}

TipoPilha* DestroiPilha (TipoPilha *Topo)
{
        TipoPilha *ptaux;
        while (Topo != NULL)
        {
          ptaux = Topo;          //guarda o endereço do topo
          Topo = Topo->elo;     //o próximo passa a ser o topo
          free(ptaux);           //libera o que estava no topo
        }
        return NULL;
}
int compara (TipoPilha *p1, TipoPilha *p2){
    TipoPilha *paux1, *paux2;
    paux1 = p1;
    paux2 = p2;
    int flag=1;
    TipoInfo dado;
    while(!(PilhaVazia(paux1)) && !(PilhaVazia(paux2))){
        if(ConsultaPilha(paux1) == ConsultaPilha(paux2)){
            PopPilha(&paux1, &dado);
            PopPilha(&paux2, &dado);
            flag = flag * 1;
        }
        else{
            PopPilha(&paux1, &dado);
            PopPilha(&paux2, &dado);
            flag = flag * 0;
        }
    }
    if(!(PilhaVazia(paux1))){
        flag = flag * 0;
    }
    if(!(PilhaVazia(paux2))){
        flag = flag * 0;
    }

    return flag; //se flag é igual a 1 as pilhas são iguais, se não retorna 0;
}



