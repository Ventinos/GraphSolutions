#include "Vertex.hpp"
#include <iostream>


//Construtores:
Vertex::Vertex() {
  aresta.first = 0;
  aresta.second = 0;
}

Vertex::Vertex(int id1, int id2) {
  aresta.first = id1;
  aresta.second = id2;
}

Vertex::Vertex(int id1, int id2, int size) {
  aresta.first = id1;
  aresta.second = id2;
  this->size = size;
}

//Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << aresta.first << " " << aresta.second << " [" << size << "])\n";}