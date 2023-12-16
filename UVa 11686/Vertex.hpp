#include <vector>

class Vertex
{
private:
  int id;
  std::vector<Vertex*> adjacency;
  bool check;
public:
  //Construtores:
  Vertex();
  Vertex(int id);
  //Getters:
  int getId();
  bool isChecked();
  std::vector<Vertex*> getAdjacency();
  //Setters:
  void setId(int id);
  void checkVertex();
  //Adiciona o vertice v na lista de adjacencia
  void addToAdjacency(Vertex *v);
  //Printa as informacoes de id e valor do vertice atual
  void print();  
  //Printa a lista de adjacencia do vertice atual
  void printAdjacency();  
  //funcoes auxiliares:
  bool removeAdjacency(int id);
};


