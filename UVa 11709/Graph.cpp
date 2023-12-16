#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <string>

// Construtores:
Graph::Graph() {}

// Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex *v) { vertices.push_back(v); }
int Graph::getSize() { return size; }
void Graph::setSize(int size) { this->size = size; }
// Dado um id retorna o vertice naquela posição:
Vertex *Graph::getVertex(std::string value) {
  for (Vertex *w : vertices) {
    if (w->getValue() == value)
      return w;
  }
  return NULL;
}

Vertex *Graph::getById(int id) {
  // std::cout << "id maldito: " << id << std::endl;
  for (Vertex *w : vertices) {
    // std::cout << "w-id maldito: " << w->getId() << std::endl;
    if (w->getId() == id)
      return w;
  }
  return NULL;
}

std::vector<Vertex *> Graph::getVertices() { return vertices; }

// Faz toda a leitura de entrada e cria o grafo:
// n = nroVertices,  m = nroArestas, inv = grafo transposto
Graph *Graph::readGraph(int n, int m, Graph *inv) {
  Graph *g = new Graph();
  g->setSize(n);
  inv->setSize(n);

  Vertex *v = NULL;
  Vertex *u = NULL;

  std::string name1, name2;

  // verifica entradas:
  if (n == 0 && m == 0)
    return NULL;

  // leitura dos vértices do grafo
  for (int i = 0; i < n; i++) {
    std::getline(std::cin, name1);
    v = new Vertex(i, name1);
    u = new Vertex(i, name1);
    // inserindo vertices no normal:
    g->addVertex(v);
    // inserindo vertices no transposto:
    inv->addVertex(u);
  }

  // conexão entre vértices
  for (int i = 0; i < m; i++) {
    std::getline(std::cin, name1);
    std::getline(std::cin, name2);

    // montando o grafo normal:
    v = g->getVertex(name1);
    u = g->getVertex(name2);
    v->addToAdjacency(u);

    // montando o grafo transposto:
    v = inv->getVertex(name1);
    u = inv->getVertex(name2);
    u->addToAdjacency(v);
  }

  return g;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    std::cout << i->getCirculo() << std::endl;
    i->printAdjacency();
  }
}

void Graph::dfs(int id) {
  Graph::getById(id)->checkVertex();
  for (Vertex *i : getById(id)->getAdjacency()) {
    if (!i->isChecked())
      dfs(i->getId());
  }
}

int Graph::solve(Graph *g1, Graph *g2) {
  int cnt = 0;

  g1->resetMark();
  g2->resetMark();

  for (int i = 0; i < g1->getSize(); i++) {
    if (g1->getById(i)->getCirculo() == 0) {
      cnt++;
      g1->dfs(i);
      g2->dfs(i);
      for (int j = 0; j < g1->getSize(); j++) {
        if (g1->getById(j)->isChecked() && g2->getById(j)->isChecked())
          if (g1->getById(j)->getCirculo() == 0) {
            g1->getById(j)->setCirculo(cnt);
            g2->getById(j)->setCirculo(cnt);
          }
      }
    }
    g1->resetMark();
    g2->resetMark();
  }
  return cnt;
}

void Graph::resetMark() {
  for (Vertex *w : vertices)
    w->uncheckVertex();
}
