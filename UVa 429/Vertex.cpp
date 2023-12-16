#include "Vertex.hpp"
#include <iostream>

// Construtores:
Vertex::Vertex() {}

Vertex::Vertex(int id, std::string value) {
  this->id = id;
  this->value = value;
  marked = false;
}

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << ", " << value << ")\n"; }