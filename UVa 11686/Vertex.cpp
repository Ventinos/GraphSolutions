#include "Vertex.hpp"
#include <iostream>

// Getters:
int Vertex::getId() { return id; }
std::vector<Vertex *> Vertex::getAdjacency() { return adjacency; }
bool Vertex::isChecked() { return check; }

// Setters:
void Vertex::setId(int id) { this->id = id; }
void Vertex::checkVertex() { check = true; }

// Construtores:
Vertex::Vertex() {
  id = 0;
  check = false;
}

Vertex::Vertex(int id) {
  this->id = id;
  check = false;
}

// Adiciona o vertice v na lista de adjacencia:

void Vertex::addToAdjacency(Vertex *v) { adjacency.push_back(v); }

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << ")\n"; }

// Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
  Vertex::print();
  for (auto i : adjacency) {
    std::cout << "\t";
    i->print();
  }
}

bool Vertex::removeAdjacency(int id) {
  for (int i = 0; i < adjacency.size(); i++) {
    if (adjacency.at(i)->getId() == id) {
      adjacency.erase(adjacency.begin() + i);
      return true; // Remoção bem-sucedida
    }
  }
  return false;
}
