#include <vector>
#include <string>
class Vertex
{
public:
  //Atributos
  std::vector<Vertex*> adj;
  std::string value;
  int id;
  bool marked {false};

  //Construtores:
  Vertex();
  Vertex(int id, std::string value);

  //Printa as informacoes de id
  //e valor do vertice atual
  void print();  
};

