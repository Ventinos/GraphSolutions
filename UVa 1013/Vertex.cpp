#include "Vertex.hpp"
#include <iostream>

// Construtores:
Vertex::Vertex() { id = -1; }

Vertex::Vertex(int x, int y, int id, int inhabitants) {
  this->x = x;
  this->y = y;
  this->id = id;
  this->inhabitants = inhabitants;
}

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() {
  std::cout << "(" << x << ", " << y << "," << inhabitants << "," << id << ")\n";
}
