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
	static Graph* readGraph();
	//Adiciona novo vertice na lista de vertices:
	void addVertex(Vertex* v);
	//Dado um id retorna o vertice naquela posição:
	Vertex* getVertex(int id);
	//Imprime todo o grafo:
	void print();
  void printVertices();
	
void dfsBridges(int u, int *dfs_numbercounter, std::vector<int>& dfs_num,std::vector<int>& dfs_low, std::vector<int>& dfs_parent,int *dfsRoot, int *rootChildren, std::vector<std::pair<int,int>> *pontes);
  
int dfs(int e, std::vector<std::pair<int,int>> pontes);
};
//,std::vector<int>& articulacao