# Esse arquivo é referente a resolução do item 2

import time
from controller import *

def tempoParaExecutar(fn, *args):
    start = time.time()
    fn(*args)
    end = time.time()
    return end - start

def item2():
    def escreveLinhaItem2(sequenciaNome, tamanho, tempo):
        string = '{},{},{}\n'.format(sequenciaNome, tamanho, tempo)
        print(string)
        output.write(string)

    # definindo as sequencias de teste
    sequencias = ([sequenciaShell, 'SHELL'], [sequenciaKnuth, 'KNUTH'], [sequenciaCiura, 'CIURA'])
    # definindo os tamanhos de teste e seus arrays
    sequenciasTamanhos = []

    # arquivo de entrada
    input = open("./entrada2.txt", "r")

    # arquivo de saida
    output = open("./saida2.txt", "w")

    # separando as linhas do arquivo de entrada no array de sequencia de tamanho
    for line in input:
        separado = list(map(int, line.strip().split()))
        sequenciasTamanhos.append([separado[0], separado[1:]])

    # executando os testes
    for tamanho in sequenciasTamanhos:
        tamanhoTeste = tamanho[0]
        for sequencia in sequencias:
            sequenciaFuncao = sequencia[0]
            sequenciaNome = sequencia[1]
            lista = tamanho[1][:]
            tempo = tempoParaExecutar(shellSort, lista, sequenciaFuncao)
            escreveLinhaItem2(sequenciaNome, tamanhoTeste, tempo)



