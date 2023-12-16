#include "Graph.hpp"
#include <iostream>

int main() {
  Graph *g;
  // start marca se ha inicio valido
  // chest marca se ha bau
  bool start, chest;
  g = Graph::readGraph(&start, &chest);
  //g->print();
  if (g->isReachable() && chest && start)
    std::cout << "*"<<std::endl;
  else
    std::cout << "!"<<std::endl;
  // se houver caminho ate o bau, tiver bau e tiver inicio eh valido.
  return 0;
}