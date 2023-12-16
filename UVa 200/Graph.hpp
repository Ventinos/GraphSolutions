#include "Vertex.hpp"
#include <string>
#include <iostream>
#include <stack>
#include <queue>
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
	static Graph* readGraph(std::ifstream* file);
	//Adiciona novo vertice na lista de vertices:
	void addVertex(Vertex* v);
	//Dado um id retorna o vertice naquela posição:
	Vertex* getVertex(int id);
  Vertex* getVertexValue(char valor);
	//Imprime todo o grafo:
	void print();
  void printVertices();
  //procura no grafo se um vértice com o valor capturado já existe, e se existe, guarda a posição dele no array de vertices do grafo em vertex
  bool verifyChar(char Char, int *vertex);
  //busca em largura, que define o output, guardando-o numa pilha
	void dfs(int pos, bool *marcado, std::stack <Vertex*> *s);
  //ordenação topológica, retorna a pilha feita no dfs para ser escrita na main
  std::stack <Vertex*> ordenaVertices();

};