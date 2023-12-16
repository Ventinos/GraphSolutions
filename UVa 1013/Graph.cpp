#include "Graph.hpp"
#include "UFDS.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>

// Construtores:
Graph::Graph() { this->numVertices = 0; }

Graph::Graph(int size) { this->numVertices = size; }

// Faz toda a leitura de entrada e cria o grafo:
Graph *Graph::readGraph(int n) {
  Graph *g;
  Edges *edge;
  Vertex *v1 = NULL;
  Vertex *v2 = NULL;
  int entry1, entry2, entry3;
  int id = 0;
  int i;
  g = new Graph(n);
  for (i = 0; i < n; i++) {
    //pega o X, Y e o numero de habitantes
    std::cin >> entry1;
    std::cin >> entry2;
    std::cin >> entry3;
    v1 = new Vertex(entry1, entry2, id, entry3);
    id++;
    //verifica se o vertice já existe
    if (g->pertence(entry1, entry2)) {
      v1 = g->getByValue(entry1, entry2);
      v1->inhabitants += entry3;
      id--;
    } else {
      g->vertices.push_back(v1);
    }

    // conecta
    for (int j = id - 1; j >= 0; j--) {
      v2 = g->vertices[j];
      // calculando menor distancia entre dois pontos
      // pontos (v1x,v1y) e (v2x,v2y)
      double a = v2->x - v1->x;
      double b = v2->y - v1->y;
      a = a * a;
      b = b * b;
      edge = new Edges(v1, v2, sqrt(a + b));
      g->addEdge(edge);
    }
  }
  return g;
}

Vertex *Graph::getByValue(int x, int y) {
  for (Vertex *v : vertices)
    if (v->x == x && v->y == y)
      return v;
  return NULL;
}

bool Graph::pertence(int x, int y) {
  for (Vertex *v : vertices) {
    if (v->x == x && v->y == y) {
      return true;
    }
  }
  return false;
}

Graph *Graph::kruskal(double *res) {
  // ordenar as arestas do grafo por peso;
  std::stable_sort(arestas.begin(), arestas.end(),
                   [](Edges *e1, Edges *e2) // funcao lambda
                   { return e1->peso < e2->peso; });

  Graph *g = new Graph();
  // Criar grafo vazio;
  double soma = 0;
  int hab = 0, h1[50], h2[50];
  int i;
  //Criar lista com o tam de cada sub arvore e do numero de habitantes dela
  for (Vertex *it : vertices) {
    //hab é o total de habitantes
    hab += it->inhabitants;
    h2[it->id] = it->inhabitants;
    h1[it->id] = 1;
  }
  UFDS *ufds = new UFDS(numVertices);
  for (Edges *it : arestas) {
    // pega o id de cada vertice da aresta
    int u = it->a->id;
    int v = it->b->id;
    // pega a raiz dos vertices
    int uRep = ufds->findRoot(u);
    int vRep = ufds->findRoot(v);
    // atualiza a raiz e adicionar a aresta no grafo
    if (uRep != vRep) {
      //realizando calculo Peso*Habitantes
      if (uRep == ufds->findRoot(0)) {
        soma += h2[vRep] * it->peso;
      }
      if (vRep == ufds->findRoot(0)) {
        soma += h2[uRep] * it->peso;
      }
      //Junta as sub arvores e altera no H1 e H2 
      //o tamanhp da arvore atual e o numero de habitantes
      ufds->setRoot(u, v, h1, h2);
      g->addEdge(it);
    }
  }
  *res = soma / hab;
  return g;
}

// Adiciona novo vertice na lista de vertices:
// arrumar para pair:
void Graph::addEdge(Edges *e) { arestas.push_back(e); }

// Imprime todo o grafo:
// arrumar para pair:
void Graph::print() {
  for (Edges *i : arestas) {
    i->print();
  }
}
