#include "Vertex.hpp"
#include <stack>

class Graph
{
private:
  std::vector<Vertex*> vertices;
  int size;
public:
//Construtores:
  Graph();
//Faz toda a leitura de entrada e cria o grafo:
  static Graph *readGraph(int n, int m, Graph *inv);
//Adiciona novo vertice na lista de vertices:
  void addVertex(Vertex* v);
  void setSize(int size);
//Dado um id retorna o vertice naquela posição:
  Vertex *getVertex(std::string value);
  Vertex *getById(int id);
//GetVertices:
  int getSize();
  std::vector<Vertex*> getVertices();
//Imprime todo o grafo:
  void print();
//Resolução do problema:
  static int solve(Graph* g1, Graph* g2);
  void dfs(int id);
//reset
  void resetMark();
};

