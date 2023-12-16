#include "Graph.hpp"
#include <iostream>

// Construtores:
Graph::Graph() {
  this->x = 0;
  this->y = 0;
}

Graph::Graph(int x, int y) {
  this->x = x;
  this->y = y;
}

// Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex *v) { vertices.push_back(v); }

// Dado um id retorna o vertice naquela posição:
Vertex *Graph::getVertex(int id) { return vertices.at(id); }

std::vector<Vertex *> Graph::getVertices() { return vertices; }

// Faz toda a leitura de entrada e cria o grafo:
Graph *Graph::readGraph(bool *start, bool *chest) {
  int x = 0, y = 0, size = 0;
  char entry, value;
  Graph *g;
  Vertex *v;
  *start = true;
  *chest = false;

  std::cin >> x;
  std::cin >> y;
  size = x * y;
  g = new Graph(x, y);

  for (int i = 0; i < size; i++) {
    std::cin >> entry;
    v = new Vertex(i, entry);
    g->addVertex(v);
  }
  // Fazendo as conexoes entre os vertices:
  for (Vertex *i : g->getVertices()) {
    value = i->getValue();
    if (value == '.' || value == '*') {
      if (value == '*') {
        *chest = true;
      }
    } else {
      if ((value == '^' || value == '.') && i->getId() == 0) {
        *start = false;
      }
      g->connectVertices(i, x, y, value);
    }
  }
  return g;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->printAdjacency();
  }
}

// Faz as conexoes no mapa:
// conecta a tudo na direcao indicada ate a proxima seta:
void Graph::connectVertices(Vertex *i, int x, int y, char value) {
  int id = i->getId();
  switch (value) {
  // CUIDADO MT MCC NESSES FOR! CAUTION! DANGER!
  case '>':
    if (id % x != x - 1) {
      for (int j = 1; id + j % x != 0; j++) {
        if (!Graph::connect(i, id, j)) {
          break;
        }
      }
    }
    break;
  case '<':
    if (id % x != 0) {
      for (int j = -1; (id + j) % x != x - 1; j--) {
        if (!Graph::connect(i, id, j)) {
          break;
        }
      }
    }
    break;
  case 'v':
    if (!(id >= x * (y - 1) && id <= (x * y) - 1)) {
      for (int j = x; id+j <= (x*y)-1; j += x) {
        if (!Graph::connect(i, id, j)) {
          break;
        }
      }
    }
    break;
  case '^':
    if (!(id >= 0 && id <= x - 1)) {
      for (int j = -x; id + j >= 0; j -= x) {
        if (!Graph::connect(i, id, j)) {
          break;
        }
      }
    }
    break;
  }
}

// auxilia a funcao connectVertices(...):
bool Graph::connect(Vertex *i, int id, int j) {
  Vertex *v = getVertex(id + j);
  char vertexValue = v->getValue();
  //se tirarmos a funcao de adicionar desse if guardamos os pontos nas listas:
  if (vertexValue != '.') {
    i->addToAdjacency(v);
    return false;
  }
  return true;
}

bool Graph::isReachable() {
  std::vector<Vertex *> adj = getVertex(0)->getAdjacency();
  char value;
  Vertex *w;
  int size = adj.size();
  getVertex(0)->checkVertex();
  int j = 0;

  for (int i = 0; i < x * y; i++) {
    
    if (adj.size() > j)
      w = adj.at(j);
    else
      return false;
    value = w->getValue();
    if (getVertex(w->getId())->isChecked()) {
      return false;
    }

    j++;

    if (value != '.' && value != '*') {
      getVertex(w->getId())->checkVertex();
      adj = getVertex(w->getId())->getAdjacency();
      j = 0;
    } else if (value == '*') {
      return true;
    }
  }
  return false;
}

