#include <vector>
#include <string>
class Vertex
{
private:
  int id;
  std::vector<Vertex*> adjacency;
  std::string name;
  int circulo;

public:
  //Construtores:
  Vertex();
  Vertex(int id);
  Vertex(int id,std::string city);
  //Getters:
  int getId();
  int getCirculo();
  std::string getName();
  std::vector<Vertex*> getAdjacency();
  //Setters:
  void setId(int id);
  void setCirculo(int value);
  void setName(std::string name);
  //Adiciona o vertice v na lista de adjacencia
  void addToAdjacency(Vertex *v);
  //Printa as informacoes de id e valor do vertice atual
  void print();  
  //Printa a lista de adjacencia do vertice atual
  void printAdjacency();
};
