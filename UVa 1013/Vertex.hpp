#include <vector>
#include <string>
class Vertex
{
  public:
  int x;
  int y;
  int id;
  int inhabitants;
  //Construtores:
  Vertex();
  Vertex(int x, int y, int id, int inhabitants);
  //Printa as informacoes de id e valor do vertice atual
  void print();  
};

