#ifndef GRAPH_BASIC_NODE_H
#define GRAPH_BASIC_NODE_H

#include "Edge.hpp"
#include "defines.hpp"
using namespace std;

class Node {
    private:
        size_t _number_of_edges;
        size_t _id;
        float _weight;
        Edge* _first_node;
        Node* _next_node;
        Node* _previous_node;

    public:
        //Construtor padrão
        Node();

        //Construtor com Parâmetros
        Node(size_t id, float weight, Edge* firstEdge, Node* nextNode, Node* previousNode);

        //Getters e Setters
        size_t getNumberOfEdges() const;
        void setNumberOfEdges(size_t numEdges);
        size_t getId() const;
        void setId(size_t id);
        float getWeight() const;
        void setWeight(float weight);
        Edge* getFirstNode() const;
        void setFirstNode(Edge* firstNode);
        Node* getNextNode() const;
        void setNextNode(Node* nextNode);
        Node* getPreviousNode() const;
        void setPreviousNode(Node* previousNode);
};

#endif  //GRAPH_BASIC_NODE_H
