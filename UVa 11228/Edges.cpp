#include "Edges.hpp"
#include <iostream>

// Construtores:
Edges::Edges() {
  a = NULL;
  b = NULL;
  peso = 0;
}

Edges::Edges(Vertex *a, Vertex *b, double peso) {
  this->a = a;
  this->b = b;
  this->peso = peso;
}

// Printa as informacoes de id e valor do vertice atual:
void Edges::print() {
  a->print();
  b->print();
  std::cout<< "Peso: "<< peso << std::endl;
}
