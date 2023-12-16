#include "Graph.hpp"
#include <iostream>
#include <stack>
#include <queue>

//Construtores:
Graph::Graph(){
  this->size = 0;
  this->edges = 0;
}

Graph::Graph(int size){
  this->size = size;
}

Graph::Graph(int size, int edges){
  this->size = size;
  this->edges = edges;
}

//Getters:
int Graph::getSize() { return size; }
int Graph::getEdge() { return edges; }
//Dado um id retorna o vertice naquela posição:
Vertex* Graph::getVertex(int id)
{
  return vertices.at(id);
}

//Setters:
void Graph::setSize(int size) { this->size = size;}
void Graph::setEdge(int edges) { this->edges = edges;}

//Faz toda a leitura de entrada e cria o grafo:
Graph* Graph::readGraph(int n, std::ifstream* file){
  int vertex1 = 0, vertex2 = 0;
  Vertex *v;
  Graph *g;
  std::string city1, city2;
  g = new Graph();
  int size = 0;
  for(int i = 0; i < n; i++){
    *file >> city1;
    *file >> city2;
    //std::cin >> city1;
    //std::cin >> city2;
    if(!g->verifyCity(city1, &vertex1)){
      v = new Vertex(size, city1);
      g->addVertex(v);
      vertex1 = size;
      size++;
    }
    if(!g->verifyCity(city2, &vertex2)){
      v = new Vertex(size, city2);
      g->addVertex(v);
      vertex2 = size;
      size++;
    }
    g->getVertex(vertex1)->addToAdjacency(g->getVertex(vertex2));
  }
  g->setSize(size);
  return g;
}

//Adiciona novo vertice na lista de vertices:
void Graph::addVertex(Vertex* v)
{
  vertices.push_back(v);
}

//Imprime todo o grafo:
void Graph::print()
{
  for(auto i : vertices)
  {
    if(i->getSafe())
      std::cout << "Seguro: ";
    else
      std::cout << "Preso: ";
    i->printAdjacency();
    
  }
}

//Verifica se a string (cidade) pertence à algum vertice do grafo
bool Graph::verifyCity(std::string city, int *vertex){
  for(auto i : vertices){
    if(i->getCity().compare(city) == 0){
     *vertex = i->getId();
     return true; 
    }
  }
  return false;
}

//Operações que verificam se o vertice do grafo é seguro (vertice está em ciclo) ou não
void Graph::verificaSafe(){
  bool vis[size];
  bool visAtual[size];
  for(int i = 0; i<size;i++){
    vis[i] = false;
    visAtual[i] = false;
  }
  for(int i = 0; i<size;i++){
    if(!vis[i])
      buscaLoop(i,visAtual, vis);
  }
}

void Graph::buscaLoop(int id,bool vetAt[], bool vet[]){
  vetAt[id] = true;
  for(auto i : vertices[id]->getAdjacency()){
    if(i->getAdjacency().size()==0){
    i->setSafe(false);
    //std::cout << "fim: " << i->getId() << std::endl;
    }
    else if(vetAt[i->getId()]){
    i->setSafe(true);
    //std::cout << "bateu: " << i->getId() << std::endl;
    }
    else{
      buscaLoop(i->getId(),vetAt, vet);
      //std::cout << "flag: " << i->getId() << std::endl;
      i->setSafe(i->verificaViz());
    }
  }
  vertices[id]->setSafe(vertices[id]->verificaViz());
  vet[id]=true;
  vetAt[id] = false;
}
