#include "../include/Edge.hpp"

using namespace std;

Edge::Edge(float weight, size_t target_id)
{
    _weight = weight;
    _target_id = target_id;
    _next_edge = nullptr;
}

void Edge::setNextEdge(Edge* next_edge)
{
    _next_edge = next_edge;
}

Edge* Edge::getNextEdge() const 
{
    return _next_edge;
}

void Edge::setWeight(float weight)
{
    _weight = weight;
}

float Edge::getWeight() const
{
    return _weight;
}

void Edge::setTargetId(size_t target_id)
{
    _target_id = target_id;
}

size_t Edge::getTargetId() const
{
    return _target_id;
}