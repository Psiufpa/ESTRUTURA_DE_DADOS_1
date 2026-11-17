
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct No
{
    int valor;
    int esq;
    int dir;
};

void inserir(vector<No> &arvore, int valor)
{
    int atual = 0;

    while (true)
    {
        if (valor < arvore[atual].valor)
        {
            if (arvore[atual].esq == -1)
            {
                No novo;
                novo.valor = valor;
                novo.esq = -1;
                novo.dir = -1;

                arvore.push_back(novo);
                arvore[atual].esq = arvore.size() - 1;

                break;
            }

            atual = arvore[atual].esq;
        }
        else
        {
            if (arvore[atual].dir == -1)
            {
                No novo;
                novo.valor = valor;
                novo.esq = -1;
                novo.dir = -1;

                arvore.push_back(novo);
                arvore[atual].dir = arvore.size() - 1;

                break;
            }

            atual = arvore[atual].dir;
        }
    }
}

void percursoNivel(vector<No> &arvore)
{
    queue<int> fila;

    fila.push(0);

    bool primeiro = true;

    while (!fila.empty())
    {
        int atual = fila.front();
        fila.pop();

        if (!primeiro)
            cout << " ";

        cout << arvore[atual].valor;
        primeiro = false;

        if (arvore[atual].esq != -1)
            fila.push(arvore[atual].esq);

        if (arvore[atual].dir != -1)
            fila.push(arvore[atual].dir);
    }

    cout << endl;
}

int main()
{
    int C, N, valor;

    cin >> C;

    for (int caso = 1; caso <= C; caso++)
    {
        cin >> N;

        vector<No> arvore;

        No raiz;
        cin >> raiz.valor;

        raiz.esq = -1;
        raiz.dir = -1;

        arvore.push_back(raiz);

        for (int i = 1; i < N; i++)
        {
            cin >> valor;
            inserir(arvore, valor);
        }

        cout << "Case " << caso << ":" << endl;

        percursoNivel(arvore);

        cout << endl;
    }

    return 0;
}
