#include "Vertex.hpp"

class Graph
{
private:
  std::vector<Vertex*> vertices;
  int x;
  int y;
public:
//Construtores:
  Graph();
  Graph(int x, int y);
//Faz toda a leitura de entrada e cria o grafo:
  static Graph* readGraph(bool *start, bool *chest);
//Adiciona novo vertice na lista de vertices:
  void addVertex(Vertex* v);
//Dado um id retorna o vertice naquela posição:
  Vertex* getVertex(int id);
//GetVertices:
  std::vector<Vertex*> getVertices();
//Imprime todo o grafo:
  void print();
//Faz as conexoes no mapa:
//Conecta na proxima seta da direcao indicada, se houver:
  void connectVertices(Vertex* i, int x, int y, char value);
//Realiza a conexao da funcao 
//connectVertices(...):
  bool connect(Vertex* i, int id, int j);
//Percorre o caminho descrito no mapa:  
  bool isReachable();
};

