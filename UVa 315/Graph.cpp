#include "Graph.hpp"
#include <algorithm>
#include <stack>
#include <sstream>
#include <iostream>

// Construtores:
Graph::Graph() { this->size = 0; }

Graph::Graph(int size) { this->size = size; }

int Graph::getSize() { return size; }
void Graph::setSize(int size) { this->size = size; }

// Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex *v) { vertices.push_back(v); }

// Dado um id retorna o vertice naquela posição:
Vertex *Graph::getVertex(int id) {
  for (Vertex *i : vertices)
    if (i->getId() == id)
      return i;
  return NULL;
}

// Faz toda a leitura de entrada e cria o grafo:
Graph *Graph::readGraph(int j) {
  std::string input;
  std::vector<int> numbers;
  int entry1, entry2,m,n;
  Graph *g;
  Vertex *v1, *v2;
  g = new Graph();

  g->setSize(j);
  for(int i=0; i<j;i++){
    v1 = new Vertex(i);
    g->addVertex(v1);
  }

  while(1){
    std::getline(std::cin, input);
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    if(numbers[0]==0)
      break;
    v1 = g->getVertex(numbers[0]-1);
    for(int i=1;i<numbers.size();i++){
      v2 = g->getVertex(numbers[i]-1);
      v1->addToAdjacency(v2);
      v2->addToAdjacency(v1);
    }
    input.clear();
    numbers.clear();
  }
  // retorna o grafo com todos os vertices
  return g;
}

// Imprime todo o grafo:
void Graph::print() {
  for (auto i : vertices) {
    i->printAdjacency();
  }
}

void Graph::dfs(int u, int *dfs_numbercounter, std::vector<int> &dfs_num,
                std::vector<int> &dfs_low, std::vector<int> &dfs_parent,
                std::vector<int> &articulacao, int *dfsRoot,
                int *rootChildren) {
  *dfs_numbercounter = *dfs_numbercounter + 1;
  dfs_num.at(u) = *dfs_numbercounter;
  dfs_low.at(u) = dfs_num.at(u);
  for (auto v : getVertex(u)->getAdjacency()) {
    //std::cout << "flag " << u <<std::endl;
    if (dfs_num.at(v->getId()) == -1 /*unvisited*/) {
      dfs_parent.at(v->getId()) = u;

      if (u == *dfsRoot)
        *rootChildren = *rootChildren + 1;

      dfs(v->getId(), dfs_numbercounter, dfs_num, dfs_low, dfs_parent,
          articulacao, dfsRoot, rootChildren);

      if (dfs_low.at(v->getId()) >= dfs_num.at(u)){
        articulacao.at(u) = 1;
      }

      dfs_low.at(u) = std::min(dfs_low.at(u), dfs_low.at(v->getId()));
    } else if (v->getId() != dfs_parent.at(u)) {
      dfs_low.at(u) = std::min(dfs_low.at(u), dfs_low.at(v->getId()));
    }
  }
}

int Graph::contaCritico(){
  int n = getSize(),u = 0, dfs_numbercounter = -1, dfsRoot = 0, rootChildren = 0,accumulator = 0;
  std::vector<int> dfs_num, dfs_low, dfs_parent, articulacao;

  // preenchendo os vetores com seus valores iniciais:
  for (int i = 0; i < n; i++) {
    dfs_num.push_back(-1);
    dfs_low.push_back(0);
    dfs_parent.push_back(-1);
    articulacao.push_back(0);
  }
  
  for (int u = 0; u < n; u++) {
    if (dfs_num.at(u) == -1) {
      dfsRoot = u;
      rootChildren = 0;
      dfs(u, &dfs_numbercounter, dfs_num, dfs_low,dfs_parent, articulacao,&dfsRoot, &rootChildren);
      articulacao.at(u) = (rootChildren > 1);
    }
  }
  //total de vertices articulacao:
  for (auto i : articulacao) {
    accumulator += i;
  }
  return accumulator;
}