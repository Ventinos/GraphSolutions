#include "Graph.hpp"
#include <algorithm>

// Construtores:
Graph::Graph() { this->size = 0; }

Graph::Graph(int size) { this->size = size; }

int Graph::getSize() { return size; }
void Graph::setSize(int size) { this->size = size; }

// Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex *v) { vertices.push_back(v); }

// Dado um id retorna o vertice naquela posição:
Vertex *Graph::getVertex(int id) {
  for (Vertex *i : vertices)
    if (i->getId() == id)
      return i;
  return NULL;
}

// Faz toda a leitura de entrada e cria o grafo:
Graph *Graph::readGraph(int n,int m) {
  int entry1, entry2, k;
  Graph *g;
  Vertex *v1, *v2;
  g = new Graph();

  // cria vertices com id baseando-se em n
  for (int i = 0; i < n; i++) {
    v1 = new Vertex(i);
    g->addVertex(v1);
  }
  // conecta todos os vertices que deverão ser conectados
  while(true) {
    std::cin >> entry1;
    std::cin >> entry2;
    if(entry1 == -1 || entry2 == -1) break;
    v1 = g->getVertex(entry1);
    v2 = g->getVertex(entry2);
    v1->addToAdjacency(v2);
    v2->addToAdjacency(v1);
  }
  // retorna o grafo com todos os vertices
  return g;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->printAdjacency();
  }
}

void Graph::dfs_qtd(int u, int v){
  vertices.at(u)->setMark(true);
  for(auto i : vertices.at(u)->getAdjacency())
    {
      //procura marcar cada vértice adjacente, identificando-o pelo ID
      if((!i->getMark()) && i->getId() != v) dfs_qtd(i->getId(),v);
    }
}
