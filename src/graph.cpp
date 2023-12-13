#include "graph.hpp"
#include <limits> // Include the header for numeric_limits

Grafo::Grafo() {}

Grafo::~Grafo() {}

void Grafo::InsereVertice() {
    vertices.InsereVerticeFinal();
}

void Grafo::InsereAresta(int v, int w) {
    vertices.InsereAresta(v, w);
}

int Grafo::QuantidadeVertices() {
    No* atual = vertices.adjacencias;
    int count = 0;
    while (atual != nullptr) {
        count++;
        atual = atual->proximo;
    }
    return count;
}

int Grafo::QuantidadeArestas() {
    
    No* atual = vertices.adjacencias;
    int count = 0;
    while (atual != nullptr) {
        count += atual->dado.size();
        atual = atual->proximo;
    }
    return count / 2;  
}

int Grafo::GrauMinimo() {
    No* atual = vertices.adjacencias;
    int grauMinimo = std::numeric_limits<int>::max();
    while (atual != nullptr) {
        if (static_cast<int>(atual->dado.size()) < grauMinimo) {
            grauMinimo = static_cast<int>(atual->dado.size());
        }
        atual = atual->proximo;
    }
    return grauMinimo;
}

int Grafo::GrauMaximo() {
    No* atual = vertices.adjacencias;
    int grauMaximo = 0;
    while (atual != nullptr) {
        if (static_cast<int>(atual->dado.size()) > grauMaximo) {
            grauMaximo = static_cast<int>(atual->dado.size());
        }
        atual = atual->proximo;
    }
    return grauMaximo;
}


void Grafo::ImprimeVizinhos(int v) {
    vertices.Imprimir();  
}
