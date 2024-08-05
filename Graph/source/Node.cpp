#include "../include/Node.hpp"
#include <iostream>

using namespace std;

Node::Node(size_t id, float weight)
{
    _id = id;
    _weight = weight;
    _first_edge = nullptr;
    _next_node = nullptr;
}

//Getters e Setters
size_t Node::getId() const
{
    return _id;
}

void Node::setId(size_t id)
{
    _id = id;
}

float Node::getWeight() const
{
    return _weight;
}

void Node::setWeight(float weight)
{
    _weight = weight;
}

Edge* Node::getFirstEdge() const
{
    return _first_edge;
}

void Node::setFirstEdge(Edge *firstEdge)
{
    _first_edge = firstEdge;
}

Node* Node::getNextNode() const
{
    return _next_node;
}

void Node::setNextNode(Node *nextNode)
{
    _next_node = nextNode;
}