#include "Graph.hpp"
#include <iostream>
#include <queue>

// Construtores:
Graph::Graph() {}

// Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex *v) { vertices.push_back(v); }

// Dado um id retorna o vertice naquela posição:
Vertex *Graph::getVertex(int id) {
  for (Vertex *w : vertices) {
    if (w->getId() == id)
      return w;
  }
  return NULL;
}

std::vector<Vertex *> Graph::getVertices() { return vertices; }

// Faz toda a leitura de entrada e cria o grafo:
Graph *Graph::readGraph(int m, int n) {
  int entry1, entry2, k;
  Graph *g;
  Vertex *v1, *v2;
  g = new Graph();
  // adiciona os vertices que não estão conectados a ninguem
  for (int i = n; i > 0; i--) {
    if (g->getVertex(i) == NULL) {
      v1 = new Vertex(i);
      g->addVertex(v1);
    }
  }

  // cria e conecta todos os vertices que deverão ser conectados
  for (int i = 0; i < m; i++) {
    std::cin >> entry1;

    if (entry1 == 0)
      break;
    if (g->getVertex(entry1) == NULL) {
      v1 = new Vertex(entry1);
      g->addVertex(v1);
    } else {
      v1 = g->getVertex(entry1);
    }

    std::cin >> entry2;
    if (g->getVertex(entry2) == NULL) {
      v2 = new Vertex(entry2);
      g->addVertex(v2);
    } else {
      v2 = g->getVertex(entry2);
    }
    k = 1;
    for (auto j : v2->getAdjacency()) {
      if (j->getId() == v1->getId())
        k = 0;
    }
    if (k == 1) {
      v2->addToAdjacency(v1);
    }
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

void Graph::solve() {
  std::queue<Vertex *> queue;
  Vertex *v = NULL;
  /*
    Isso aqui procura por vertices v de lista de adjacencia vazia, se achar
    ele remove esse v das listas de adjacencia de todos os vertices bota v numa
    fila e remove v do grafo. Depois disso tira os elementos da fila.
  */

  // Percorre todos os vértices da lista de vértices
  for (int j = 0; j < vertices.size(); j++) {
    v = vertices.at(j);
    // verifica se tem lista vazia:
    if (v->getAdjacency().empty()) {
      // removendo das listas de adj:
      for (Vertex *w : vertices)
        w->removeAdjacency(v->getId());
      // botando na fila:
      queue.push(v);
      // removendo do grafo:
      vertices.erase(vertices.begin() + j);
      j = -1;
    }
  }

  // se pelo menos um dos vertices não pode ser removido,
  // printa "IMPOSSIBlE"e limpa o grafo
  if (vertices.size() != 0) {
    std::cout << "IMPOSSIBLE" << std::endl;
    vertices.clear();
    return;
  }
  // desenfilera os valores:
  while (queue.size() != 0) {
    std::cout << queue.front()->getId() << std::endl;
    queue.pop();
  }
}