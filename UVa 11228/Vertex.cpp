#include "Vertex.hpp"
#include <iostream>

// Construtores:
Vertex::Vertex() { id = -1; }

Vertex::Vertex(int x, int y, int id) {
  this->x = x;
  this->y = y;
  this->id = id;
}

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() {
  std::cout << "(" << x << ", " << y << "," << id << ")\n";
}
