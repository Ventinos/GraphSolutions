#include "Vertex.hpp"
#include <iostream>

// Construtores:
Vertex::Vertex() {
  id = 0;
}

Vertex::Vertex(int id, int pos) {
  this->id = id;
  this->pos = pos;
}

std::vector<Vertex *> Vertex::getAdjacency() { return adjacency; }

// Adiciona o vertice v na lista de adjacencia:

void Vertex::addToAdjacency(Vertex *v) { adjacency.push_back(v); }

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << ")" << "\n";}

// Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
  for (auto i : adjacency) {
    std::cout << "\t";
    i->print();
  }
}