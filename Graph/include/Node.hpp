#ifndef GRAPH_BASIC_NODE_H
#define GRAPH_BASIC_NODE_H

#include "Edge.hpp"
#include "defines.hpp"
using namespace std;

class Node {
    private:
        size_t _id; //ID do nó
        float _weight; //Peso do nó
        Edge* _first_edge; //Primeiro edge da lista de adjacência
        Node* _next_node; //Próximo nó da lista de nós

    public:
        Node();
        Node(size_t id, float weight);

        //Getters e Setters
        size_t getId() const;
        void setId(size_t id);
        float getWeight() const;
        void setWeight(float weight);
        Edge* getFirstEdge() const;
        void setFirstEdge(Edge* firstEdge);
        Node* getNextNode() const;
        void setNextNode(Node* nextNode);
};

#endif  //GRAPH_BASIC_NODE_H
