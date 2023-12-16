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
Graph *Graph::readGraph() {
  int entry1, entry2, k;
  Graph *g;
  Vertex *v1, *v2;
  g = new Graph();
  // adiciona os vertices que não estão conectados a ninguem
  int m,n;
  std::cin >> n;
  g->size = n;
  std::cin >> m;
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
                       int *dfsRoot,
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
                 dfsRoot, rootChildren, pontes);

      if (dfs_low.at(v->getId()) > dfs_num.at(u)) {
        pontes->push_back(std::make_pair(v->getId(), u));
      }

      dfs_low.at(u) = std::min(dfs_low.at(u), dfs_low.at(v->getId()));
    } else if (v->getId() != dfs_parent.at(u)) {
      dfs_low.at(u) = std::min(dfs_low.at(u), dfs_low.at(v->getId()));
    }
  }
}

int Graph::dfs(int e, std::vector<std::pair<int, int>> pontes) {
  int u, ret = 0;
  std::stack<int> stack;
  stack.push(e);
  bool flag = false;

  while (!stack.empty()) {
    u = stack.top();
    stack.pop();
    Vertex *v = getVertex(u);

    if (!v->isMarked()) {
      v->mark();
      v->setSafe(true);
      ret++;
      for (Vertex *i : v->getAdjacency()) {
        if (!i->isMarked()) {
          for (auto p : pontes) {
            flag = (v->getId() == p.first && i->getId() == p.second) ||
                   (v->getId() == p.second && i->getId() == p.first);
            if (flag)
              break;
          }
          if (!flag)
            stack.push(i->getId());
        }
      }
    }
  }
  return ret;
}
