#include "Vertex.hpp"
#include <iostream>

//Getters:
int Vertex::getId() { return id; }
std::vector<Vertex *> Vertex::getAdjacency() { return adjacency; }
bool Vertex::getSafe() { return safe; }
std::string Vertex::getCity() { return city; }

//Setters:
void Vertex::setId(int id) { this->id = id; }
void Vertex::setSafe(bool safe) { this->safe = safe;}
void Vertex::setCity(std::string city) { this->city = city;}

//Construtores:
Vertex::Vertex() {
  id = 0;
  safe = false;
}

Vertex::Vertex(int id) {
  this->id = id;
  safe = false;
}

Vertex::Vertex(int id,std::string city) {
  this->id = id;
  this->city = city;
  safe = false;
}

//Adiciona o vertice v na lista de adjacencia:
void Vertex::addToAdjacency(Vertex *v) { adjacency.push_back(v); }

//Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "(" << id << city << " " << ")\n"; }

//Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
  Vertex::print();
  for (auto i : adjacency) {
    std::cout << "\t";
    i->print();
  }
}
  //Verifica se vizinho é seguro
bool Vertex::verificaViz(){
  bool flag = false;
  for (auto i : adjacency)
    if(i->getSafe())
      flag=true;
  return flag;
}