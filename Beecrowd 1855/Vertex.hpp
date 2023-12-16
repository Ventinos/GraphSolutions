#include <vector>
class Vertex
{
private:
  int id;
  char value;
  std::vector<Vertex*> adjacency;
  bool check;
public:
  //Construtores:
  Vertex();
  Vertex(int id, char value);
  //Getters:
  int getId();
  char getValue();
  bool isChecked();
  std::vector<Vertex*> getAdjacency();
  //Setters:
  void setId(int id);
  void setValue(char value);
  void checkVertex();
  //Adiciona o vertice v na lista de adjacencia
  void addToAdjacency(Vertex *v);
  //Printa as informacoes de id e valor do vertice atual
  void print();  
  //Printa a lista de adjacencia do vertice atual
  void printAdjacency();  
};

