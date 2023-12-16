#include <vector>
#include <string>
class Vertex
{
private:
  int id;
  std::vector<Vertex*> adjacency;
  std::string city;
  bool safe;

public:
  //Construtores:
  Vertex();
  Vertex(int id);
  Vertex(int id,std::string city);
  //Getters:
  int getId();
  int getValue();
  bool getSafe();
  std::string getCity();
  std::vector<Vertex*> getAdjacency();
  //Setters:
  void setId(int id);
  void setValue(int value);
  void setSafe(bool safe);
  void setCity(std::string city);
  //Adiciona o vertice v na lista de adjacencia
  void addToAdjacency(Vertex *v);
  //Printa as informacoes de id e valor do vertice atual
  void print();  
  //Printa a lista de adjacencia do vertice atual
  void printAdjacency();
  //Verifica se vizinho é seguro
  bool verificaViz();
};