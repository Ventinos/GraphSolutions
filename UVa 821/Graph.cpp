#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <algorithm>

// Construtores:
Graph::Graph() {}

Graph::Graph(int size) { 
  this->size = size;
}

int Graph::inGraph(int id){
  int flag = -1;
  for(auto i : vertices){
    if(i->id == id){
      flag = i->pos;
      break;
    }
  }
  return flag;
}

Vertex* Graph::getVet(int id){
  for(auto i : vertices)
    {
      if(id == i->pos)
      {
        return i;
      }
    }
  return NULL;
}

// Faz toda a leitura de entrada e cria o grafo:
Graph * Graph::readGraph(int a, int b) {
  int temp1, temp2, n = 0, m = 0, counter = 2;
  Vertex *v1, *v2;
  Graph *g;
  g = new Graph();
  v1 = new Vertex(a, 0);
  v2 = new Vertex(b, 1);
  v1->addToAdjacency(v2);
  g->vertices.push_back(v1);
  g->vertices.push_back(v2);
  std::cin >> m;
  std::cin >> n;
  while(m != 0 && n != 0){
    temp1 = g->inGraph(m);
    if(temp1==-1){
      v1 = new Vertex(m, counter);
      g->vertices.push_back(v1);
      temp1 = counter;
      counter += 1;
    }
    else
      v1 = g->vertices.at(temp1);
    temp2 = g->inGraph(n);
    if(temp2==-1){
      v2 = new Vertex(n, counter);
      g->vertices.push_back(v2);
      temp2 = counter;
      counter += 1;
    }
    else
      v2 = g->vertices.at(temp2);
    g->vertices.at(temp1)->addToAdjacency(g->vertices.at(temp2));
    std::cin >> m;
    std::cin >> n;
  }
  g->size = g->vertices.size();
  return g;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->print();
    i->printAdjacency();
  }
}

float Graph::solve(){
  float sum = 0;
  for(auto i : vertices)
    {
      sum += bfs(i);
    }
  return (sum/(size*(size-1)));
}

int Graph::bfs(Vertex* v){
    bool visited[size];
    int distances[size];
    int sum = 0;
    for(int i = 0; i<size; i++){
      visited[i] = false;
      distances[i] = 0;
    }
  
    std::queue<int> q;
    int u;
    visited[v->pos] = true;
    q.push(v->pos);
    while (!q.empty())
    {
        u = q.front();
        Vertex* v1 = getVet(u);
        q.pop();
        for (auto i : v1->getAdjacency())
        {
            if (!visited[i->pos])
            {
              //distancia do filho é a do pai + 1
                distances[i->pos] = distances[u]+1;
                visited[i->pos] = true;
                q.push(i->pos);
            }
        }
    }

    for(int i = 0; i<size; i++)
      sum += distances[i];
  
    return sum;
}
