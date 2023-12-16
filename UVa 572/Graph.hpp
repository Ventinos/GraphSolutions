#include "Vertex.hpp"

class Graph
{
private:
  std::vector<Vertex*> vertices;
  int size;
  int edges;
public:
//Construtores:
  Graph();
  Graph(int size, int edges);
//Faz toda a leitura de entrada e cria o grafo:
  static Graph* readGraph(int j, int k);
//Adiciona novo vertice na lista de vertices:
  void addVertex(Vertex* v);
//Setter de arestas
  void setEdges(int edges);
//Conta a quantidade de vértices de valor 1
  int busca();
//Busca vértices adjacentes ao id que possuem valor 1
  void contaAdj(int id,bool vet[]);
//Dado um id retorna o vertice naquela posição:
  Vertex* getVertex(int id);
//Imprime todo o grafo:
  void print();
};