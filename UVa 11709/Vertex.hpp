#include <vector>
#include <string> 
#include <iostream>

class Vertex{
private:
  int id;
  std::vector<Vertex*> adjacency;
  bool check;
  int circulo;
  std::string value;
public:
  Vertex();
  Vertex(int id, std::string value);
  //Getters:
  int getId();
  int getCirculo();
  std::string getValue();
  bool isChecked();
  std::vector<Vertex*> getAdjacency();
  //Setters:
  void setId(int id);
  void setCirculo(int circulo);
  void setValue(std::string value);
  void checkVertex();
  void uncheckVertex();
  //Adiciona o vertice v na lista de adjacencia
  void addToAdjacency(Vertex *v);
  //Printa as informacoes de id e valor do vertice atual
  void print();
  //Printa a lista de adjacencia do vertice atual
  void printAdjacency();  
  //funcoes auxiliares:
  bool removeAdjacency(int id);
};


