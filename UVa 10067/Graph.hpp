#include "Vertex.hpp"
#include <fstream>
#include <queue>
class Graph
{
public:
  std::vector<Vertex*> vertices;

//Construtores:
  Graph();
  Graph(int linha, int coluna);

//Faz toda a leitura de entrada e cria o grafo:
  static Graph* readGraph();
  void insereAdj(int i);
//Imprime todo o grafo:
  void print();
  void bfs(int S);
  void resetMarks();
};
