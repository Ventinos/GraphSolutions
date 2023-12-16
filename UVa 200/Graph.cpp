#include "Graph.hpp"

// Construtores:
Graph::Graph() { this->size = 0; }

Graph::Graph(int size) { this->size = size; }

int Graph::getSize() { return size; }
void Graph::setSize(int size) { this->size = size; }

// Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex *v) {
  vertices.push_back(v);
}

// Dado um id retorna o vertice naquela posi��o:
Vertex *Graph::getVertex(int id) { return vertices.at(id); }
Vertex *Graph::getVertexValue(char valor) {
  int j;
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices.at(i)->getValue() == valor) {
      j = i;
      break;
    }
  }
  return vertices.at(j);
}

bool Graph::verifyChar(char Char, int *vertex){
  for(auto i : vertices){
    if(i->getValue() == Char){
     *vertex = i->getId();
     return true; 
    }
  }
  return false;
}

// Faz toda a leitura de entrada e cria o grafo:
Graph *Graph::readGraph(std::ifstream* file){
  int i = 0,size = 0, vertex1, vertex2;
  Vertex *v;
  Graph *g = new Graph();
  std::string string1, string2 = "";
  *file >> string1;
  //std::cin >> string1;
  while(string2.compare("#") != 0){
    *file >> string2;
    //std::cin >> string2;
      for(i = 0; string1[i] == string2[i] && string1[i]; i++);
    if(string1[i] && string2[i]){
      if(!g->verifyChar(string1[i], &vertex1)){
      v = new Vertex(size, string1[i]);
      g->addVertex(v);
      vertex1 = size;
      size++;
    }
    if((!g->verifyChar(string2[i], &vertex2) && string2.compare("#") != 0)){
      v = new Vertex(size, string2[i]);
      g->addVertex(v);
      vertex2 = size;
      size++;
    }
      if(string2.compare("#") != 0) g->getVertex(vertex1)->addToAdjacency(g->getVertex(vertex2));
    }
    string1 = string2;
  }
  return g;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->printAdjacency();
  }
}

void Graph::dfs(int pos, bool *marcado, std::stack <Vertex*> *s)
{
  marcado[pos] = true;
  for(auto j : vertices.at(pos)->getAdjacency())
    {
      //procura marcar cada vértice adjacente, identificando-o pelo ID
      if(!marcado[j->getId()]) dfs(j->getId(),marcado,s);
    }
  s->push(vertices.at(pos));
}

std::stack <Vertex*> Graph::ordenaVertices() {//ordenação topológica
  std::stack <Vertex*> V;
  bool marcado[vertices.size()];
  for(int i = 0; i < sizeof(marcado); i++) marcado[i] = false;
  for(int i = 0; i < sizeof(marcado); i++)
    {
      if(!marcado[i]) dfs(i,marcado,&V);
    }
  return V;
}