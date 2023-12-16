#include "Vertex.hpp"
#include <fstream>
#include <queue>
class Graph
{
public:
  std::vector<Vertex*> vertices;
  int linha;
  int coluna;
  int reinoA;
  int reinoB;

//Construtores:
  Graph();
  Graph(int linha, int coluna);

//Faz toda a leitura de entrada e cria o grafo:
  static Graph* readGraph();

//Imprime todo o grafo:
  void print();

//Imprime a resposta
  void printResul();

//torna perigoso regiões com cavalos e potencialmente
//posições que cavalos podem acessar com 1 movimento
  void markUnsafePlaces();

//bfs para caminhos mínimos
  void bfs(int e);
};
