#include "Vertex.hpp"
#include <iostream>

// Getters:
int Vertex::getId() { return id; }
char Vertex::getValue() { return value; }
std::vector<Vertex *> Vertex::getAdjacency() { return adjacency; }
bool Vertex::isChecked() { return check; }

// Setters:
void Vertex::setId(int id) { this->id = id; }
void Vertex::setValue(char value) { this->value = value; }
void Vertex::checkVertex() { check=true; }

// Construtores:
Vertex::Vertex() {
  id = 0;
  value = ' ';
  check = false;
}

Vertex::Vertex(int id, char value) {
  this->id = id;
  this->value = value;
  check = false;
}

// Adiciona o vertice v na lista de adjacencia:

void Vertex::addToAdjacency(Vertex *v) { 
  adjacency.push_back(v); 
}

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << "," << value << ")\n"; }

// Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
  Vertex::print();
  for (auto i : adjacency) {
    std::cout << "\t";
    i->print();
  }
}