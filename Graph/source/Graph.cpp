#include "../include/Graph.hpp"
#include "../include/Node.hpp"
#include "./Node.cpp"
#include <iostream>
#include <fstream>

using namespace std;

//Construtor que lê uma instância de um arquivo
Graph::Graph(ifstream& instance)
{
    //Inicialização dos atributos
    _number_of_nodes = 0;
    _number_of_edges = 0;
    _directed = false;
    _weighted_edges = false;
    _weighted_nodes = false;
    _first = nullptr;
    _last = nullptr;

    //Pode adicionar lógica para ler o arquivo e construir o grafo
}

Graph::Graph()
{
    _number_of_nodes = 0;
    _number_of_edges = 0;
    _directed = false;
    _weighted_edges = false;
    _weighted_nodes = false;
    _first = nullptr;
    _last = nullptr;
}

Graph::~Graph()
{
    Node* current = _first;
    while(current != nullptr) {
        Node* next = current->getNextNode();
        delete current;
        current = next;
    }
}

//Adiciona um nó no grafo
void Graph::add_node(size_t node_id, float weight)
{
    Node* newNode = new Node(node_id, weight, nullptr, nullptr, _last);

    if(_last != nullptr) {
        _last->setNextNode(newNode);
    } else {
        _first = newNode;
    }

    _last = newNode;
    _number_of_nodes++;
}

//Adiciona uma aresta ao grafo
void Graph::add_edge(size_t node_id_1, size_t node_id_2, float weight)
{
    Node* node1 = _first;

    while(node1 != nullptr && node1->getId() != node_id_1) {
        node1 = node1->getNextNode();
    }

    if(node1 != nullptr) {
        Edge* newEdge = new Edge(weight, node_id_2);
        newEdge->setNextEdge(node1->getFirstNode());
        node1->setFirstNode(newEdge);
        node1->setNumberOfEdges(node1->getNumberOfEdges() + 1);
        _number_of_edges++;
    }
}

//Remove um nó do grafo
void Graph::remove_node(size_t node_id)
{
    Node* current = _first;
    Node* previous = nullptr;

    while(current != nullptr && current->getId() != node_id) {
        previous = current;
        current = current->getNextNode();
    }

    if(current != nullptr) {
        if(previous != nullptr) {
            previous->setNextNode(current->getNextNode());
        } else {
            _first = current->getNextNode();
        }

        if(current->getNextNode() != nullptr) {
            current->getNextNode()->setPreviousNode(previous);
        } else {
            _last = previous;
        }

        delete current;
        _number_of_nodes--;
    }
}

//Remove uma aresta entre dois nós
void Graph::remove_edge(size_t node_id_1, size_t node_id_2)
{
    Node* node1 = _first;

    while(node1 != nullptr && node1->getId() != node_id_1) {
        node1 = node1->getNextNode();
    }

    if(node1 != nullptr) {
        Edge* current_edge = node1->getFirstNode();
        Edge* previous_edge = nullptr;

        while(current_edge != nullptr && current_edge->getTargetId() != node_id_2) {
            previous_edge = current_edge;
            current_edge = current_edge->getNextEdge();
        }

        if(current_edge != nullptr) {
            if(previous_edge != nullptr) {
                previous_edge->setNextEdge(current_edge->getNextEdge());
            } else {
                node1->setFirstNode(current_edge->getNextEdge());
            }

            delete current_edge;
            node1->setNumberOfEdges(node1->getNumberOfEdges() - 1);
            _number_of_edges--;
        }
    }
}

//Método para verificar se dois nós estão conectados
int Graph::conected(size_t node_id_1, size_t node_id_2)
{
    Node* node1 = _first;

    while(node1 != nullptr && node1->getId() != node_id_1) {
        node1 = node1->getNextNode();
    }

    if(node1 != nullptr) {
        Edge* current_edge = node1->getFirstNode();

        while(current_edge != nullptr) {
            if(current_edge->getTargetId() == node_id_2) {
                return 1; //Conectado
            }
            current_edge = current_edge->getNextEdge();
        }
    }
    return 0; //Não conectado
}

//Método para imprimir o grafo em um arquivo
void Graph::print_graph(ofstream& output_file)
{
    Node* current_node = _first;

    while(current_node != nullptr) {
        output_file << "Node " << current_node->getId() << " (" << current_node->getWeight() << ")" << endl;
        Edge* current_edge = current_node->getFirstNode();
        while(current_edge != nullptr) {
            output_file << "  -> " << current_edge->getTargetId() << "(weight " << current_edge->getWeight() << ")" << endl;
            current_edge = current_edge->getNextEdge();
        }
        current_node = current_node->getNextNode();
    }
}

//Método para imprimir o grafo na saída padrão
void Graph::print_graph()
{
    Node* current_node = _first;

    while(current_node != nullptr) {
        cout << "Node " << current_node->getId() << "(" << current_node->getWeight() << ")" << endl;
        Edge* current_edge = current_node->getFirstNode();
        while(current_edge != nullptr) {
            cout << "  -> " << current_edge->getTargetId() << "(weight " << current_edge->getWeight() << ")" << endl;
            current_edge = current_edge->getNextEdge();
        }
        current_node = current_node->getNextNode();
    }
}