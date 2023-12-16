#include "Vertex.hpp"
class Edges
{
  public:
  Vertex *a;
  Vertex *b;
  double peso;
  bool marked;
  //Construtores:
  Edges();
  Edges(Vertex* a, Vertex* b, double peso);
  //Printa as informacoes de id e valor do vertice atual
  void print();  
};

