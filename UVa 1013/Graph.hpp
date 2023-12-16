#include "Edges.hpp"
#include <vector>
#include <utility>
#include <iostream>
class Graph
{
  public:
  //ATRIBUTOS:
  std::vector<Edges*> arestas;
  std::vector<Vertex*>vertices;
  int numVertices;
  
  //METODOS:
  //Construtores:
  Graph();
  Graph(int size);

  //Faz toda a leitura de entrada e cria o grafo:
  static Graph* readGraph(int n);
  Vertex* getByValue(int x, int y);
  //Adiciona novo vertice na lista de vertices:
  void addEdge(Edges* e);
  bool pertence(int x,int y);
  //Imprime todo o grafo:
  void print();
  //Kruskal:
  Graph* kruskal(double *res);
};

