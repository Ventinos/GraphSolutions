#include "Vertex.hpp"
#include <fstream>
#include <queue>
class Graph
{
public:
  std::vector<Vertex*> vertices;
  int size;

//Construtores:
  Graph();
  Graph(int size);

//Faz toda a leitura de entrada e cria o grafo:
static Graph *connect(std::vector<std::string> dictionary);
Vertex* exists(std::string str);
Vertex* addVertex(std::string str, int *id);
//soluçaõ do problema;
int solve(std::string start, std::string end);

//Imprime todo o grafo:
  void print();
  void resetMarks() ;
//Imprime a resposta
  void printResul();
};

