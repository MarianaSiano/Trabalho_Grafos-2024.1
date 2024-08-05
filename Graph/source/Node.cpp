#include "../include/Node.hpp"
#include <iostream>

using namespace std;

Node::Node()
{
    _number_of_edges = 0;
    _id = 0;
    _weight = 0.0;
    _first_node = nullptr;
    _next_node = nullptr;
    _previous_node = nullptr;
}

Node::Node(size_t id, float weight, Edge *firstEdge, Node *nextNode, Node *previousNode)
{
    _number_of_edges = 0;
    _id = id;
    _weight = weight;
    _first_node = firstEdge;
    _next_node = nextNode;
    _previous_node = previousNode;
}

//Getters e Setters
size_t Node::getNumberOfEdges() const
{
    return _number_of_edges;
}

void Node::setNumberOfEdges(size_t numEdges)
{
    _number_of_edges = numEdges;
}

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

Edge* Node::getFirstNode() const
{
    return _first_node;
}

void Node::setFirstNode(Edge *firstNode)
{
    _first_node = firstNode;
}

Node* Node::getNextNode() const
{
    return _next_node;
}

void Node::setNextNode(Node *nextNode)
{
    _next_node = nextNode;
}

Node* Node::getPreviousNode() const
{
    return _previous_node;
}

void Node::setPreviousNode(Node *previousNode)
{
    _previous_node = previousNode;
}