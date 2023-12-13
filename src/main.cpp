#include "graph.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " -d | -n | -k" << std::endl;
        return 1;
    }

    Grafo grafo;

    // Leitura dos dados do grafo
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        grafo.InsereVertice();

        int m;
        std::cin >> m;

        for (int j = 0; j < m; ++j) {
            int vizinho;
            std::cin >> vizinho;
            grafo.InsereAresta(i, vizinho);
        }
    }

    // Realiza a operação especificada na linha de comando
    std::string operacao(argv[1]);

    if (operacao == "-d") {
        // Imprime dados básicos
        std::cout << grafo.QuantidadeVertices() << std::endl;
        std::cout << grafo.QuantidadeArestas() << std::endl;
        std::cout << grafo.GrauMinimo() << std::endl;
        std::cout << grafo.GrauMaximo() << std::endl;
    } else if (operacao == "-n") {
        // Imprime as vizinhanças
        for (int i = 0; i < grafo.QuantidadeVertices(); ++i) {
            grafo.ImprimeVizinhos(i);
        }
    } else if (operacao == "-k") {
        // Imprime 1 se o grafo é completo, 0 caso contrário
        std::cout << (grafo.GrauMinimo() == grafo.GrauMaximo()) << std::endl;
    } else {
        std::cerr << "Operação inválida: " << operacao << std::endl;
        return 1;
    }

    return 0;
}
