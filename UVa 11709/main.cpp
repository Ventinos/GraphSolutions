#include "Graph.hpp"
#include <iostream>
#include <queue>

int main() {
  int n, m;
  std::string lixo;
  
  Graph *g = new Graph();
  Graph *inv;

  std::queue<int> queue;

  while (true) {
    std::cin >> n;
    std::cin >> m;
    std::getline(std::cin, lixo);

    inv = new Graph();
    
    g = Graph::readGraph(n, m, inv);

    if (g == NULL)
      break;
    
    queue.push(Graph::solve(g, inv));
  }
  
  while (!queue.empty()) {
    std::cout << queue.front() << std::endl;
    queue.pop();
  }
  
  return 0;
}
