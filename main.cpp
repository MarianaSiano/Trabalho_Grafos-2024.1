#include "include/defines.hpp"
#include "include/Graph.hpp"
#include "include/Edge.hpp"
#include "include/Node.hpp"

int main(int argc, char* argv[])
{
    //Verifica se o número correto de argumentos foi passado
    if(argc != 6) {
        cout << "Uso: execGrupo2 <arquivo_entrada> <arquivo_saida> <direcao> <pesoAresta> <pesoNos>" << endl;
        return 1; //Retorna um código de erro
    }

    //Lê os argumentos
    const char* arquivo_entrada = argv[1];
    const char* arquivo_saida = argv[2];
    int direcao = stoi(argv[3]); //Converte para inteiro
    double pesoAresta = stod(argv[4]); //Converte para double
    int pesoNos = stoi(argv[5]); //Converte para inteiro

    cout << "Arquivo de entrada => " << arquivo_entrada << endl;
    cout << "Arquivo de saída => " << arquivo_saida << endl;
    cout << "Direção => " << direcao << endl;
    cout << "Peso das Arestas => " << pesoAresta << endl;
    cout << "Peso dos nós => " << pesoNos << endl;
}