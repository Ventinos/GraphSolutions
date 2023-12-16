#include <iostream>
#include "Graph.hpp"

int main() {
  std::ifstream file("input.txt");
  while(!file.eof()){
    Graph *g = Graph::readGraph(&file);
  std::stack <Vertex*> ordem;
  ordem = g->ordenaVertices();

  while(!ordem.empty())
    {
      std::cout << ordem.top()->getValue();
      ordem.pop();
    }
    std::cout << std::endl;
  }
  return 0;
}