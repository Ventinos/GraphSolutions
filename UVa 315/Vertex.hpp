#include <vector>

class Vertex
{
private:
	int id;
  bool marked;
	std::vector<Vertex*> adjacency;
public:
	//Construtores:
	Vertex();
	Vertex(int id);
  //Getters:
  int getId();
  bool isMarked();
	std::vector<Vertex*> getAdjacency();
  //retorna o primeiro adjacente não colorido do vertice
  Vertex* getAdjacencyNotColored();
  //Setters:
	void setId(int id);
  void mark();
  void unmark();
  //Adiciona o vertice v na lista de adjacencia
	void addToAdjacency(Vertex *v); 
  //Printa as informacoes de id e valor do vertice atual
	void print();
  //Printa a lista de adjacencia do vertice atual
	void printAdjacency();};