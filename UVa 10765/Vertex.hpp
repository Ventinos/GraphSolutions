#include <vector>

class Vertex
{
private:
	int id;
	std::vector<Vertex*> adjacency;
  bool mark;
public:
	//Construtores:
	Vertex();
	Vertex(int id);
	
  //Getters:
  int getId();
	bool getMark();
	std::vector<Vertex*> getAdjacency();
  
  //retorna o primeiro adjacente não colorido do vertice
  Vertex* getAdjacencyNotColored();
	
  //Setters:
	void setId(int id);
  void setMark(bool mark);
  void setSafe(bool safe);
	
  //Adiciona o vertice v na lista de adjacencia
	void addToAdjacency(Vertex *v); 
	
  //Printa as informacoes de id e valor do vertice atual
	void print();
	
  //Printa a lista de adjacencia do vertice atual
	void printAdjacency();
};
