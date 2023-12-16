#include "Graph.hpp"
#include <bits/stdc++.h>
#include <iostream>

//Construtores:
Graph::Graph(){
  this->size = 0;
  this->edges = 0;
}

Graph::Graph(int size, int edges){
  this->size = size;
  this->edges = edges;
}

//Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex* v)
{
  vertices.push_back(v);
}

void Graph::setEdges(int edges)
{
  this->edges = edges;
}

//Dado um id retorna o vertice naquela posição:
Vertex* Graph::getVertex(int id)
{
  return vertices.at(id);
}

//Faz toda a leitura de entrada e cria o grafo:
Graph* Graph::readGraph(int j, int k)
{
  int n = 0, r=0, cnt = 0 , m = 0;
  char value;
  Vertex *v;
  Graph *g;

  n = j*k;
  
  g = new Graph(n,m);
  
  for (int i = 0; i < n; i++) {
    std::cin >> value;
    if(value=='*'){
      v = new Vertex(i,0);
      g->addVertex(v);
    }
    else if(value=='@'){
      v = new Vertex(i,1);
      g->addVertex(v);
    }
  }
  for (int i = 0; i < j; i++)
  {
    for (int f = 0; f < k; f++){
      r = (i*k)+f;
    if(f!=0){
      g->getVertex(r)->addToAdjacency(g->getVertex(r-1));
      cnt++;
    }
    if(f!=k-1){
      g->getVertex(r)->addToAdjacency(g->getVertex(r+1));
      cnt++;
    }
    if(i!=0){
      g->getVertex(r)->addToAdjacency(g->getVertex(r-k));
      cnt++;
    }
    if(i!=(j-1)){
      g->getVertex(r)->addToAdjacency(g->getVertex(r+k));
      cnt++;
    }
    if((f!=0)&&(i!=0)){
      g->getVertex(r)->addToAdjacency(g->getVertex(r-1-k));
      cnt++;
    }
    if((f!=0)&&(i!=j-1)){
      g->getVertex(r)->addToAdjacency(g->getVertex(r-1+k));
      cnt++;
    }
    if((f!=k-1)&&(i!=j-1)){
      //std::cout << "flag G" << std::endl;
      g->getVertex(r)->addToAdjacency(g->getVertex(r+1+k));
      cnt++;
    }
    if((f!=k-1)&&(i!=0)){
      //std::cout << "flag H" << std::endl;
      g->getVertex(r)->addToAdjacency(g->getVertex(r+1-k));
      cnt++;
    }
    }
  }
  g->setEdges(cnt);
  return g;
}

int Graph::busca(){
  int cnt = 0;
  bool vis[size];
  for(int i=0; i<size;i++){
    vis[i] = false;
  }

  for(int i=0;i<size;i++){
    if(vertices[i]->getValue()!=0){
      if(!vis[i]){
        cnt++;}
      vis[i]=true;
      contaAdj(i, vis);
    }
  }
  return cnt;
}

void Graph::contaAdj(int id, bool vet[]){
  for(auto i : vertices[id]->getAdjacency()){
    if((i->getValue()!=0)&&(!vet[i->getId()])){
      vet[i->getId()]=true;
      contaAdj(i->getId(),vet);}
  }
}

//Imprime todo o grafo:
void Graph::print()
{
  for(auto i : vertices)
  {
      i->printAdjacency();
  }
}