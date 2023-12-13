#include "ListaAdjacencia.hpp"


No::No() : proximo(nullptr) {}

No::No(std::list<int> dados) : dado(dados), proximo(nullptr) {}

ListaAdjacencia::ListaAdjacencia() : adjacencias(nullptr) {}

void ListaAdjacencia::InsereVerticeFinal() {
    std::list<int> dados; 
    No* novoNo = new No(dados);

    if (Vazia()) {
        adjacencias = novoNo;
    } else {
        No* atual = adjacencias;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
}


void ListaAdjacencia::InsereAresta(int v, int w) {
    int count = 0;
    No* it = adjacencias;

    while (it != nullptr) {
        if (count == v) {
            it->dado.push_back(w);
            break;
        }

    it = it->proximo;
    count++;
    }
}

void ListaAdjacencia::Imprimir() {
    No* atual = adjacencias;
    while (atual != nullptr) {
        std::cout << "Nó: ";
        for (int valor : atual->dado) {
            std::cout << valor << " ";
        }
        std::cout << std::endl;
        atual = atual->proximo;
    }
}

void ListaAdjacencia::RemoverVerticeInicio() {
    if (!Vazia()) {
        No* temp = adjacencias;
        adjacencias = adjacencias->proximo;
        delete temp;
    }
}

bool ListaAdjacencia::Vazia() {
    return adjacencias == nullptr;
}

ListaAdjacencia::~ListaAdjacencia() {
    while (!Vazia()) {
        RemoverVerticeInicio();
    }
}
