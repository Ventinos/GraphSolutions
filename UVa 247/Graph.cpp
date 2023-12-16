#include "Graph.hpp"
#include <iostream>
#include <stack>

// Construtores:
Graph::Graph() {
  this->size = 0;
  this->edges = 0;
}

Graph::Graph(int size) { this->size = size; }

Graph::Graph(int size, int edges) {
  this->size = size;
  this->edges = edges;
}

// Getters:
int Graph::getSize() { return size; }
int Graph::getEdge() { return edges; }
// Dado um id retorna o vertice naquela posição:
Vertex *Graph::getVertex(int id) { return vertices.at(id); }

// Setters:
void Graph::setSize(int size) { this->size = size; }
void Graph::setEdge(int edges) { this->edges = edges; }

// Faz toda a leitura de entrada e cria o grafo:
std::pair<Graph *, Graph *> Graph::readGraph(int n) {
  int vertex1 = 0, vertex2 = 0;
  Vertex *v, *v2;
  Graph *g1, *g2;
  std::string name1, name2;
  // g1 é o grafo e g2 é o trasposto de g1
  g1 = new Graph();
  g2 = new Graph();
  int size = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> name1;
    std::cin >> name2;
    if (!g1->verifyName(name1, &vertex1)) {
      v = new Vertex(size, name1);
      v2 = new Vertex(size, name1);
      g1->addVertex(v);
      g2->addVertex(v2);
      vertex1 = size;
      size++;
    }
    if (!g1->verifyName(name2, &vertex2)) {
      v = new Vertex(size, name2);
      v2 = new Vertex(size, name2);
      g1->addVertex(v);
      g2->addVertex(v2);
      vertex2 = size;
      size++;
    }
    g1->getVertex(vertex1)->addToAdjacency(g1->getVertex(vertex2));
    g2->getVertex(vertex2)->addToAdjacency(g2->getVertex(vertex1));
  }
  g1->setSize(size);
  g2->setSize(size);
  return std::make_pair(g1, g2);
}

//descobre quais componentes são fortemente conectados
std::queue<std::string> Graph::verificaCirculo(Graph *g1, Graph *g2) {
  int cnt = 0, size = g1->getSize();
  std::string s;
  std::queue<std::string> v;
  bool vis[size], vis2[size];
  for (int i = 0; i < size; i++) {
    vis[i] = false;
    vis2[i] = false;
  }
  for (int i = 0; i < size; i++) {
    if (g1->getVertex(i)->getCirculo() == 0) {
      cnt++;
      v.push(s);
      s = "";
      g1->dfs(i, vis);
      g2->dfs(i, vis2);
      for (int j = 0; j < size; j++) {
        if (vis[j] && vis2[j])
          if (g1->getVertex(j)->getCirculo() == 0) {
            if (s == "")
              s = s + g1->getVertex(j)->getName();
            else
              s = s + ", " + g1->getVertex(j)->getName();
            g1->getVertex(j)->setCirculo(cnt);
          }
      }
    }
    for (int k = 0; k < size; k++) {
      vis[k] = false;
      vis2[k] = false;
    }
  }
  v.push(s);
  return v;
}

void Graph::dfs(int n, bool vis[]) {
  vis[n] = true;
  for (auto i : getVertex(n)->getAdjacency()) {
    if (!vis[i->getId()])
      dfs(i->getId(), vis);
  }
}

// Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex *v) { vertices.push_back(v); }

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    std::cout << i->getCirculo() << std::endl;
    i->printAdjacency();
  }
}

// Verifica se a string (pessoa) pertence à algum vertice do grafo
bool Graph::verifyName(std::string city, int *vertex) {
  for (auto i : vertices) {
    if (i->getName().compare(city) == 0) {
      *vertex = i->getId();
      return true;
    }
  }
  return false;
}
