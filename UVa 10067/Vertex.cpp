#include "Vertex.hpp"
#include <iostream>

// Construtores:
Vertex::Vertex() {
  
}

Vertex::Vertex(int id) {
  this->id = id;
  dist = -1;
}

std::vector<Vertex *> Vertex::getAdjacency() { return adjacency; }

// Adiciona o vertice v na lista de adjacencia:

void Vertex::addToAdjacency(Vertex *v) { adjacency.push_back(v); }

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id <<")\n";}

// Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
  for (auto i : adjacency) {
    std::cout << "\t";
    i->print();
  }
}

