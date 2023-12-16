#include "Graph.hpp"
#include <iostream>
#include <queue>

int main() {
  int m, n;
  Graph *g;
  std::vector<Graph> grafos;

  std::cin >> n;
  std::cin >> m;

  while (n != 0 || m != 0) {
    g = g->Graph::readGraph(m, n);
    grafos.push_back(*g);
    std::cout << std::endl;

    std::cin >> n >> m;
  }
  for (int j = 0; j < grafos.size(); j++) {
    grafos[j].solve();
  }
}