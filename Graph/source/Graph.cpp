#include "../include/Graph.hpp"
#include "../include/Node.hpp"
#include "./Node.cpp"
#include <iostream>
#include <fstream>

using namespace std;

//Construtor que lê uma instância de um arquivo
Graph::Graph(ifstream& instance)
{
    _number_of_nodes = 0;
    _number_of_edges = 0;
    _directed = false;
    _weighted_edges = false;
    _weighted_nodes = false;
    _first_node = nullptr;

    loadGraphFromFile(instance);
}

Graph::Graph()
{
    _number_of_nodes = 0;
    _number_of_edges = 0;
    _directed = false;
    _weighted_edges = false;
    _weighted_nodes = false;
    _first_node = nullptr;
}

Graph::~Graph()
{
    Node* current = _first_node;
    while(current != nullptr) {
        Node* next = current->getNextNode();
        delete current;
        current = next;
    }
}

//Adiciona um nó no grafo
void Graph::addNode(size_t node_id, float weight)
{
    Node* newNode = new Node(node_id, weight);

    newNode->setNextNode(_first_node);
    _first_node = newNode;
    _number_of_nodes++;
}

//Adiciona uma aresta ao grafo
void Graph::addEdge(size_t node_id_1, size_t node_id_2, float weight)
{
    Node* node1 = _first_node;

    while(node1 != nullptr && node1->getId() != node_id_1) {
        node1 = node1->getNextNode();
    }

    if(node1 != nullptr) {
        Edge* newEdge = new Edge(weight, node_id_2);
        newEdge->setNextEdge(node1->getFirstEdge());
        node1->setFirstEdge(newEdge);
        _number_of_edges++;

        //Se o grafo não é dirigido, adicione a aresta de volta
        if(!_directed) {
            Node* node2 = _first_node;
            while(node2 != nullptr && node2->getId() != node_id_2) {
                node2 = node2->getNextNode();
            }
            if(node2 != nullptr) {
                Edge* reverseEdge = new Edge(weight, node_id_1);
                reverseEdge->setNextEdge(node2->getFirstEdge());
                node2->setFirstEdge(reverseEdge);
            }
        }
    }
}

//Remove um nó do grafo
void Graph::removeNode(size_t node_id)
{
    Node* current = _first_node;
    Node* previous = nullptr;

    while(current != nullptr && current->getId() != node_id) {
        previous = current;
        current = current->getNextNode();
    }

    if(current != nullptr) {
        if(previous != nullptr) {
            previous->setNextNode(current->getNextNode());
        } else {
            _first_node = current->getNextNode();
        }

        //Remover todas as arestas que apontam para este nó
        Node* temp = _first_node;

        while(temp != nullptr) {
            Edge* edgeCurrent = temp->getFirstEdge();
            Edge* edgePrevious = nullptr;

            while (edgeCurrent != nullptr) {
                if(edgeCurrent->getTargetId() == node_id) {
                    if(edgePrevious != nullptr) {
                        edgePrevious->setNextEdge(edgeCurrent->getNextEdge());
                    } else {
                        temp->setFirstEdge(edgeCurrent->getNextEdge());
                    }
                    delete edgeCurrent;
                    _number_of_edges--;
                    break; //Para evitar problemas com a iteração
                }
                edgePrevious = edgeCurrent;
                edgeCurrent = edgeCurrent->getNextEdge();
            }
            temp = temp->getNextNode();
        }
        delete current;
        _number_of_nodes--;
    }
}

//Remove uma aresta entre dois nós
void Graph::removeEdge(size_t node_id_1, size_t node_id_2)
{
    Node* node1 = _first_node;

    while(node1 != nullptr && node1->getId() != node_id_1) {
        node1 = node1->getNextNode();
    }

    if(node1 != nullptr) {
        Edge* current_edge = node1->getFirstEdge();
        Edge* previous_edge = nullptr;

        while(current_edge != nullptr && current_edge->getTargetId() != node_id_2) {
            previous_edge = current_edge;
            current_edge = current_edge->getNextEdge();
        }

        if(current_edge != nullptr) {
            if(previous_edge != nullptr) {
                previous_edge->setNextEdge(current_edge->getNextEdge());
            } else {
                node1->setFirstEdge(current_edge->getNextEdge());
            }
            delete current_edge;
            _number_of_edges--;

            //Se o grafo não é dirigido, remova a aresta de volta
            if(!_directed) {
                Node* node2 = _first_node;

                while(node2 != nullptr && node2->getId() != node_id_2) {
                    node2 = node2->getNextNode();
                }

                if(node2 != nullptr) {
                    Edge* reverseEdgeCurrent = node2->getFirstEdge();
                    Edge* reverseEdgePrevious = nullptr;

                    while(reverseEdgeCurrent != nullptr && reverseEdgePrevious->getTargetId() != node_id_1) {
                        reverseEdgePrevious = reverseEdgeCurrent;
                        reverseEdgeCurrent = reverseEdgeCurrent->getNextEdge();
                    }

                    if(reverseEdgeCurrent != nullptr) {
                        if(reverseEdgePrevious != nullptr) {
                            reverseEdgePrevious->setNextEdge(reverseEdgeCurrent->getNextEdge());
                        } else {
                            node2->setFirstEdge(reverseEdgeCurrent->getNextEdge());
                        }

                        delete reverseEdgeCurrent;
                        _number_of_edges--;
                    }
                }
            }
        }
    }
}

void Graph::printGraph() const 
{
    Node* current_node = _first_node;

    while(current_node != nullptr) {
        cout << "Node " << current_node->getId() << " (Weight: " << current_node->getWeight() << ")" << endl;
        Edge* current_edge = current_node->getFirstEdge();

        while(current_edge != nullptr) {
            cout << " -> " << current_edge->getTargetId() << " (Weight: " << current_edge->getWeight() << ")" << endl;
            current_edge = current_edge->getNextEdge();
        }
        current_node = current_node->getNextNode();
    }
}

//Método auxiliar para carregar o grafo a partir de um arquivo
void Graph::loadGraphFromFile(ifstream& instance)
{
    size_t node_count, edge_count;
    instance >> node_count >> edge_count; //Lê o número de nós e arestas

    for(size_t i = 0; i < node_count; i++) {
        size_t id;
        float weight;

        instance >> id >> weight; //Lê o ID e o peso do nó
        addNode(id, weight);
    }

    for(size_t i = 0; i < edge_count; i++) {
        size_t node_id_1, node_id_2;
        float weight;

        instance >> node_id_1 >> node_id_2 >> weight; //Lê os ID dos nós conectados e o peso da aresta
        addEdge(node_id_1, node_id_2, weight);
    }
}