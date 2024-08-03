#include "../include/Edge.hpp"
#include <cstddef> //Para size_t
#include <iostream>

using namespace std;

//Construtor
Edge::Edge(float weight, size_t target_id) 
{
    _next_edge = nullptr;
    _weight = weight;
    _target_id = target_id;
}

//Método para definir o próximo edge
void Edge::setNextEdge(Edge* next_edge) 
{
    _next_edge = next_edge;
}

//Método para obter o próximo edge
Edge* Edge::getNextEdge() const 
{
    return _next_edge;
}

//Método para definir o peso
void Edge::setWeight(float weight)
{
    _weight = weight;
}

//Método para obter o peso
float Edge::getWeight() const 
{
    return _weight;
}

//Método para definir o ID do alvo
void Edge::setTargetId(size_t target_id)
{
    _target_id = target_id;
}

size_t Edge::getTargetId() const
{
    return _target_id;
}