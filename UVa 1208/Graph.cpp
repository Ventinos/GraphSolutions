#include "Graph.hpp"
#include <iostream>
#include <stack>
#include <algorithm>

// Construtores:
Graph::Graph() { this->size = 0; }

Graph::Graph(int size) { this->size = size; }

// Faz toda a leitura de entrada e cria o grafo:
Graph * Graph::readGraph(int n) {
  int size = 0;
  std::string input;
  Vertex *v;
  Graph *g;
  g = new Graph(n);
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
      std::cin >> input;
      size = stoi(input);
      if(size != 0){
        if(i > j){
        v = new Vertex(j,i,size);
        g->vertices.push_back(v);
        }
      }
    }
  }
  //Ordena os vertices
  std::sort(g->vertices.begin(), g->vertices.end(),
            [](Vertex *e1, Vertex *e2)
            { return e1->aresta.second < e2->aresta.second; });
  std::stable_sort(g->vertices.begin(), g->vertices.end(),
            [](Vertex *e1, Vertex *e2)
            { return e1->aresta.first < e2->aresta.first; });
  std::stable_sort(g->vertices.begin(), g->vertices.end(),
            [](Vertex *e1, Vertex *e2)
            { return e1->size < e2->size; });
  return g;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->print();
  }
}

void Graph::printResul() {
  for (auto i : vertices) {
    char R1, R2;
      R1 = i->aresta.first + 65;
      R2 = i->aresta.second + 65;
    std::cout << R1 << "-" << R2 << " " << i->size <<std::endl;
  }
}

// Resolução do problema
Graph * Graph::solve() {
  int vet[size];
  Graph *g;
  g = new Graph(size);
  //inicionalizamos o vetor de "pais" com -1
  //-1 indica que o vértice não foi inserido no grafo
  for(int i = 0 ;i<size;i++)
    vet[i]=-1;
  for(auto i : vertices){
    if((vet[i->aresta.first]==-1)&&(vet[i->aresta.second]==-1)){
      vet[i->aresta.first]=i->aresta.first;
      vet[i->aresta.second]=i->aresta.first;
      g->vertices.push_back(i);
    }
    else if(vet[i->aresta.first]==vet[i->aresta.second]){}
    else if(vet[i->aresta.first]==-1){
      vet[i->aresta.first]=vet[i->aresta.second];
      g->vertices.push_back(i);
    }
    else if(vet[i->aresta.second]==-1){
      vet[i->aresta.second]=vet[i->aresta.first];
      g->vertices.push_back(i);
    }
    else{
      int a,b;
      if(vet[i->aresta.second]<vet[i->aresta.first]){
        a=vet[i->aresta.first];
        b=vet[i->aresta.second];
      }
      else{
        a=vet[i->aresta.second];
        b=vet[i->aresta.first];
      }
      for(int j = 0;j<size;j++)
        if(vet[j]==a)
          vet[j]=b;
      g->vertices.push_back(i);
    }
  }
  return g;
}