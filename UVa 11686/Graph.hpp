#include "Vertex.hpp"

class Graph
{
private:
  std::vector<Vertex*> vertices;
public:
//Construtores:
  Graph();
//Faz toda a leitura de entrada e cria o grafo:
Graph *readGraph(int m, int n);
//Adiciona novo vertice na lista de vertices:
  void addVertex(Vertex* v);
//Dado um id retorna o vertice naquela posição:
  Vertex* getVertex(int id);
//GetVertices:
  std::vector<Vertex*> getVertices();
//Imprime todo o grafo:
  void print();
//solucao:
  void solve();
};

