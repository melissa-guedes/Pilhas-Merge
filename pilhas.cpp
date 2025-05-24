#include <iostream>
using namespace std;

// ---------- Pilha com vetor (para números pares) ----------
class PilhaVetor {
    int topo;
    int dados[30]; // Tamanho máximo

public:
    PilhaVetor() {
        topo = -1;
    }

    bool vazia() {
        return topo == -1;
    }

    bool cheia() {
        return topo == 29;
    }

    void push(int valor) {
        if (!cheia()) {
            dados[++topo] = valor;
        } else {
            cout << "Erro: Pilha de pares cheia!" << endl;
        }
    }

    int pop() {
        if (!vazia()) {
            return dados[topo--];
        } else {
            cout << "Erro: Pilha de pares vazia!" << endl;
            return -1;
        }
    }
};

// ---------- Pilha com lista encadeada (para números ímpares) ----------
struct No {
    int valor;
    No* prox;
};

class PilhaLista {
    No* topo;

public:
    PilhaLista() {
        topo = nullptr;
    }

    ~PilhaLista() {
        while (!vazia()) {
            pop();
        }
    }

    bool vazia() {
        return topo == nullptr;
    }

    void push(int valor) {
        No* novo = new No;
        novo->valor = valor;
        novo->prox = topo;
        topo = novo;
    }

    int pop() {
        if (!vazia()) {
            No* temp = topo;
            int valor = topo->valor;
            topo = topo->prox;
            delete temp;
            return valor;
        } else {
            cout << "Erro: Pilha de ímpares vazia!" << endl;
            return -1;
        }
    }
};

// ---------- Função principal ----------
int main() {
    PilhaVetor pilhaPares;
    PilhaLista pilhaImpares;

    int numero, anterior = -1;

    cout << "Digite 30 numeros inteiros em ordem crescente:\n";

    for (int i = 0; i < 30; ++i) {
        do {
            cout << "Numero " << (i + 1) << ": ";
            cin >> numero;

            if (numero <= anterior) {
                cout << "Erro: o numero deve ser maior que o anterior (" << anterior << "). Tente novamente.\n";
            }
        } while (numero <= anterior);

        anterior = numero;

        if (numero % 2 == 0) {
            pilhaPares.push(numero);
        } else {
            pilhaImpares.push(numero);
        }
    }

    // Desempilhar e mostrar os valores em ordem decrescente
    cout << "\nValores em ordem decrescente (desempilhando):\n";

    cout << "Numeros pares:\n";
    while (!pilhaPares.vazia()) {
        cout << pilhaPares.pop() << " ";
    }

    cout << "\nNumeros impares:\n";
    while (!pilhaImpares.vazia()) {
        cout << pilhaImpares.pop() << " ";
    }

    cout << endl;
    return 0;
}
