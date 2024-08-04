#ifndef GRAFO_BASICO_EDGE_H
#define GRAFO_BASICO_EDGE_H

#include "defines.hpp"
using namespace std;

class Edge
{
    private:
        Edge  *_next_edge; //Ponteiro para o próximo edge
        float  _weight; //Peso da aresta
        size_t _target_id; //ID do alvo

    public:
        //Construtor
        Edge(float weight, size_t target_id);

        //Destrutor
        ~Edge();

        //Setters e Getters
        void setNextEdge(Edge* next_edge); //Método para definir o próximo edge
        Edge* getNextEdge() const; //Método para obter o próximo edge
        void setWeight(float weight); //Método para definir o peso
        float getWeight() const; //Método para obter o peso
        void setTargetId(size_t target_id); //Método para definir o ID do alvo
        size_t getTargetId() const; //Método para obter o ID do alvo
};

#endif /* GRAFO_BASICO_EDGE_H */