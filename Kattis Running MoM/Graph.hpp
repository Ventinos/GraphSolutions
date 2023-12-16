#include "Vertex.hpp"
#include <fstream>

class Graph
{
private:
  std::vector<Vertex*> vertices;
  int size;
  int edges;
public:
//Construtores:
  Graph();
  Graph(int size);
  Graph(int size, int edges);
//Getters:
  int getSize();
  int getEdge();
//Dado um id retorna o vertice naquela posição:
  Vertex* getVertex(int id);
//Setters:
  void setEdge(int edge);
  void setSize(int size);
//Faz toda a leitura de entrada e cria o grafo:
  static Graph* readGraph(int n, std::ifstream* file);
//Adiciona novo vertice na lista de vertices:
  void addVertex(Vertex* v);
//Imprime todo o grafo:
  void print();
//Verifica se a string (cidade) pertence à algum vertice do grafo
  bool verifyCity(std::string city, int *vertex);
//Operações que verificam se o vertice do grafo é seguro (vertice está em ciclo) ou não
  void verificaSafe();
  void buscaLoop(int id,bool vetAt[], bool vet[]);
};