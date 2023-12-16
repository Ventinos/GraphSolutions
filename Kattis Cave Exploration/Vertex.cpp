#include "Vertex.hpp"
#include <iostream>

// Getters:
int Vertex::getId() { return id; }
std::vector<Vertex *> Vertex::getAdjacency() { return adjacency; }

// Setters:
void Vertex::setId(int id) { this->id = id; }

// Construtores:
Vertex::Vertex() { id = 0; }

Vertex::Vertex(int id) {
  this->id = id;
  marked = false;
  safe = false;
}

// Adiciona o vertice v na lista de adjacencia:
void Vertex::addToAdjacency(Vertex *v) { adjacency.push_back(v); }

// adiciona o vertice v na lista de adjacencia, com sua cor e valor

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << "," << safe << ")\n"; }

// Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
  Vertex::print();
  for (auto i : adjacency) {
    std::cout << "\t";
    i->print();
  }
}

bool Vertex::isSafe() { return safe; }

bool Vertex::isMarked() { return marked; }

void Vertex::mark() { marked = true; }
void Vertex::unmark() { marked = false; }
void Vertex::setSafe(bool safe) { this->safe = safe; }