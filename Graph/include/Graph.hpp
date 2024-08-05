#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Node.hpp"
#include "defines.hpp"

using namespace std;

class Graph
{
    private:
        size_t _number_of_nodes;
        size_t _number_of_edges;
        bool _directed; //Indica se o grafo é dirigido
        bool _weighted_edges; //Indica se as arestas são ponderadas
        bool _weighted_nodes; //Indica se os nós são ponderados
        Node* _first_node; //Primeiro nó da lista de nós

        void loadGraphFromFile(ifstream& instance); //Método auxiliar para carregar o grafo a partir de um arquivo

    public:
        Graph(ifstream& instance);
        Graph();
        ~Graph();

        //Métodos para manipulação do grafo
        void addNode(size_t node_id, float weight);
        void addEdge(size_t node_id_1, size_t node_id_2, float weight);
        void removeNode(size_t node_id);
        void removeEdge(size_t node_id_1, size_t node_id_2);
        void printGraph() const;
};

#endif  //GRAPH_HPP