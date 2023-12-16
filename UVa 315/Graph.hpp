#include "Vertex.hpp"
#include <iostream>
#include <fstream>

class Graph
{
private:
	std::vector<Vertex*> vertices;
	int size;
public:
	//Construtores:
	Graph();
	Graph(int size);
	//Getters e Setters
	int getSize();
  void setSize(int size);
	//Faz toda a leitura de entrada e cria o grafo:
	static Graph* readGraph(int j);
	//Adiciona novo vertice na lista de vertices:
	void addVertex(Vertex* v);
	//Dado um id retorna o vertice naquela posição:
	Vertex* getVertex(int id);
	//Imprime todo o grafo:
	void print();
  void printVertices();
	void dfs(int u, int *dfs_numbercounter, std::vector<int>& dfs_num,std::vector<int>& dfs_low,std::vector<int>& dfs_parent,std::vector<int>& articulacao,int *dfsRoot, int *rootChildren);
  int contaCritico();
};