#include <vector>
#include <string> 
#include <iostream>

class Vertex{
public:
  int id;
  int pos;
  std::vector<Vertex*> adjacency;

  Vertex();
  Vertex(int id, int pos);

  //add do vertice na adjacencia
  std::vector<Vertex*> getAdjacency();
  //Adiciona o vertice v na lista de adjacencia
  void addToAdjacency(Vertex *v);
  //Printa as informacoes de id e valor do vertice atual
  void print();
  //Printa a lista de adjacencia do vertice atual
  void printAdjacency();  
};
