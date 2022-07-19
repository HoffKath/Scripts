#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


int main ()
{
    TipoPilha *p1, *p2;
    int retorno;


    p1 = InicializaPilha();
    p2 = InicializaPilha();
   /* Teste 1
    p1 = PushPilha(p1,1);
    p1 = PushPilha(p1,2);
    p1 = PushPilha(p1,3);
    p1 = PushPilha(p1,4);
    p2 = PushPilha(p2,2);
    p2 = PushPilha(p2,3);
    p2 = PushPilha(p2,4);
    */
    p1 = PushPilha(p1,4);
    p1 = PushPilha(p1,3);
    p1 = PushPilha(p1,2);
    p1 = PushPilha(p1,1);
    p2 = PushPilha(p2,4);
    p2 = PushPilha(p2,3);
    p2 = PushPilha(p2,2);
    p2 = PushPilha(p2,1);

    ImprimirPilha(p1);
    ImprimirPilha(p2);

    retorno = compara(p1, p2);
    if (retorno == 0){
        printf("As pilhas nao sao iguais!");
    }
    if (retorno == 1){
        printf("As pilhas sao iguais!");
    }
    return 0;
}
