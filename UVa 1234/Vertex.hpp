#include <vector>
#include <string>
class Vertex
{
public:
  //Atributos
  std::pair<int,int> aresta;
  int size;

  //Construtores:
  Vertex();
  Vertex(int id1, int id2);
  Vertex(int id1, int id2, int size);

  //Printa as informacoes de id e valor do vertice atual
  void print();  
};
