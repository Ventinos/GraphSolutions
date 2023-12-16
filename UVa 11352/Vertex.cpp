#include "Vertex.hpp"
#include <iostream>

//setter
void Vertex::setUnsafe(){  
  if(Vertex::value!='A' && Vertex::value!='B') safe = false;
}
void Vertex::setMark(){  mark = true;  }

// Construtores:
Vertex::Vertex() {
  id = 0;
  value = '.';
  safe = true;
  mark = false;
  dist = 0;
}

Vertex::Vertex(int id, char value) {
  this->id = id;
  this->value = value;
  safe = true;
  mark = false;
  dist = 0;
}

std::vector<Vertex *> Vertex::getAdjacency() { return adjacency; }

// Adiciona o vertice v na lista de adjacencia:

void Vertex::addToAdjacency(Vertex *v) { adjacency.push_back(v); }

// Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << "," << value << ","<< safe << ")\n";}

// Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
  for (auto i : adjacency) {
    std::cout << "\t";
    i->print();
  }
}

bool Vertex::removeAdjacency(int id) {
  for (int i = 0; i < adjacency.size(); i++) {
    if (adjacency.at(i)->id == id) {
      adjacency.erase(adjacency.begin() + i);
      return true; // Remoção bem-sucedida
    }
  }
  return false;
}
