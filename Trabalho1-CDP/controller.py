#Esse aquivo guarda funções que são usadas nos dois itens 
from math import floor

def sequenciaShell(lenList):
    SHEEL = []
    i = 0
    while i < lenList:
        number = 2 ** i
        if (number >= lenList):
            break
        SHEEL.append(int(number))
        i += 1
        
    return list(reversed(SHEEL))

def sequenciaKnuth(lenList):
    KNUTH = []
    i = 1
    while i < lenList:
        number = int((3 ** i) // 2)
        if (number >= lenList):
            break
        KNUTH.append(number)
        i += 1
        
    return list(reversed(KNUTH))

def sequenciaCiura(lenList):
    CIURA = [1, 4, 10, 23, 57, 132, 301, 701]
    test = list(filter(lambda x: x < lenList, CIURA))
    if (len(test) < len(CIURA)):
        return list(reversed(test))
    preNumber = CIURA[-1]
    while (preNumber < lenList):
        preNumber = floor(2.25 * preNumber)
        CIURA.append(int(preNumber))
    return list(reversed(CIURA))

# shellSort
def shellSort(lista, sequencia):
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
    return lista

def listToString(lista):
    return ', '.join([str(element) for element in lista])
