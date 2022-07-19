# Esse arquivo é referente a resolução do item 1
from controller import *

#Constantes:
SEQUENCIASTRING = " SEQ= "
INCREMENTO = " INCR= "

def item1():
    input = open("./entrada1.txt", "r")
    output = open("./saida1.txt", "w")

    sequencias = ([sequenciaShell, 'SHELL'], [sequenciaKnuth, 'KNUTH'], [sequenciaCiura, 'CIURA']) 
    sequenciasTamanhos = []
    for line in input:
        separado = list(map(int, line.strip().split()))
        sequenciasTamanhos.append([separado[0], separado[1:]])

    def escreveLinhaItem1(lista,sequenciaNome):
        string = '{}{}{}\n'.format(listToString(lista), SEQUENCIASTRING, sequenciaNome)
        output.write(string)
    
    def escreveIncremento(lista,incremento):
        string = '{}{}{}\n'.format(listToString(lista), INCREMENTO, incremento)
        output.write(string)


    def shellSort1(lista, sequencia):
        tamanhoLista = len(lista)
        seq = sequencia(tamanhoLista)
        for incremento in seq:
            for i in range(incremento, tamanhoLista):
                valor = lista[i]
                j = i
                while j >= incremento and lista[j - incremento] > valor:
                    lista[j] = lista[j - incremento]
                    j = j - incremento
                lista[j] = valor
            escreveIncremento(lista, incremento)
        return lista

    for tamanho in sequenciasTamanhos:
        for sequencia in sequencias:
            sequenciaFuncao = sequencia[0]
            sequenciaNome = sequencia[1]
            lista = tamanho[1][:]
            escreveLinhaItem1(lista,sequenciaNome)
            shellSort1(lista,sequenciaFuncao)

