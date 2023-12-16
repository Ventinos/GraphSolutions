#include "Graph.hpp"
#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>

// Construtores:
Graph::Graph() { this->size = 0; }

Graph::Graph(int size) { this->size = size; }

// Faz toda a leitura de entrada e cria o grafo:
Graph * Graph::readGraph() {
  int vertex = -1;
  int n = 0, m = 0;
  int v1 = 0, v2 = 0, size = 0;
  Vertex *v;
  Graph *g;
  std::cin >> n;
  std::cin >> m;
  g = new Graph(n);
  for(int i = 0; i < m; i++){
    std::cin >> v1;
    std::cin >> v2;
    std::cin >> size;
    v = new Vertex(v1-1,v2-1,size);
    g->vertices.push_back(v);
  }
  //Ordena os vertices
  std::sort(g->vertices.begin(), g->vertices.end(),
            [](Vertex *e1, Vertex *e2)
            { return e1->aresta.second > e2->aresta.second; });
  std::stable_sort(g->vertices.begin(), g->vertices.end(),
            [](Vertex *e1, Vertex *e2)
            { return e1->aresta.first > e2->aresta.first; });
  std::stable_sort(g->vertices.begin(), g->vertices.end(),
            [](Vertex *e1, Vertex *e2)
            { return e1->size > e2->size; });
  return g;
}

// Resolução do problema
int Graph::solve() {
  int vet[size];
  int cnt = 0;
  //inicionalizamos o vetor de "pais" com -1
  //-1 indica que o vértice não foi inserido no grafo
  for(int j = 0 ;j<size;j++){
    vet[j]=-1;
  }
  for(auto i : vertices){
    if((vet[i->aresta.first]==-1)&&(vet[i->aresta.second]==-1)){
      vet[i->aresta.first]=i->aresta.first;
      vet[i->aresta.second]=i->aresta.first;
    }
    else if(vet[i->aresta.first]==vet[i->aresta.second]){
      cnt = cnt + i->size;
    }
    else if(vet[i->aresta.first]==-1){
      vet[i->aresta.first]=vet[i->aresta.second];
    }
    else if(vet[i->aresta.second]==-1){
      vet[i->aresta.second]=vet[i->aresta.first];
    }
    else{
      int a,b;
        a=vet[i->aresta.first];
        b=vet[i->aresta.second];
      for(int j = 0;j<size;j++)
        if(vet[j]==a)
          vet[j]=b;
    }
  }
  return cnt;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->print();
  }
}