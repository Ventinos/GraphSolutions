#include <vector>

class Vertex
{
private:
	int id;
	char value;
	std::vector<Vertex*> adjacency;
public:
	//Construtores:
	Vertex();
	Vertex(char value);
  Vertex(int id,char value);
	//Getters:
  int getId();
	char getValue();
	std::vector<Vertex*> getAdjacency();
  //retorna o primeiro adjacente não colorido do vertice
  Vertex* getAdjacencyNotColored();
	//Setters:
	void setId(int id);
	void setValue(char value);
	//Adiciona o vertice v na lista de adjacencia
	void addToAdjacency(Vertex *v); 
	//Printa as informacoes de id e valor do vertice atual
	void print();
	//Printa a lista de adjacencia do vertice atual
	void printAdjacency();
};