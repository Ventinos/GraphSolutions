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
  static Graph* readGraph(int a, int b);

//Verifica se um id está no grafo
  int inGraph(int id);

  Vertex* getVet(int id);

//Imprime todo o grafo:
  void print();

  float solve();

  int bfs(Vertex* v);
};
