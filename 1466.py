from collections import deque


class No:
    def __init__(self):
        self.valor = 0
        self.esq = -1
        self.dir = -1


def inserir(arvore, valor):
    atual = 0

    while True:
        if valor < arvore[atual].valor:
            if arvore[atual].esq == -1:
                novo = No()
                novo.valor = valor
                novo.esq = -1
                novo.dir = -1

                arvore.append(novo)
                arvore[atual].esq = len(arvore) - 1

                break

            atual = arvore[atual].esq
        else:
            if arvore[atual].dir == -1:
                novo = No()
                novo.valor = valor
                novo.esq = -1
                novo.dir = -1

                arvore.append(novo)
                arvore[atual].dir = len(arvore) - 1

                break

            atual = arvore[atual].dir


def percursoNivel(arvore):
    fila = deque()

    fila.append(0)

    primeiro = True

    while fila:
        atual = fila.popleft()

        if not primeiro:
            print(" ", end="")

        print(arvore[atual].valor, end="")
        primeiro = False

        if arvore[atual].esq != -1:
            fila.append(arvore[atual].esq)

        if arvore[atual].dir != -1:
            fila.append(arvore[atual].dir)

    print()


C = int(input())

for caso in range(1, C + 1):
    N = int(input())

    valores = input().split()

    arvore = []

    raiz = No()
    raiz.valor = int(valores[0])

    raiz.esq = -1
    raiz.dir = -1

    arvore.append(raiz)

    for i in range(1, N):
        valor = int(valores[i])
        inserir(arvore, valor)

    print("Case", str(caso) + ":")

    percursoNivel(arvore)

    print()