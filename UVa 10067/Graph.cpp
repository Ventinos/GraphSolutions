#include "Graph.hpp"
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

// Construtores:
Graph::Graph() {}

// Faz toda a leitura de entrada e cria o grafo:
Graph *Graph::readGraph() {
  Graph *g;
  g = new Graph();
  
  //cria 10k de vertices e bota no grafo:
  for (int i = 0; i < 10000; i++) {
    g->vertices.push_back(new Vertex(i));
  }

  //faz as insercoes devidas nas listas de adj de cada vertice:
  for (int i = 0; i < 10000; i++)
    g->insereAdj(i);

  //retorna o grafo pronto:
  return g;
}

void Graph::insereAdj(int i) {
  short int d[4], dUp[4], dDown[4], temp1, temp2;
  int valor = i, mult = 1;
  int numUp = 0, numDown = 0;

  // separando digitos:
  for (int j = 0; j < 4; j++) {
    // separando os digitos
    d[j] = valor % 10;
    valor /= 10;
  }

  // copiando de d para dUp e dDown
  for (int k = 0; k < 4; k++) {
    dUp[k] = d[k];
    dDown[k] = d[k];
  }

  for (int j = 0; j < 4; j++) {
    // caso pra cima
    temp1 = dUp[j];
    dUp[j]++;
    dUp[j] %= 10;

    // caso pra baixo
    temp2 = dDown[j];
    dDown[j] += 9;
    dDown[j] %= 10;

    // concatenando os digitos de up e down:
    for (int j = 0; j < 4; j++) {
      numUp += dUp[j] * mult;
      numDown += dDown[j] * mult;
      mult *= 10;
    }

    // adicionando na lista de adj de i o numUp e numDown:
    this->vertices.at(i)->addToAdjacency(this->vertices.at(numUp));
    this->vertices.at(i)->addToAdjacency(this->vertices.at(numDown));

    // resetando variaveis:
    dUp[j] = temp1;
    dDown[j] = temp2;
    numUp = 0;
    numDown = 0;
    mult = 1;
  }
}

void Graph::print() {
  for (auto i : vertices) {
    std::cout << i->id << "\n";
    i->printAdjacency();
  }
}

//bfs usado para medir os cliques:
void Graph::bfs(int S) {
  int a, d;
  std::queue<int> queue;
  //bota na fila
  queue.push(S);
  //marca
  Graph::vertices.at(S)->mark = true;
  Graph::vertices.at(S)->dist = 0;
  //enquanto a fila n estiver vazia:
  while (!queue.empty()) {
    //pega o primeiro elemento da fila:
    a = queue.front();
    queue.pop();
    //pega o vertice desse id:
    Vertex *v = Graph::vertices.at(a);
    //pega a distancia ate ele:
    d = v->dist;
    //para cada vertice adjacente:
    for (auto i : v->getAdjacency()) {
      //se n estiver marcado:
      if (!i->mark) {
        //marca:
        i->mark = true;
        //faz a distancia ate ele d+1:
        i->dist = d + 1;
        //bota na fila:
        queue.push(i->id);
      }
    }
  }
}

//reseta as marcas e as distancias:
void Graph::resetMarks() {
  for (auto v : vertices){
    v->mark = false;
    v->dist = -1;
  }  
}