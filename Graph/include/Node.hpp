#ifndef NODE_HPP
#define NODE_HPP

#include "Edge.hpp"
#include "defines.hpp"
using namespace std;

class Node {
    private:
        size_t _id;
        float _weight;
        Edge* _first_edge;
        Node* _next_node;

    public:
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

#endif  //NODE_HPP
