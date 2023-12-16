#include "Vertex.hpp"
#include <fstream>
#include <queue>
class Graph
{
private:
  std::vector<Vertex*> vertices;
  int size;
  int edges;
public:
//Construtores, Getters e Setters:
  Graph();
  Graph(int size);
  Graph(int size, int edges);
  int getSize();
  int getEdge();
//Dado um id retorna o vertice naquela posição:
  Vertex* getVertex(int id);
  void setEdge(int edge);
  void setSize(int size);
//Faz toda a leitura de entrada e cria o grafo:
  static std::pair<Graph*,Graph*> readGraph(int n);
//Adiciona novo vertice na lista de vertices:
  void addVertex(Vertex* v);
//Imprime todo o grafo:
  void print();
//Verifica se a string (cidade) pertence à algum vertice do grafo
  bool verifyName(std::string name, int *vertex);
//descobre quais componentes são fortemente conectados
  static std::queue<std::string> verificaCirculo(Graph* g1, Graph* g2);
//realiza dfs e retorna o vetor de visitas
  void dfs(int n, bool vis[]);
};
