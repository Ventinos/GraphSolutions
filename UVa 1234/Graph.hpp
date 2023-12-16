#include "Vertex.hpp"
#include <fstream>
#include <queue>
class Graph
{
public:
  std::vector<Vertex*> vertices;
  int size;

//Construtores:
  Graph();
  Graph(int size);

//Faz toda a leitura de entrada e cria o grafo:
  static Graph* readGraph();

//soluçaõ do problema, retorna o preço das cameras
  int solve();

//Imprime todo o grafo:
  void print();

//Imprime a resposta
  void printResul();
};
