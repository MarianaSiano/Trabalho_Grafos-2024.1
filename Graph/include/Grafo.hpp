#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Node.hpp"
#include "defines.hpp"

#include <iostream>

using namespace std;

class Grafo
{
public:
    /*Assinatura dos métodos básicos para o funcionamento da classe*/

    Grafo(ifstream& instance);
    Grafo();
    ~Grafo();

    void remove_node(size_t node_id);
    void remove_edge(size_t node_id_1, size_t node_id_2);
    void add_node(size_t node_id, float weight = 0);
    void add_edge(size_t node_id_1, size_t node_id_2, float weight = 0);
    void print_graph(ofstream& output_file);
    void print_graph();

    int conected(size_t node_id_1, size_t node_id_2);

private:
    size_t _number_of_nodes;
    size_t _number_of_edges;
    bool   _directed;
    bool   _weighted_edges;
    bool   _weighted_nodes;
    Node  *_first;
    Node  *_last;
};

#endif  //GRAFO_HPP
