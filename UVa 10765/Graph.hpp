#include "Vertex.hpp"
#include <iostream>
#include <fstream>
#include <stack>

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
	static Graph* readGraph(int n,int m);

	//Adiciona novo vertice na lista de vertices:
	void addVertex(Vertex* v);

	//Dado um id retorna o vertice naquela posição:
	Vertex* getVertex(int id);

	//Imprime todo o grafo:
	void print();
  void printVertices();

  //Calcula quantidade de componentes ao "retirar" um vertice
  void dfs_qtd(int u, int v);
};
