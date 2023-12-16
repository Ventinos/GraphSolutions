#include <vector>
#include <string> 
#include <iostream>

class Vertex{
public:
  int id;
  std::vector<Vertex*> adjacency;
  bool mark;
  bool safe;
  char value;
  int dist;

  Vertex();
  Vertex(int id, char value);

  //UM setter
  void setUnsafe();
  void setMark();
  //add do vertice na adjacencia
  std::vector<Vertex*> getAdjacency();
  //Adiciona o vertice v na lista de adjacencia
  void addToAdjacency(Vertex *v);
  //Printa as informacoes de id e valor do vertice atual
  void print();
  //Printa a lista de adjacencia do vertice atual
  void printAdjacency();  
  //funcoes auxiliares:
  bool removeAdjacency(int id);
};
