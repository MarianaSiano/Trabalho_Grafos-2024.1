#ifndef ARESTA_H
#define ARESTA_H

#include "defines.hpp"
#include <iostream>

using namespace std;

class Aresta 
{
    private:
        size_t nodeAdj;
        size_t nodeOrigem;

        Aresta *proximaAresta;
        float peso;
        size_t id_Destino;

    public:
        //Construtores e Destrutor
        Aresta() {}
        Aresta(size_t node){
            this->nodeAdj = node;
            this->peso = -1;
            this->proximaAresta = nullptr;
        }

        Aresta(size_t node, float peso) {
            this->nodeAdj = node;
            this->peso = peso;
            this->proximaAresta = nullptr;
        }

        Aresta(size_t node, float peso, size_t nodeOrigem){
            this->nodeAdj = node;
            this->peso = peso;
            this->proximaAresta = nullptr;
            this->nodeOrigem = nodeOrigem;
        }

        ~Aresta(){
            this->nodeOrigem = -1;
            this->peso = -1;
        }

        //Get
        float getPeso() { return peso; }
        Aresta* getproxAresta() { return this->proximaAresta; }
        size_t getNodeAdj() { return nodeAdj; }
        size_t getNodeOrigem() { return nodeOrigem; }

        //Set
        void setOrigem(size_t origem) { nodeOrigem = origem; }
        void sexProx(Aresta *aresta) { this->proximaAresta = aresta; }
};

// struct Aresta
// {
//     Aresta  *_next_edge;
//     float  _weight;
//     size_t _target_id;
// };

#endif /* ARESTA_H */
