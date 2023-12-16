#include "Vertex.hpp"
#include <iostream>

//Getters:
int Vertex::getId() { return id; }
char Vertex::getValue() { return value; }
std::vector<Vertex*> Vertex::getAdjacency() { return adjacency; }
Vertex* Vertex::getAdjacencyNotColored() 
{
  int j;
  for(j = 0; j < adjacency.size(); j++)
    {
      if(adjacency.at(j)->getId()==0)
      {
        break;
      }
    }
  return adjacency.at(j); 
}

//Setters:
void Vertex::setId(int id) { this->id = id; }
void Vertex::setValue(char value) { this->value = value; }

//Construtores:
Vertex::Vertex() {
    id = 0;
    value = ' ';
}

Vertex::Vertex(char value) {
    this->id = 0;
    this->value = value;
}

Vertex::Vertex(int id,char value) {
    this->id = id;
    this->value = value;
}

//Adiciona o vertice v na lista de adjacencia:
void Vertex::addToAdjacency(Vertex *v) 
{
    adjacency.push_back(v);
}

//adiciona o vertice v na lista de adjacencia, com sua cor e valor

//Printa as informacoes de id e valor do vertice atual:
void Vertex::print() { std::cout << "\n" << "(" << id << "," << value << ")\n"; }

//Printa a lista de adjacencia do vertice atual:
void Vertex::printAdjacency() {
    std::cout << "vertice: ";
    Vertex::print();
    for (auto i : adjacency) {
        std::cout << "\t";
        i->print();
    }
}