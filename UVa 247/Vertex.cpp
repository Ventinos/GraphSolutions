#include "Vertex.hpp"
#include <iostream>

//Getters:
int Vertex::getId() { return id; }
std::vector<Vertex *> Vertex::getAdjacency() { return adjacency; }
int Vertex::getCirculo() { return circulo; }
std::string Vertex::getName() { return name; }

//Setters:
void Vertex::setId(int id) { this->id = id; }
void Vertex::setCirculo(int circ) { this->circulo = circ; }
void Vertex::setName(std::string name) { this->name = name;}

//Construtores:
Vertex::Vertex() {
  id = 0;
  circulo=0;
}

Vertex::Vertex(int id) {
  this->id = id;
  circulo=0;
}

Vertex::Vertex(int id,std::string name) {
  this->id = id;
  this->name = name;
  circulo=0;
}

//Adiciona o vertice v na lista de adjacencia:
void Vertex::addToAdjacency(Vertex *v) { adjacency.push_back(v); }

//Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << name << " " << circulo << ")\n"; }

//Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
  Vertex::print();
  for (auto i : adjacency) {
    std::cout << "\t";
    i->print();
  }
}