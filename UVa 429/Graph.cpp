#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <stack>

// Construtores:
Graph::Graph() { this->size = 0; }

Graph::Graph(int size) { this->size = size; }

int verify(std::string a, std::string b) {
  int count = 0;
  int i = 0;
  int size = a.size();
  if (b.size() != size)
    return -1;
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i])
      count++;
  }
  return count;
}

// conecta palavras que sao diferentes por uma letra de diferenca:
Graph *Graph::connect(std::vector<std::string> dictionary) {
  Graph *g = new Graph();
  int id = 0;
  Vertex *a, *b;

  for (int i = 0; i < dictionary.size(); i++) {
    b = new Vertex(id, dictionary[i]);
    id++;
    g->vertices.push_back(b);
  }

  for (int i = 0; i < dictionary.size(); i++) {
    a = g->exists(dictionary[i]);
    for (int j = 0; j < dictionary.size(); j++) {
      b = g->exists(dictionary[j]);
      if (verify(dictionary[i], dictionary[j]) == 1 && i != j)
        a->adj.push_back(b);
    }
  }

  return g;
}

Vertex *Graph::exists(std::string str) {
  for (auto w : vertices) {
    if (w->value == str)
      return w;
  }
  return NULL;
}

// Resolução do problema
int Graph::solve(std::string start, std::string end) {
  std::queue<Vertex *> queue;
  int counter[vertices.size()];

  Vertex *u = exists(start);
  Vertex *v = exists(end);
  Vertex *w = NULL;

  queue.push(u);
  u->marked = true;
  counter[u->id] = 0;

  while (!queue.empty()) {
    w = queue.front();
    queue.pop();

    for (auto i : w->adj) {
      if (!i->marked) {
        counter[i->id] = counter[w->id] + 1;
        i->marked = true;
        if (i->value == v->value)
          return counter[i->id];
        queue.push(i);
      }
    }
  }
  return 0;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->print();
    for (auto w : i->adj) {
      w->print();
    }
  }
}

void Graph::resetMarks() {
  for (auto w : vertices)
    w->marked = false;
}