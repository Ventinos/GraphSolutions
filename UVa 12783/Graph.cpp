#include "Graph.hpp"
#include <algorithm>
#include <stack>

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
Graph *Graph::readGraph(int n, int m) {
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
  for (int i = 0; i < m; i++) {
    std::cin >> entry1;
    std::cin >> entry2;

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

void Graph::dfsBridges(int u, int *dfs_numbercounter, std::vector<int> &dfs_num,
                       std::vector<int> &dfs_low, std::vector<int> &dfs_parent,
                       std::vector<int> &articulacao, int *dfsRoot,
                       int *rootChildren,
                       std::vector<std::pair<int, int>> *pontes) {
  *dfs_numbercounter = *dfs_numbercounter + 1;
  dfs_num.at(u) = *dfs_numbercounter;
  dfs_low.at(u) = dfs_num.at(u);
  for (auto v : getVertex(u)->getAdjacency()) {
    if (dfs_num.at(v->getId()) == -1 /*unvisited*/) {
      dfs_parent.at(v->getId()) = u;

      if (u == *dfsRoot)
        *rootChildren = *rootChildren + 1;

      dfsBridges(v->getId(), dfs_numbercounter, dfs_num, dfs_low, dfs_parent,
                 articulacao, dfsRoot, rootChildren, pontes);

      if (dfs_low.at(v->getId()) > dfs_num.at(u)) {
        if (v->getId() < u) {
          pontes->push_back(std::make_pair(v->getId(), u));
        } else {
          pontes->push_back(std::make_pair(u, v->getId()));
        }
        articulacao.at(u) = 1;
      }

      dfs_low.at(u) = std::min(dfs_low.at(u), dfs_low.at(v->getId()));
    } else if (v->getId() != dfs_parent.at(u)) {
      dfs_low.at(u) = std::min(dfs_low.at(u), dfs_low.at(v->getId()));
    }
  }
}

