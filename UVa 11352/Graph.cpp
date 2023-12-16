#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>

// Construtores:
Graph::Graph() {}

Graph::Graph(int linha, int coluna) { 
  this->linha = linha;
  this->coluna = coluna;
}

// Faz toda a leitura de entrada e cria o grafo:
Graph * Graph::readGraph() {
  int n = 0, m = 0, counter = 0;
  std::string s;
  char c;
  int v1 = 0, v2 = 0, size = 0;
  Vertex *v;
  Graph *g;
  std::cin >> m;
  std::cin >> n;
  g = new Graph(m,n);
  for(int i = 0; i < m; i++){
    std::cin >> s;
    for(int j = 0; j < n; j++){
      c = s.at(j);
      v = new Vertex(counter, c);
      if(c == 'A') g->reinoA = counter;
      if(c == 'B') g->reinoB = counter;
      counter++;
      g->vertices.push_back(v);
    }
  }
  for(int i = 0; i < m*n; i++){
    //insert linha do elemento
    if((i+1)%n!=0) g->vertices.at(i)->addToAdjacency(g->vertices.at(i+1));
    if(i>0 && (i-1)/n == i/n) g->vertices.at(i)->addToAdjacency(g->vertices.at(i-1));
    //insert linha acima do elemento
    if(i-n>=0)
    {
      g->vertices.at(i)->addToAdjacency(g->vertices.at(i-n));
      if((i+1-n)%n!=0) g->vertices.at(i)->addToAdjacency(g->vertices.at(i+1-n));
    if((i-n)%n!=0 && ((i-1-n)/n == (i-n)/n)) g->vertices.at(i)->addToAdjacency(g->vertices.at(i-1-n));
    }
    //insert linha abaixo do elemento
    if(i+n<n*m)
    {
      g->vertices.at(i)->addToAdjacency(g->vertices.at(i+n));
      if((i+1+n)%n!=0) g->vertices.at(i)->addToAdjacency(g->vertices.at(i+1+n));
      if((i+n)%n!=0 && ((i-1+n)/n == (i+n)/n)) g->vertices.at(i)->addToAdjacency(g->vertices.at(i-1+n));
    }
  }
  return g;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->print();
    i->printAdjacency();
  }
}

//análise para determinar regiões perigosas

void Graph::markUnsafePlaces() {
  int col = Graph::coluna;
  int lin = Graph::linha;
  for (auto j : Graph::vertices) {
    if(j->value == 'Z'){
      j->setUnsafe();
      int i = j->id;
      if((i+2) < (col*lin) && ((i+2)/col == i/col)) {//direita, cima e baixo
        if(i+2+col<col*lin && ((i+2+col)/col== i/col + 1)){
          Graph::vertices.at(i+2+col)->setUnsafe();
        }
        if(i+2-col>=0 && i+2-col<col*lin && ((i+2-col)/col == i/col - 1)){
          Graph::vertices.at(i+2-col)->setUnsafe();
        }
      }
      if((i-2) >= 0 && (i-2) < (col*lin) && ((i-2)/col == i/col)){//esquerda, cima e baixo
        if(i-2+col>=0 && i-2+col<col*lin && ((i-2+col)/col == i/col) + 1){
          Graph::vertices.at(i-2+col)->setUnsafe();
        }
        if(i-2-col>=0 && i-2-col<col*lin && ((i-2-col)/col== i/col - 1 )){
          Graph::vertices.at(i-2-col)->setUnsafe();
        }
      }
      if((i+2*col) < (col*lin)){//abaixo, direita e esquerda
        if((i+1+2*col)<col*lin && (i+1+2*col)/col == (i+2*col)/col){
          Graph::vertices.at(i+1+2*col)->setUnsafe();
        }
        if(i-1+2*col<col*lin && (i-1+2*col)/col == (i+2*col)/col){
          Graph::vertices.at(i-1+2*col)->setUnsafe();
        }
      }
      if((i-2*col)>=0 && (i-2*col) < (col*lin)){//cima, direita e esquerda
        if((i+1-2*col)>=0 && (i+1-2*col)<col*lin && (i+1-2*col)/col == (i-2*col)/col){
          Graph::vertices.at(i+1-2*col)->setUnsafe();
        }
        if(i-1-2*col>=0 && i-1-2*col<col*lin && (i-1-2*col)/col == (i-2*col)/col){
          Graph::vertices.at(i-1-2*col)->setUnsafe();
        }
      }
    }
  }
}

void Graph::bfs(int e)
{
  int a,d;
  bool flag = true;
  std::queue<int> queue;
  queue.push(e);
  Graph::vertices.at(e)->setMark();
  while(!queue.empty())
    {
      a = queue.front();
      queue.pop();
      Vertex* v = Graph::vertices.at(a);
      d = v->dist;
      bool vmark = v->mark;
        for(auto i : v->getAdjacency())
          {
            if(!i->mark && i->safe)//só analisa/insere elementos que são seguros e ainda não visitados
            {
              i->setMark();
              i->dist = d+1;
              queue.push(i->id);
            }
          }
    }
}