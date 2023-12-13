#ifndef LISTAAD_HPP
#define LISTAAD_HPP

#include <list>
#include <iostream>

struct No {
    std::list<int> dado;
    No* proximo;

    No();    
    No(std::list<int> dados);
};

class ListaAdjacencia {

public:
    ListaAdjacencia();

    ~ListaAdjacencia();

    void InsereVerticeFinal();

    void InsereAresta(int vertice1, int vertice2);

    void Imprimir();

    void RemoverVerticeInicio();

    bool Vazia();
    

    No* adjacencias;
};

#endif
